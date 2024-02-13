#include "PlayerPaddle.hpp"

#include <raylib.h>

#include <format>

void PlayerPaddle::Init() {}

void PlayerPaddle::Draw() {
    paddleGraphic.Draw(transform);
    auto str = std::format("{}", count);
    DrawText(str.c_str(), 0, 0, 18, BLACK);
}

void PlayerPaddle::Update() {
    count += 1;

    // int velX = 0;
    int velY = 0;

    int speed = 3;
    if (IsKeyDown(KEY_W)) {
        velY -= speed;
    }
    if (IsKeyDown(KEY_S)) {
        velY += speed;
    }
    // if (IsKeyDown(KEY_A)) {
    //     velX -= 1;
    // }
    // if (IsKeyDown(KEY_D)) {
    //     velX += 1;
    // }

    // transform.x += velX;
    transform.y += velY;
    collider.UpdatePosition(transform);
}
