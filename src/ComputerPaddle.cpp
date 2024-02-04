#include "ComputerPaddle.hpp"

void ComputerPaddle::Init() {
    transform.x = 100;
    transform.y = 200;
}
void ComputerPaddle::Draw() { paddleGraphic.Draw(transform); }
void ComputerPaddle::Update() {}
