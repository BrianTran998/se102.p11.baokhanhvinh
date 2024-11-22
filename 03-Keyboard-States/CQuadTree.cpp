#include "CQuadTree.h"
#include "debug.h"

void CSceneNode::subdivide()
{
    if (width <= 160 || height <= 160) return; // No need to subdivide if the node is small enough

    // Create 4 child nodes with half the size of the parent node
    children[0] = new CSceneNode(id * 8 + 1, x, y, width / 2, height / 2);
    children[1] = new CSceneNode(id * 8 + 2, x + width / 2, y, width / 2, height / 2);
    children[2] = new CSceneNode(id * 8 + 3, x, y - height / 2, width / 2, height / 2);
    children[3] = new CSceneNode(id * 8 + 4, x + width / 2, y - height / 2, width / 2, height / 2);

    // Move objects from parent to children based on their location
    for (auto& obj : objects) {
        for (int i = 0; i < 4; ++i) {
            if (children[i]->isObjectWithinNode(obj)) {
                children[i]->addObject(obj);
            }
        }
    }

    // Clear the parent objects after subdividing
    objects.clear();

    // Recursively subdivide children if needed
    for (int i = 0; i < 4; ++i) {
        if (children[i]->hasObjects()) {
            children[i]->subdivide();
        }
    }
}

void CSceneNode::addObject(CGameObject* obj)
{
    objects.push_back(obj);
}

bool CSceneNode::isTouchingCamera(CCamera* camera)
{
    //Case scene node is in camera
    if (camera->isObjectInCamera(this->x, this->y, this->width, this->height))
    {
        return true;
    }
    //Case camera is in scene node
    if (camera->isInSceneNode(this->x, this->y, this->width, this->height))
    {
        return true;
    }

    return false;
}

void CSceneNode::getObjects(std::vector<CGameObject*>& objectList)
{
    for (const auto& obj : objects) {
        if (!isObjectInList(obj, objectList)) {
            objectList.push_back(obj); // Add to list if not already present
        }
    }
    objects.clear(); //Clear after gotten all objects in this nodes
}

bool CSceneNode::isObjectInList(CGameObject* obj, std::vector<CGameObject*>& objectList)
{
    for (const auto& existingObj : objectList) {
        if (existingObj == obj) {  // Direct pointer comparison
            return true;  // Object is already in the list
        }
    }
    return false;  // Object not found in the list
}

bool CSceneNode::isObjectWithinNode(CGameObject* obj)
{
    if (obj->isInSceneNode(this->x, this->y, this->width, this->height))
    {
        return true;
    }
    else return false;
}

CQuadTree::CQuadTree(float width, float height, std::vector<CGameObject*>& objects)
{
    if (height >= width) {
        width = height;
    }
    else height = width;
    root = new CSceneNode(0, 0, height, width, height);
    for (const auto& obj : objects) {
        root->addObject(obj);
    }
    root->subdivide();  // Start subdividing nodes
}

std::vector<CGameObject*> CQuadTree::getObjectsInView(CCamera* camera)
{
    std::vector<CGameObject*> visibleObjects;
    std::vector<CSceneNode*> nodesToCheck = { root };
    // Traverse the nodes and find the ones that touch the camera view
    
    for (size_t i = 0; i < nodesToCheck.size(); ++i) {
        CSceneNode* node = nodesToCheck[i];

        if (node->isTouchingCamera(camera)) {
            node->getObjects(visibleObjects);

            // Add children of the current node to the list if they exist
            for (int j = 0; j < 4; ++j) {
                if (node->children[j]) {
                    nodesToCheck.push_back(node->children[j]);
                }
            }
        }
    }
    
    return visibleObjects;
}
