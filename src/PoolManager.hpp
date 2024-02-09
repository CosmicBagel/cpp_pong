#pragma once

#include <cstddef>
#include <format>
#include <vector>

#include "Crash.hpp"

typedef size_t PoolObjectId;

template <typename T>
class PoolObjectWrapper {
   public:
    bool active = false;
    T object;
};

template <typename T>
class PoolManager {
   private:
    std::vector<PoolObjectWrapper<T>> pool;

   public:
    explicit PoolManager<T>(size_t starting_size) { pool.reserve(starting_size); }

    PoolObjectId Add(T object) {
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

    T Get(PoolObjectId id) {
        if (id < 0 || id >= pool.size()) {
            Crash::panic(std::format("PoolManager Get: Out of bounds id: {}", id));
        }
        if (!pool[id].active) {
            Crash::panic(
                std::format("PoolManager Get: Attempted to get inactive object with id: {}", id));
        }
        return pool[id].object;
    }

    void Remove(PoolObjectId id) {
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
};
