#include "PlayerPaddle.hpp"

#include <raylib.h>

#include <format>

#include "PhysicsSystem.hpp"

void PlayerPaddle::Init() {
    transform.x = 400;
    transform.y = 200;
    auto tempRectanglePhysicsObjectId =
        PhysicsSystem::GetInstance().CreateRectangle(transform, 100, 100);
}
void PlayerPaddle::Draw() {
    paddleGraphic.Draw(transform);
    auto str = std::format("{}", count);
    DrawText(str.c_str(), 0, 0, 18, BLACK);
}
void PlayerPaddle::Update() { count += 1; }
