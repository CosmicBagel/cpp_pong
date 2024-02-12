#pragma once

#include "IGameObject.hpp"
#include "PoolManager.hpp"
#include "TransformComponent.hpp"

class Ball final : public IGameObject {
   private:
    TransformComponent transform;
    PoolObjectId rectanglePhysicsObjectId;
    Color drawColor = RED;

   public:
    void Init() override;
    void Draw() override;
    void Update() override;
};
