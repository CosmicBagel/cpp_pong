#pragma once

#include <functional>

#include "PhysicsSystem.hpp"
#include "PoolManager.hpp"
#include "TransformComponent.hpp"

class RectangleColliderComponent {
   public:
    PhysicsSystem &physicsSystem;
    const PoolObjectId id;

    RectangleColliderComponent(TransformComponent initalTransform, int width, int height)
        : physicsSystem(PhysicsSystem::GetInstance()),
          id(physicsSystem.CreateRectangle(initalTransform, width, height)) {}

    RectangleColliderComponent(const RectangleColliderComponent &) = delete;
    RectangleColliderComponent(RectangleColliderComponent &&) = delete;
    RectangleColliderComponent &operator=(const RectangleColliderComponent &) = delete;
    RectangleColliderComponent &operator=(RectangleColliderComponent &&) = delete;

    ~RectangleColliderComponent() { physicsSystem.RemoveRectangle(id); }

    void CheckIntersections(void (*callbackPtr)(PoolObjectId otherId)) {
        auto physObj = physicsSystem.GetRectangle(id);
        for (auto it = physObj.OverlappingObjects.begin(); it != physObj.OverlappingObjects.end();
             it++) {
            callbackPtr(*it);
        }
    };

    void CheckIntersections(std::function<void(PoolObjectId otherId)> lambdaCallback) {
        auto physObj = physicsSystem.GetRectangle(id);
        for (auto it = physObj.OverlappingObjects.begin(); it != physObj.OverlappingObjects.end();
             it++) {
            lambdaCallback(*it);
        }
    };

    void UpdatePosition(TransformComponent transform) {
        physicsSystem.GetRectangle(id).SetPos(transform);
    };
};
