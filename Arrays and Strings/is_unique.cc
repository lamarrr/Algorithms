#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool IsUniqueString(const std::string& str) {
  std::vector<char> tmp{str.begin(), str.end()};
  std::sort(tmp.begin(), tmp.end());

  for (size_t i = 1; i < tmp.size(); i++) {
    if (tmp[i] == tmp[i - 1]) return false;
  }
  return true;
}

int main() {
  std::cout << std::boolalpha;
  std::cout << IsUniqueString("Hello") << std::endl;
  std::cout << IsUniqueString("World") << std::endl;
}