#pragma once

#include "PhysicsObjectTag.hpp"
#include "PoolManager.hpp"
#include "RectanglePhysicsObject.hpp"
#include "TransformComponent.hpp"

const size_t PHYSICS_RESERVE_SIZE = 100;

class PhysicsSystem {
   private:
    static PhysicsSystem* instance;
    PoolManager<RectanglePhysicsObject> rectanglePhysicsObjects;
    // Vector<CirclePhysicsObject> circlePhysicsObjects;

    // singleton, we self instantiate, constructor must be private
    PhysicsSystem() : rectanglePhysicsObjects(PHYSICS_RESERVE_SIZE){};

   public:
    PhysicsSystem(const PhysicsSystem&) = delete;
    PhysicsSystem(PhysicsSystem&&) = delete;
    PhysicsSystem& operator=(const PhysicsSystem&) = delete;
    PhysicsSystem& operator=(PhysicsSystem&&) = delete;

    static PhysicsSystem& GetInstance() {
        if (instance == nullptr) {
            instance = new PhysicsSystem();
        }
        return *instance;
    };

    void Update();

    PoolObjectId CreateRectangle(TransformComponent transform, int width, int height, PhysicsObjectTag tag) {
        auto r = RectanglePhysicsObject(transform, width, height, tag);
        PoolObjectId id = rectanglePhysicsObjects.Add(r);
        r.id = id;
        return id;
    };

    // Do not store this reference! (It is a ref to a vector element)
    //
    // Also creating more rectangles could invalidate this reference
    RectanglePhysicsObject& GetRectangle(PoolObjectId id) {
        return rectanglePhysicsObjects.GetInfallible(id);
    }
    bool SetRectangle(PoolObjectId id, RectanglePhysicsObject rect) {
        return rectanglePhysicsObjects.Set(id, rect);
    }

    void RemoveRectangle(PoolObjectId id) { rectanglePhysicsObjects.Remove(id); }
};
