#include "Ball.hpp"

#include "raylib.h"

void Ball::Init() { transform = {250, 250}; }
void Ball::Draw() { DrawCircle(transform.x, transform.y, 10, RED); }
void Ball::Update() {}
