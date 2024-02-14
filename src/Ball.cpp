#include "Ball.hpp"

#include "PhysicsSystem.hpp"
#include "PoolManager.hpp"
#include "RectanglePhysicsObject.hpp"
#include "raylib.h"

PhysicsSystem& physicsSystem = PhysicsSystem::GetInstance();

void Ball::Init() {}

void Ball::Draw() { DrawRectangle(transform.x, transform.y, 20, 20, drawColor); }

void Ball::Update() {
    drawColor = RED;
    collider.ProcessIntersections([&](PoolObjectId otherId) {
        drawColor = GREEN;
        velX *= -1;
        velY *= -1;
    });

    transform.x += velX;
    transform.y += velY;
    collider.UpdatePosition(transform);
}
