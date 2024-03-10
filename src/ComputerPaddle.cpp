#include "ComputerPaddle.hpp"

#include "Logging.hpp"
#include "Math.hpp"

void ComputerPaddle::Init() { moveTargetTransform = transform; }
void ComputerPaddle::Draw() { paddleGraphic.Draw(transform); }

int yikes = 0;
void ComputerPaddle::Update() {
    /*
     * follow ball, but with randomized drift and lag
     * intentionally follow ball badly
     *
     * - has an internal target point to follow, with randomly changing strength of lerp to it
     * - the target itself follows the ball but also with its own randomly changing lerp
     * - target also has an offset that oscillates (sine wave)
     */

    moveTargetTransform.y = ballTransform.y + 55;

    transform.y += lerp(transform.y, 500);

    // yikes = lerp(yikes, 100);
    DebugLog("math {}", transform.y);
}


