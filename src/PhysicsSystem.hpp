#pragma once

// #include <raylib.h>

#include "PoolManager.hpp"
#include "RectanglePhysicsObject.hpp"

const size_t PHYSICS_RESERVE_SIZE = 100;

class PhysicsSystem {
   private:
    static PhysicsSystem* instance;
    PoolManager<RectanglePhysicsObject> rectanglePhysicsObjects;
    // Vector<CirclePhysicsObject> circlePhysicsObjects;

    // singleton, we self instantiate, constructor must be private
    PhysicsSystem() : rectanglePhysicsObjects(PHYSICS_RESERVE_SIZE){};

   public:
    static PhysicsSystem& GetInstance() {
        if (instance == nullptr) {
            instance = new PhysicsSystem();
        }
        return *instance;
    };

    void Update();

    PoolObjectId CreateRectangle() {
        auto r = RectanglePhysicsObject();
        PoolObjectId id = rectanglePhysicsObjects.Add(r);
        r.id = id;
        return id;
    };

    void RemoveRectangle(PoolObjectId id) {
        rectanglePhysicsObjects.Remove(id);
    }
};
