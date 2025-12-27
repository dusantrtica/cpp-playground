#include "code.hpp"

bool is_invalid_id(const int id) {
  std::string id_str = std::to_string(id);
  if(id_str.length() % 2 == 1) {
    return false;
  }

  int i = 0;
  int n = id_str.length() / 2;
  while (i < n && id_str[i] == id_str[i+n]) {
    i++;
  }

  if(i == n) {
    return true;
  }

  return false;
}
