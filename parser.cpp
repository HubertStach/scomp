//
// Created by hubert on 2/20/26.
//

#include "parser.h"

#include <iostream>
#include <ostream>

Token peek(const Parser *parser, int ahead) {
    if (parser->m_index + ahead >= parser->tokens.size()) {
        return {INVALID, ""};
    }
    return parser->tokens.at(parser->m_index + ahead);
}

// Return the current token and move the index forward
Token consume(Parser *parser) {
    return parser->tokens.at(parser->m_index++);
}

NodeExpr parse_expr(Parser *parser) {
    // Check if current token is an integer
    if (peek(parser).type == INT_VALUE) {
        return {.token = consume(parser)};
    } else {
        std::cerr << "Expected integer expression" << std::endl;
        exit(EXIT_FAILURE);
    }
}

NodeExit parse_exit(Parser *parser) {
    NodeExit node;

    while (peek(parser).type != INVALID) {

        if (peek(parser).type == RETURN) {
            consume(parser);

            node.expr = parse_expr(parser);

            if (peek(parser).type == SEMICOLON) {
                consume(parser);
            } else {
                std::cerr << "Expected ';'" << std::endl;
                exit(EXIT_FAILURE);
            }
            return node;
        }
        else {
            consume(parser);
        }
    }
    return node;
}