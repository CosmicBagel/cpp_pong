#include "Ball.hpp"

#include <functional>

#include "Events.hpp"
#include "PhysicsObjectTag.hpp"
#include "PhysicsSystem.hpp"
#include "PoolManager.hpp"
#include "RectanglePhysicsObject.hpp"
#include "raylib.h"

const TransformComponent Ball::StartingPos = {400, 300};

void Ball::Init() {
    EventManager& em = EventManager::GetInstance();
    std::function<void()> fn = std::bind(&Ball::ResetPos, this);
    em.Subscribe(EventName::PlayerScored, fn);
    em.Subscribe(EventName::ComputerScored, fn);
}

void Ball::ResetPos() {
    velX = StartingVelX;
    velY = StartingVelY;
    transform = StartingPos;
    collider.UpdatePosition(transform);
}

void Ball::Draw() { DrawRectangle(transform.x, transform.y, 20, 20, drawColor); }

void Ball::Update() {
    PhysicsSystem& physicsSystem = PhysicsSystem::GetInstance();
    drawColor = RED;
    collider.ProcessIntersections([&](PoolObjectId otherId) {
        PhysicsObjectTag otherTag = physicsSystem.GetRectangle(otherId).GetTag();
        TransformComponent otherPos = physicsSystem.GetRectangle(otherId).GetPos();
        int otherHeight = physicsSystem.GetRectangle(otherId).GetHeight();

        switch (otherTag) {
            case PhysicsObjectTag::Paddle: {
                // DebugLog("Hit paddle");
                velX *= -1;

                int otherCenter = otherHeight / 2 + otherPos.y;
                // DebugLog("other center {}", otherCenter);
                int thisCenter = 10 + transform.y;
                // DebugLog("this center {}", thisCenter);
                int centerDistance = otherCenter - thisCenter;

                velY = (int)(centerDistance * -1 * 0.05F);
                // DebugLog("Center distance {}", centerDistance);
                break;
            }
            case PhysicsObjectTag::Wall:
                // DebugLog("Hit wall");
                velY *= -1;
                break;
            case PhysicsObjectTag::None:
                // DebugLog("Hit unknown object");
                break;
        }

        drawColor = GREEN;
    });

    transform.x += velX;
    transform.y += velY;
    collider.UpdatePosition(transform);
}
