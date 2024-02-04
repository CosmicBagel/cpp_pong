#include <raylib.h>

#include <iostream>
#include <memory>
#include <vector>

#include "Ball.hpp"
#include "ComputerPaddle.hpp"
#include "PlayerPaddle.hpp"

int main() {
    std::cout << "oh hey it pong" << std::endl;

    const int screenWidth = 800;
    const int screenHeight = 600;
    const int targetFps = 60;

    InitWindow(screenWidth, screenHeight, "cpp_pong");

    SetTargetFPS(targetFps);

    std::vector<std::unique_ptr<IGameObject>> gameObjects;
    gameObjects.push_back(std::unique_ptr<IGameObject>{new PlayerPaddle});
    gameObjects.push_back(std::unique_ptr<IGameObject>{new ComputerPaddle});
    gameObjects.push_back(std::unique_ptr<IGameObject>{new Ball});

    for (auto &gobj : gameObjects) {
        gobj->Init();
    }

    while (!WindowShouldClose()) {
        for (auto &gobj : gameObjects) {
            gobj->Update();
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        for (auto &gobj : gameObjects) {
            gobj->Draw();
        }
        EndDrawing();
    }

    return 0;
}
