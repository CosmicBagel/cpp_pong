#pragma once

#include "IGameObject.hpp"
#include "PaddleGraphicComponent.hpp"
#include "TransformComponent.hpp"

class ComputerPaddle final : public IGameObject {
   private:
    PaddleGraphicComponent paddleGraphic;
    TransformComponent transform;

   public:
    void Init() override;
    void Draw() override;
    void Update() override;
};
