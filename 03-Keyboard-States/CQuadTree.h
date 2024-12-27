#pragma once
#include <vector>
#include "GameObject.h"
#include "CCamera.h"
class CSceneNode
{
public:
    float x, y, width, height;
    int id;
    std::vector<CGameObject*> objects;  // Store pointers to objects
    CSceneNode* children[4] = { nullptr, nullptr, nullptr, nullptr }; // 4 children for 4 quadrants

    CSceneNode(int id, float x, float y, float width, float height)
        : id(id), x(x), y(y), width(width), height(height) {}

    bool hasObjects() {
        return !objects.empty();
    }

    void subdivide();
    void addObject(CGameObject* obj);
    bool isTouchingCamera(CCamera* camera);
    void getObjects(std::vector<CGameObject*>& objectList);
    bool isObjectInList(CGameObject* obj, std::vector<CGameObject*>& objectList);

    // Function to check if an object is within the bounds of the current screen node
    bool isObjectWithinNode(CGameObject* obj);
};

class CQuadTree
{
public:
    CSceneNode* root;
    CQuadTree(float width, float height, std::vector<CGameObject*>& objects);

    std::vector<CGameObject*> getObjectsInView(CCamera* camera);
};

