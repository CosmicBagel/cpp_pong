#pragma once
class IGameObject {
   public:
    IGameObject() = default;
    IGameObject(const IGameObject &) = default;
    IGameObject(IGameObject &&) = default;
    IGameObject &operator=(const IGameObject &) = default;
    IGameObject &operator=(IGameObject &&) = default;

    virtual ~IGameObject() = default;

    virtual void Init() = 0;
    virtual void Draw() = 0;
    virtual void Update() = 0;
};
