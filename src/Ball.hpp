#pragma once

#include "IGameObject.hpp"
#include "TransformComponent.hpp"
#include "PoolManager.hpp"

class Ball final : public IGameObject {
   private:
    TransformComponent transform;
    PoolObjectId rectanglePhysicsObjectId;

   public:
    void Init() override;
    void Draw() override;
    void Update() override;
};
