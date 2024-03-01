#include "Events.hpp"

#include <format>
#include <functional>

#include "raylib.h"

EventManager* EventManager::instance = nullptr;

void EventManager::Subscribe(EventName name, std::function<void()> callback) {
    if (!eventMap.contains(name)) {
        eventMap[name] = std::vector<std::function<void()>>();
    }
    eventMap[name].push_back(callback);
}

void EventManager::Invoke(EventName name) {
    if (!eventMap.contains(name)) {
        std::string nameStr = EventNameStrings[(int)name];
        TraceLog(LOG_ERROR,
                 std::format("Attempted to invoke uninitalized event: {}", nameStr).c_str());
        return;
    }
    if (eventMap[name].empty()) {
        std::string nameStr = EventNameStrings[(int)name];
        TraceLog(
            LOG_WARNING,
            std::format("Invoked event: {}, but it was empty (no subscribers)", nameStr).c_str());
        return;
    }

    std::vector<std::function<void()>>& vec = eventMap[name];
    for (auto it = vec.begin(); it != vec.end(); it++) {
        (*it)();
    }
}
