#include "PlayerPaddle.hpp"

#include <format>

#include "raylib.h"

void PlayerPaddle::Init() {
    transform.x = 400;
    transform.y = 200;
}
void PlayerPaddle::Draw() {
    paddleGraphic.Draw(transform);
    auto str = std::format("{}", count);
    DrawText(str.c_str(), 0, 0, 18, BLACK);
}
void PlayerPaddle::Update() { count += 1; }
