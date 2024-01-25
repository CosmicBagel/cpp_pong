#include <raylib.h>

#include <iostream>

int main() {
    std::cout << "oh hey it pong" << std::endl;

    const int screenWidth = 800;
    const int screenHeight = 600;
    const int targetFps = 60;

    InitWindow(screenWidth, screenHeight, "cpp_pong");

    SetTargetFPS(targetFps);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    return 0;
}

