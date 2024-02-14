#pragma once

#include "IGameObject.hpp"
#include "RectangleColliderComponent.hpp"
#include "TransformComponent.hpp"
class Wall : public IGameObject {
   private:
    TransformComponent transform;
    RectangleColliderComponent collider;

   public:
    Wall(TransformComponent transform)
        : transform(transform), collider(transform, 800, 20, PhysicsObjectTag::Wall){};
    void Init() override;
    void Draw() override;
    void Update() override;
};
