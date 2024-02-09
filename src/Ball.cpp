#include "Ball.hpp"

#include "PhysicsSystem.hpp"
#include "raylib.h"

void Ball::Init() {
    transform = {250, 250};
    // initialize
    rectanglePhysicsObjectId = PhysicsSystem::GetInstance().CreateRectangle();
}
void Ball::Draw() { DrawCircle(transform.x, transform.y, 10, RED); }
void Ball::Update() {}
