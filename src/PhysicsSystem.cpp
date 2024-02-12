#include "PhysicsSystem.hpp"

#include <cstdlib>

#include "RectanglePhysicsObject.hpp"

bool AABBIntersectionCheck(RectanglePhysicsObject a, RectanglePhysicsObject b) {
    auto aPos = a.GetPos();
    auto bPos = b.GetPos();

    auto doThey = (abs((aPos.x + a.GetWidth() / 2) - (bPos.x + b.GetWidth() / 2)) * 2 <
                   (a.GetWidth() + b.GetWidth())) &&
                  (abs((aPos.y + a.GetHeight() / 2) - (bPos.y + b.GetHeight() / 2)) * 2 <
                   (a.GetHeight() + b.GetHeight()));
    return doThey;
}

PhysicsSystem* PhysicsSystem::instance = nullptr;

void PhysicsSystem::Update() {
    // AABB intersection detection for all RectanglePhysicsObjects
    PoolManager<RectanglePhysicsObject>& objs = rectanglePhysicsObjects;

    for (auto it = objs.begin(); it != objs.end(); it++) {
        it->object.OverlappingObjects.clear();
    }

    for (auto it = objs.begin(); it != objs.end(); it++) {
        if (!it->active) {
            continue;
        }
        for (auto it_other = it + 1; it_other != objs.end(); it_other++) {
            if (!it->active) {
                continue;
            }
            // queue up intersections in RectanglePhysicsObject
            // wack
            if (AABBIntersectionCheck(it->object, it_other->object)) {
                it->object.OverlappingObjects.push_back(it_other->object.id);
                it_other->object.OverlappingObjects.push_back(it->object.id);
            }
        }
    }
}
