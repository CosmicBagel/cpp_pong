#include "ScoreKeeper.hpp"

#include <raylib.h>

#include <format>

#include "Events.hpp"

void ScoreKeeper::PlayerScored() {
    playerScore++;
    TraceLog(LOG_DEBUG, "player scored!!!");
}

void ScoreKeeper::ComputerScored() {
    computerScore++;
    TraceLog(LOG_DEBUG, "computer scored!!!");
}

void ScoreKeeper::Init() {
    EventManager& em = EventManager::GetInstance();
    std::function<void()> fnPlayerScored = std::bind(&ScoreKeeper::PlayerScored, this);
    std::function<void()> fnComputerScored = std::bind(&ScoreKeeper::ComputerScored, this);
    em.Subscribe(EventName::PlayerScored, fnPlayerScored);
    em.Subscribe(EventName::ComputerScored, fnComputerScored);
}

void ScoreKeeper::Update() {}
void ScoreKeeper::Draw() {
    const char* cmpStr = std::format("{}", computerScore).c_str();
    const char* playerStr = std::format("{}", playerScore).c_str();

    DrawText(cmpStr, 0, 0, 18, BLACK);
    DrawText(playerStr, 750, 0, 18, BLACK);
}
