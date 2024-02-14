#include <raylib.h>

#include <csignal>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>

#include "Ball.hpp"
#include "ComputerPaddle.hpp"
#include "PhysicsSystem.hpp"
#include "PlayerPaddle.hpp"
#include "Wall.hpp"

/*
 * todo
 *   - bounce ball off paddle at different angles depending where ball hits paddle
 *       - physics object / collider tags
 *       - ball responds to wall and paddle differently
 *         (handle case if ball intersects both wall and paddle)
 */

void HandleKeyboardInterrupt(int signal) {
    std::cout << "Keyboard interrupt. Killing game." << std::endl;
    std::quick_exit(signal);
}

int main() {
    Crash::SetupSignalHandler();
    std::signal(SIGINT, HandleKeyboardInterrupt);

#ifdef CPP_PONG_DEBUG_BUILD
    SetTraceLogLevel(LOG_DEBUG);
#endif

    std::cout << "oh hey it pong" << std::endl;

    const int screenWidth = 800;
    const int screenHeight = 600;
    const int targetFps = 60;

    InitWindow(screenWidth, screenHeight, "cpp_pong");

    SetTargetFPS(targetFps);

    // init physicsSystem
    PhysicsSystem &physicsSystem = PhysicsSystem::GetInstance();

    // pass function pointer to collider event desired

    // spawn objects
    std::vector<std::unique_ptr<IGameObject>> gameObjects;

    gameObjects.push_back(std::unique_ptr<IGameObject>{new PlayerPaddle});
    gameObjects.push_back(std::unique_ptr<IGameObject>{new ComputerPaddle});
    gameObjects.push_back(std::unique_ptr<IGameObject>{new Ball});
    gameObjects.push_back(std::unique_ptr<IGameObject>{new Wall({0, 0})});
    gameObjects.push_back(std::unique_ptr<IGameObject>{new Wall({0, 580})});

    for (auto &gobj : gameObjects) {
        gobj->Init();
    }

    while (!WindowShouldClose()) {
        // update systems
        physicsSystem.Update();

        // update game objects
        for (auto &gobj : gameObjects) {
            gobj->Update();
        }

        // render
        BeginDrawing();
        ClearBackground(DARKGRAY);
        for (auto &gobj : gameObjects) {
            gobj->Draw();
        }
        EndDrawing();
    }

    return 0;
}
