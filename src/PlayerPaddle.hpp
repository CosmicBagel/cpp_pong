#pragma once

#include "IGameObject.hpp"
#include "PaddleGraphicComponent.hpp"

class PlayerPaddle final : public IGameObject {
   private:
    unsigned int count = 0;
    PaddleGraphicComponent paddleGraphic;
    TransformComponent transform;

   public:
    void Init() override;
    void Draw() override;
    void Update() override;
};
