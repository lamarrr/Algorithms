#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool IsPermutation(const std::string& a, const std::string& b) {
  std::vector<char> tmp_a{a.begin(), a.end()};
  std::vector<char> tmp_b{b.begin(), b.end()};
  std::sort(tmp_a.begin(), tmp_a.end());
  std::sort(tmp_b.begin(), tmp_b.end());
  auto [ma, mb] = std::mismatch(tmp_a.begin(), tmp_a.end(), tmp_b.begin());
  return ma == tmp_a.end() && mb == tmp_b.end();
}

int main() {
  std::cout << std::boolalpha;

  std::cout << IsPermutation("123", "312") << std::endl;
  std::cout << IsPermutation("logarithm", "algorithm") << std::endl;
  std::cout << IsPermutation("Boy", "boY") << std::endl;
  std::cout << IsPermutation("Eer", "erE") << std::endl;
}