#include <functional>
#include <string>

//__COUNT__ is a hack to check how many enum members there are, at runtime
// but more importantly forces the string array to be the same size
// worst case scenario this results in some strings being empty
enum class EventName { PlayerScored, ComputerScored, __COUNT__ };
static const std::array<std::string, (int)EventName::__COUNT__> EventNameStrings = {
    "PlayerScored", "ComputerScored"};

class EventManager {
   private:
    std::unordered_map<EventName, std::vector<std::function<void()>>> eventMap;
    static EventManager* instance;
    EventManager() = default;

   public:
    static EventManager& GetInstance() {
        if (instance == nullptr) {
            instance = new EventManager();
        }
        return *instance;
    };

    void Subscribe(EventName name, std::function<void()> callback);
    void Invoke(EventName name);
};
