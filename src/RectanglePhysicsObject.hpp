#pragma once

#include <cstddef>
#include <vector>

#include "PhysicsObjectTag.hpp"
#include "PoolManager.hpp"
#include "TransformComponent.hpp"

class PhysicsSystem;

class RectanglePhysicsObject final {
    friend class PhysicsSystem;

   private:
    size_t id = 0;
    TransformComponent transform;
    int width = 0, height = 0;
    PhysicsObjectTag tag = PhysicsObjectTag::None;

   public:
    std::vector<PoolObjectId> OverlappingObjects;

    RectanglePhysicsObject() = default;
    RectanglePhysicsObject(TransformComponent transform, int width, int height,
                           PhysicsObjectTag tag)
        : transform(transform), width(width), height(height), tag(tag){};

    RectanglePhysicsObject(const RectanglePhysicsObject& source)
        : id(source.id),
          transform(source.transform),
          width(source.width),
          height(source.height),
          OverlappingObjects(source.OverlappingObjects){};

    RectanglePhysicsObject& operator=(const RectanglePhysicsObject& source) {
        id = source.id;
        transform = source.transform;
        width = source.width;
        height = source.height;
        OverlappingObjects = source.OverlappingObjects;
        return *this;
    };

    RectanglePhysicsObject(RectanglePhysicsObject&&) = delete;
    RectanglePhysicsObject& operator=(RectanglePhysicsObject&&) = delete;

    ~RectanglePhysicsObject();

    TransformComponent GetPos() { return transform; };
    void SetPos(TransformComponent _transform) { transform = _transform; };
    int GetWidth() const { return width; };
    void SetWidth(int _width) { width = _width; };
    int GetHeight() const { return height; };
    void SetHeight(int _height) { height = _height; };
    PhysicsObjectTag GetTag() { return tag; }
};
