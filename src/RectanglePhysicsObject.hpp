#pragma once

#include <cstddef>

#include "TransformComponent.hpp"

class PhysicsSystem;

class RectanglePhysicsObject final {
    friend class PhysicsSystem;

   private:
    size_t id = 0;
    TransformComponent transform;
    int width = 0, height = 0;

   public:
    RectanglePhysicsObject(){};

    RectanglePhysicsObject(const RectanglePhysicsObject& source)
        : id(source.id),
          transform(source.transform),
          width(source.width),
          height(source.height){};

    RectanglePhysicsObject& operator=(const RectanglePhysicsObject& source) {
        id = source.id;
        transform = source.transform;
        width = source.width;
        height = source.height;
        return *this;
    };

    RectanglePhysicsObject(RectanglePhysicsObject&&) = default;
    RectanglePhysicsObject& operator=(RectanglePhysicsObject&&) = default;

    ~RectanglePhysicsObject();

    TransformComponent GetPos() { return transform; };
    void SetPos(TransformComponent _transform) { transform = _transform; };
    int GetWidth() const { return width; };
    void SetWidth(int _width) { width = _width; };
    int GetHeight() const { return height; };
    void SetHeight(int _height) { height = _height; };
};
