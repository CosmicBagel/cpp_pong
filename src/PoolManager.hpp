#pragma once

#include <cstddef>
#include <format>
#include <vector>

#include "Crash.hpp"
#include "raylib.h"

// todo replace with an object reference, similar to how std::iterator works
//   where the user can just access properties on it as if they have the object
//   and not worry about memory issues with it
typedef size_t PoolObjectId;

template <typename T>
class PoolObjectWrapper {
   public:
    bool active = false;
    T object;
};

template <typename T>
struct RetrievedPoolObject {
    bool success = false;
    T *object;
};

template <typename T>
class PoolManager {
   private:
    std::vector<PoolObjectWrapper<T>> pool;
    int activeCount = 0;

   public:
    PoolManager(const PoolManager &) = delete;
    PoolManager(PoolManager &&) = delete;
    PoolManager &operator=(const PoolManager &) = delete;
    PoolManager &operator=(PoolManager &&) = delete;
    explicit PoolManager<T>(size_t starting_size) { pool.reserve(starting_size); }

    PoolObjectId Add(T object) {
        activeCount += 1;
        for (size_t id = 0; id < pool.size(); id++) {
            if (!pool[id].active) {
                pool[id].active = true;
                pool[id].object = object;
                return id;
            }
        }
        // all current slots are full, we need to push
        size_t id = pool.size();
        pool.push_back(PoolObjectWrapper<T>{true, object});
        return id;
    }

    T &GetInfallible(PoolObjectId id) {
        if (id < 0 || id >= pool.size()) {
            Crash::panic(std::format("PoolManager Get: Out of bounds id: {}", id));
        }
        if (!pool[id].active) {
            Crash::panic(
                std::format("PoolManager Get: Attempted to get inactive object with id: {}", id));
        }
        return pool[id].object;
    }

    RetrievedPoolObject<T> Get(PoolObjectId id) {
        if (id < 0 || id >= pool.size()) {
            return {false, nullptr};
        }
        return {pool[id].active, &pool[id].object};
    };

    bool Set(PoolObjectId id, T obj) {
        if (id < 0 || id >= pool.size()) {
            return false;
        }
        if (!pool[id].active) {
            return false;
        }
        pool[id] = {true, obj};
        return true;
    };

    auto begin() { return pool.begin(); }
    auto end() { return pool.end(); }

    void Remove(PoolObjectId id) {
        activeCount -= 1;
        if (id < 0 || id >= pool.size()) {
            Crash::panic(std::format("PoolManager Get: Out of bounds id: {}", id));
        }
        if (!pool[id].active) {
            Crash::panic(
                std::format("PoolManager Get: Attempted to remove inactive "
                            "object with id: {}",
                            id));
        }
        pool[id].active = false;
    }

    int GetActiveCount() { return activeCount; }
};
