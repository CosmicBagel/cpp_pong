#pragma once

#include "IGameObject.hpp"
#include "TransformComponent.hpp"

class Ball final : public IGameObject {
   private:
    TransformComponent transform;

   public:
    void Init() override;
    void Draw() override;
    void Update() override;
};
