#include "ComputerPaddle.hpp"

#include "PhysicsSystem.hpp"

void ComputerPaddle::Init() {
    transform.x = 100;
    transform.y = 200;
    auto tempRectanglePhysicsObjectId =
        PhysicsSystem::GetInstance().CreateRectangle(transform, 100, 100);
}
void ComputerPaddle::Draw() { paddleGraphic.Draw(transform); }
void ComputerPaddle::Update() {}
