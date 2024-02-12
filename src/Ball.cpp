#include "Ball.hpp"

#include "Crash.hpp"
#include "PhysicsSystem.hpp"
#include "raylib.h"

void Ball::Init() {
    transform = {250, 250};
    // initialize
    rectanglePhysicsObjectId = PhysicsSystem::GetInstance().CreateRectangle(transform, 10, 10);
}

auto drawColor = RED;
void Ball::Draw() { DrawRectangle(transform.x, transform.y, 20, 20, drawColor); }
void Ball::Update() {
    auto physObjGetResult = PhysicsSystem::GetInstance().GetRectangle(rectanglePhysicsObjectId);
    if (!physObjGetResult.success) {
        Crash::panic("GetRectangle failed");
    }
    auto physObj = physObjGetResult.object;

    if (physObj->OverlappingObjects.size() > 0) {
        drawColor = GREEN;
    } else {
        drawColor = RED;
    }

    int speed = 1;
    if (IsKeyDown(KEY_LEFT_SHIFT)) {
        speed = 3;
    }

    int xDiff = 0;
    int yDiff = 0;
    if (IsKeyDown(KEY_W)) {
        yDiff -= speed;
    }
    if (IsKeyDown(KEY_S)) {
        yDiff += speed;
    }
    if (IsKeyDown(KEY_D)) {
        xDiff += speed;
    }
    if (IsKeyDown(KEY_A)) {
        xDiff -= speed;
    }

    transform.x += xDiff;
    transform.y += yDiff;
    physObj->SetPos(transform);

    // PhysicsSystem::GetInstance().SetRectangle(rectanglePhysicsObjectId, physObj);
}
