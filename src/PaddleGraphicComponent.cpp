#include "PaddleGraphicComponent.hpp"

#include <raylib.h>

void PaddleGraphicComponent::Draw(TransformComponent transform) const {
    DrawRectangle(transform.x, transform.y, 15, 110, BLACK);
}
