#include "Wall.hpp"

#include "raylib.h"

void Wall::Init() {}
void Wall::Update() {}
void Wall::Draw() { DrawRectangle(transform.x, transform.y, 800, 20, BLUE); }
