//
// Created by hubert on 2/16/26.
//

#ifndef CCOMP_LEXER_H
#define CCOMP_LEXER_H
#include <string>
#include <vector>

enum TokenType {
  // variable values
  INT_VALUE,

  //variable types
  INTEGER,

  //variable names
  LITERAL,

  //keywordy
  RETURN,
  IF,
  ELSE,
  WHILE,
  FOR,
  PRINT,
  //operatory
  SEMICOLON,
  PLUS,
  MINUS,
  MULT,
  DIV,
  EQUAL,
  NOTEQUAL,
  LESS,
  GREATER,
  LESSEQ,
  GREATEREQ,

  INVALID

};

struct Token {
  TokenType type;
  std::string value;

  Token(TokenType type, std::string value) : type(type), value(value) {}
  Token() {
    type = TokenType::INVALID;
  }
};

struct Lexer {
  std::string source;
  std::vector<Token> tokens;
};

char peek(const Lexer *lexer, int current, int ahead);
char consume(const Lexer *lexer, int &ahead);

void init_lexer(Lexer *lexer, const std::string& file_name);
void tokenize(Lexer *lexer);
void print_lexer(const Lexer *lexer);

#endif //CCOMP_LEXER_H