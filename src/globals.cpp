
#include <vector>
// constexpr int MAX_SPOTS{9};
// constexpr int MAX_NUMBER_SPOTS_OWNED{5};

std::vector<int> available_spots = {1, 2, 3, 4, 5, 6, 7, 8, 9};
std::vector<int> player_one_spots{};
std::vector<int> player_two_spots{};
std::vector<int> *ptr_available_spots = &available_spots;
std::vector<int> *ptr_player_one_spots = &player_one_spots;
std::vector<int> *ptr_player_two_spots = &player_two_spots;
bool game_over{};
bool player_one_turn{};
