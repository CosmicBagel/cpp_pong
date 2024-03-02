#include "IGameObject.hpp"

class ScoreKeeper final : public IGameObject {
   private:
    int playerScore = 0;
    int computerScore = 0;

    void PlayerScored();
    void ComputerScored();

   public:
    void Init() override;
    void Update() override;
    void Draw() override;
};
