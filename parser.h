//
// Created by hubert on 2/20/26.
//
#pragma once
#include <vector>

#include "lexer.h"

struct NodeExpr {
  Token token;
};

struct NodeExit {
  NodeExpr expr;
};

struct Parser {
  std::vector<Token> tokens;
  size_t m_index = 0;

  explicit Parser(std::vector<Token> tokens) : tokens(std::move(tokens)) {}
};

Token peek(const Parser *parser, int ahead = 0);
Token consume(Parser *parser);
NodeExpr parse_expr(Parser *parser);
NodeExit parse_exit(Parser *parser);
