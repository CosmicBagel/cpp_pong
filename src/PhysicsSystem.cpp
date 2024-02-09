#include "PhysicsSystem.hpp"

#include "Crash.hpp"
#include "RectanglePhysicsObject.hpp"

bool AABBCollisionCheck(RectanglePhysicsObject a, RectanglePhysicsObject b) {
    return false;
}

PhysicsSystem* PhysicsSystem::instance = nullptr;

void PhysicsSystem::Update() {
    Crash::not_implemented();
    // AABB collision detection for all RectanglePhysicsObjects
    // auto objs = rectanglePhysicsObjects;
    // for (auto it = objs.begin(); it != objs.end(); it++) {
    // for (auto it_other = it + 1; it_other != objs.end(); it_other++) {
    // queue up collisions in RectanglePhysicsObject
    // }
    // }
}
