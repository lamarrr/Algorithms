#include <cinttypes>
#include <iostream>
#include <stack>
#include <string_view>

enum class Token : uint8_t { Curly = '{', Curved = '(', Straight = '[' };

Token GetClose(Token token) {
  switch (token) {
    case Token::Curly:
      return static_cast<Token>('}');

    case Token::Curved:
      return static_cast<Token>(')');

    case Token::Straight:
      return static_cast<Token>(']');

    default:
      return static_cast<Token>('\0');
  }
}

bool IsBalanced(std::string_view str) {
  std::stack<Token> tokens;
  for (char i : str) {
    if (i == '{' || i == '[' || i == '(') {
      tokens.push(static_cast<Token>(i));
    } else if (i == '}' || i == ']' || i == ')') {
      if (tokens.empty() || GetClose(tokens.top()) != static_cast<Token>(i))
        return false;
      tokens.pop();
    }
  }
  return tokens.empty();
}

int main(int argc, char** argv) {
  std::string u = "[hello][()][]}";
  std::cout << std::boolalpha << "str: " << u
            << ",  IsBalanced(): " << IsBalanced(u) << std::endl;
}









#include <cinttypes>
#include <iostream>
#include <stack>
#include <string_view>

enum class Token : uint8_t { Curly = '{', Curved = '(', Straight = '[' };

inline Token GetClose(Token token) {
  switch (token) {
    case Token::Curly:
      return static_cast<Token>('}');

    case Token::Curved:
      return static_cast<Token>(')');

    case Token::Straight:
      return static_cast<Token>(']');

    default:
      return static_cast<Token>('\0');
  }
}

inline bool IsBalanced(std::string_view str) {
  std::stack<Token> tokens;
  for (char i : str) {
    if (i == '{' || i == '[' || i == '(') {
      tokens.push(static_cast<Token>(i));
    } else if (i == '}' || i == ']' || i == ')') {
      if (tokens.empty() || GetClose(tokens.top()) != static_cast<Token>(i))
        return false;
      tokens.pop();
    }
  }
  return tokens.empty();
}

int main(int argc, char** argv) {
  std::string u = "[hello][()][]{}";
  std::cout << std::boolalpha << "str: " << u
            << ",  IsBalanced(): " << IsBalanced(u) << std::endl;
}
