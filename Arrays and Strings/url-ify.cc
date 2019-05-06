#include <algorithm>
#include <iostream>
#include <memory>
#include <string>

std::string URLify(const std::string& str) {
  std::string buff;

  for (char c : str) {
    if (c != ' ') {
      buff.push_back(c);
    } else {
      buff.append("%20");
    }
  }

  return std::move(buff);
}

int main() { std::cout << URLify("Hello, World!"); }