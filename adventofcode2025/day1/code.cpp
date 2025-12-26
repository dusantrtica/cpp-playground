#include "code.hpp"
#include <iostream>

int password(const std::vector<std::string> &input) {
  int position = 50;
  int num_of_zero_positions = 0;
  for (const auto &line : input) {
    int direction = line[0] == 'L' ? -1 : 1;
    int steps = std::stoi(line.substr(1));
    if (direction == -1) {
      steps = 100 - steps;
    }
    position += steps;
    position = position % 100;

    // std::cout << "Starting position: " << position << std::endl;
    if (position == 0) {
      num_of_zero_positions += 1;
    }
  }
  return num_of_zero_positions;
}

int password_with_crossing_zero(const std::vector<std::string> &input) {
  int position = 50;
  int num_of_zero_positions = 0;
  for (const auto &line : input) {
    int direction = line[0] == 'L' ? -1 : 1;
    int steps = std::stoi(line.substr(1));
    if (steps >= 100) {
      num_of_zero_positions += steps / 100;
      steps = steps % 100;
    }

    std::cout << "Position: " << position << " " << steps << " " << direction
              << std::endl;
    if (direction == -1) {
      if (steps >= position && position != 0) {
        num_of_zero_positions++;
      }
      steps = 100 - steps;
    } else if (position + steps >= 100) {
      num_of_zero_positions++;
    }

    position += steps;
    position = position % 100;
  }

  return num_of_zero_positions;
}
