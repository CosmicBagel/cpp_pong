#include "Ball.hpp"

#include "Crash.hpp"
#include "PhysicsSystem.hpp"
#include "RectanglePhysicsObject.hpp"
#include "raylib.h"

PhysicsSystem& physicsSystem = PhysicsSystem::GetInstance();

void Ball::Init() {
    transform = {250, 250};
    // initialize
    rectanglePhysicsObjectId = physicsSystem.CreateRectangle(transform, 20, 20);
}

void Ball::Draw() { DrawRectangle(transform.x, transform.y, 20, 20, drawColor); }

void Ball::Update() {
    RectanglePhysicsObject& physObj = physicsSystem.GetRectangle(rectanglePhysicsObjectId);

    if (!physObj.OverlappingObjects.empty()) {
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
    physObj.SetPos(transform);
}
