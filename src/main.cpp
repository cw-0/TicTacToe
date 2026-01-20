#include "globals.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>

const char *X{"\033[36mX\033[0m"};
const char *O{"\033[31mO\033[0m"};

void print_board();
void game_loop();
bool spot_unavailable(int target);
int get_chosen_spot();
bool check_for_win(std::vector<int> *player_spots);
bool vector_find(int target, std::vector<int> *player_spots);
void clear_terminal();
std::string spot_symbol(int n);

int main() {
  game_loop();
  system("pause");
  return 0;
}

void print_board() {
  std::cout << "Player 1: " << X << "\nPlayer 2: " << O << "\n\n";
  std::cout << " " << spot_symbol(1) << " | " << spot_symbol(2) << " | "
            << spot_symbol(3) << "\n";
  std::cout << "-----------\n";
  std::cout << " " << spot_symbol(4) << " | " << spot_symbol(5) << " | "
            << spot_symbol(6) << "\n";
  std::cout << "-----------\n";
  std::cout << " " << spot_symbol(7) << " | " << spot_symbol(8) << " | "
            << spot_symbol(9) << "\n";
  std::cout << '\n';
}

void game_loop() {
  while (!game_over) {
    clear_terminal();
    print_board();
    player_one_turn = !player_one_turn;
    int chosen_spot = get_chosen_spot();

    if (player_one_turn) {
      player_one_spots.push_back(chosen_spot);
    } else {
      player_two_spots.push_back(chosen_spot);
    }
    available_spots.erase(std::remove(available_spots.begin(),
                                      available_spots.end(), chosen_spot),
                          available_spots.end());

    bool winner_found = check_for_win(
        (player_one_turn ? ptr_player_one_spots : ptr_player_two_spots));

    if (winner_found) {
      clear_terminal();
      print_board();
      std::cout << "Player " << (player_one_turn ? "1" : "2") << " Wins!\n";
      return;
    }

    if (available_spots.size() <= 0) {
      clear_terminal();
      print_board();
      std::cout << "TIE\n";
      return;
    }
  }
}

bool spot_unavailable(int target) {
  auto check =
      std::find(available_spots.begin(), available_spots.end(), target);
  return check == available_spots.end() ? true : false;
}

int get_chosen_spot() {
  int chosen_spot{};

  while (true) {
    std::cout << "Player " << (player_one_turn ? "1" : "2") << " Choose Spot: ";
    std::cin >> chosen_spot;
    if (spot_unavailable(chosen_spot)) {
      std::cout << "Invalid Spot\n";
      chosen_spot = 0;
      continue;
    } else {
      return chosen_spot;
    }
  }
}

bool check_for_win(std::vector<int> *player_spots) {
  if (vector_find(1, player_spots) && vector_find(2, player_spots) &&
      vector_find(3, player_spots)) {
    return true;
  }

  if (vector_find(4, player_spots) && vector_find(5, player_spots) &&
      vector_find(6, player_spots)) {
    return true;
  }

  if (vector_find(7, player_spots) && vector_find(8, player_spots) &&
      vector_find(9, player_spots)) {
    return true;
  }

  if (vector_find(1, player_spots) && vector_find(4, player_spots) &&
      vector_find(7, player_spots)) {
    return true;
  }

  if (vector_find(2, player_spots) && vector_find(5, player_spots) &&
      vector_find(8, player_spots)) {
    return true;
  }

  if (vector_find(3, player_spots) && vector_find(6, player_spots) &&
      vector_find(9, player_spots)) {
    return true;
  }

  if (vector_find(1, player_spots) && vector_find(5, player_spots) &&
      vector_find(9, player_spots)) {
    return true;
  }

  if (vector_find(3, player_spots) && vector_find(5, player_spots) &&
      vector_find(7, player_spots)) {
    return true;
  }

  return false;
}

bool vector_find(int target, std::vector<int> *vector) {
  std::vector<int>::iterator found =
      std::find(vector->begin(), vector->end(), target);
  if (found != vector->end()) {
    return true;
  }
  return false;
}

void clear_terminal() {
#ifdef _WIN32
  std::system("cls");
#else
  std::system("clear");
#endif
}

std::string spot_symbol(int n) {
  if (vector_find(n, ptr_available_spots))
    return std::to_string(n);
  if (vector_find(n, ptr_player_one_spots))
    return X;
  return O;
}
