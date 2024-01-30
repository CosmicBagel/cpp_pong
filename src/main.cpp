#include <raylib.h>

#include <format>
#include <iostream>
#include <memory>
#include <vector>

class IGameObject {
   public:
    IGameObject() = default;
    IGameObject(const IGameObject &) = default;
    IGameObject(IGameObject &&) = default;
    IGameObject &operator=(const IGameObject &) = default;
    IGameObject &operator=(IGameObject &&) = default;

    virtual ~IGameObject() = default;

    virtual void Init() = 0;
    virtual void Draw() = 0;
    virtual void Update() = 0;
};

struct TransformComponent final {
    int x = 0;
    int y = 0;
};

class PaddleGraphicComponent final {
   public:
    void Draw(TransformComponent transform) const {
        DrawRectangle(transform.x, transform.y, 100, 100, BLACK);
    }
};

class PlayerPaddle final : public IGameObject {
   private:
    uint count = 0;
    PaddleGraphicComponent paddleGraphic;
    TransformComponent transform;

   public:
    void Init() override {
        transform.x = 400;
        transform.y = 200;
    }
    void Draw() override {
        paddleGraphic.Draw(transform);
        auto str = std::format("{}", count);
        DrawText(str.c_str(), 0, 0, 18, BLACK);
    }
    void Update() override { count += 1; }
};

class ComputerPaddle final : public IGameObject {
   private:
    PaddleGraphicComponent paddleGraphic;
    TransformComponent transform;

   public:
    void Init() override {
        transform.x = 100;
        transform.y = 200;
    }
    void Draw() override { paddleGraphic.Draw(transform); }
    void Update() override {}
};

class Ball final : public IGameObject {
   private:
    TransformComponent transform;

   public:
    void Init() override { transform = {250, 250}; }
    void Draw() override { DrawCircle(transform.x, transform.y, 10, RED); }
    void Update() override {}
};

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
