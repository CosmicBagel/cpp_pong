#include "Ball.hpp"

#include "PhysicsObjectTag.hpp"
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
        PhysicsObjectTag otherTag = physicsSystem.GetRectangle(otherId).GetTag();
        TransformComponent otherPos = physicsSystem.GetRectangle(otherId).GetPos();
        int otherHeight = physicsSystem.GetRectangle(otherId).GetHeight();

        switch (otherTag) {
            case PhysicsObjectTag::Paddle: {
                // TraceLog(LOG_DEBUG, "Hit paddle");
                velX *= -1;

                int otherCenter = otherHeight / 2 + otherPos.y;
                // TraceLog(LOG_DEBUG, std::format("other center {}", otherCenter).c_str());
                int thisCenter = 10 + transform.y;
                // TraceLog(LOG_DEBUG, std::format("this center {}", thisCenter).c_str());
                int centerDistance = otherCenter - thisCenter;

                velY = (int)(centerDistance * -1 * 0.05F);
                // TraceLog(LOG_DEBUG, std::format("Center distance {}", centerDistance).c_str());
                break;
            }
            case PhysicsObjectTag::Wall:
                // TraceLog(LOG_DEBUG, "Hit wall");
                velY *= -1;
                break;
            case PhysicsObjectTag::None:
                // TraceLog(LOG_DEBUG, "Hit unknown object");
                break;
        }

        drawColor = GREEN;
    });

    transform.x += velX;
    transform.y += velY;
    collider.UpdatePosition(transform);
}
