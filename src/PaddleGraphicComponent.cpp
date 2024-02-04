#include "PaddleGraphicComponent.hpp"

#include <raylib.h>

void PaddleGraphicComponent::Draw(TransformComponent transform) const {
    DrawRectangle(transform.x, transform.y, 100, 100, BLACK);
}
