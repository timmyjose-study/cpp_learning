#include <iostream>
#include <string>
#include <vector>

enum TokenType {
  Foo,
  Bar,
  Baz,
};

class Token {
public:
  Token(TokenType kind, std::string spelling)
      : kind(kind), spelling(spelling) {}

  TokenType get_kind() const { return kind; }
  const std::string &get_spelling() const { return spelling; }

  friend std::ostream &operator<<(std::ostream &out, const Token &token) {
    return out << "Token { kind = " << token.kind
               << ", spelling = " << token.spelling << " }";
  }

private:
  TokenType kind;
  std::string spelling;

  friend class Lexer;
};

class Lexer {
public:
  Lexer() {
    tokens.push_back(Token{TokenType::Foo, std::string("foo")});
    tokens.push_back(Token{TokenType::Bar, std::string("bar")});
    tokens.push_back(Token{TokenType::Baz, std::string("baz")});
  }

  std::vector<Token>::const_iterator begin() const { return tokens.begin(); }
  std::vector<Token>::const_iterator end() const { return tokens.end(); }

private:
  std::vector<Token> tokens;
};

int main() {
  Lexer lexer;

  for (auto it = lexer.begin(); it != lexer.end(); it++) {
    std::cout << *it << std::endl;
  }

  return 0;
}
