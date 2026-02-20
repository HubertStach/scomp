//
// Created by hubert on 2/16/26.
//

#include "lexer.h"

#include <fstream>
#include <iostream>
#include <sstream>

std::string get_enum_name(enum TokenType t) {
    switch (t) {
        case INT_VALUE: return "INT_VALUE";
            //variable types
        case INTEGER: return "INTEGER";

            //variable names
        case LITERAL: return "LITERAL";

            //keywordy
        case RETURN: return "RETURN";
        case IF: return "IF";
        case ELSE: return "ELSE";
        case WHILE: return "WHILE";
        case FOR: return "FOR";
        case PRINT: return "PRINT";
            //operatory
        case SEMICOLON: return "SEMICOLON";

        case INVALID: return "INVALID";
    }
}

char peek(const Lexer *lexer, int current, int offset = 0) {
    if (current + offset > lexer->source.length()) {
        return 0; // Null terminator/EOF
    }
    return lexer->source.at(current + offset);
}

char consume(const Lexer *lexer, int &current) {
    char c = lexer->source.at(current);
    current++;
    return c;
}


void tokenize(Lexer *lexer) {
    int current = 0;
    int length = lexer->source.length();

    while (current < length) {
        char c = peek(lexer, current);

        if (isspace(c)) {
            consume(lexer, current);
            continue;
        }

        // identifiers and keywords
        if (isalpha(c)) {
            std::string buffer;
            while (current < length && isalnum(peek(lexer, current))) {
                buffer.push_back(consume(lexer, current));
            }

            if (buffer == "return") {
                lexer->tokens.emplace_back(RETURN, buffer);
            } else {
                lexer->tokens.emplace_back(LITERAL, buffer);
            }
        }
        // numbers
        else if (isdigit(c)) {
            std::string buffer;
            while (current < length && isdigit(peek(lexer, current))) {
                buffer.push_back(consume(lexer, current));
            }
            lexer->tokens.emplace_back(INT_VALUE, buffer);
        }

        //semicolon
        else if (c == ';') {
            std::string buffer;
            buffer.push_back(consume(lexer, current)); // Move current past ';'
            lexer->tokens.emplace_back(SEMICOLON, buffer);
        }

        // invalid
        else {
            std::string buffer;
            buffer.push_back(consume(lexer, current));
            lexer->tokens.emplace_back(INVALID, buffer);
        }
    }
}

void init_lexer(Lexer *lexer, const std::string& file_name) {
    std::ifstream file(file_name);
    if (!file.good()) {
        std::cerr << "Cannot open file: " << file_name << std::endl;
    }
    std::stringstream content_stream;
    content_stream << file.rdbuf();
    file.close();

    lexer->source = content_stream.str();
    tokenize(lexer);
}

void print_lexer(const Lexer *lexer) {
    for (const auto & token : lexer->tokens) {
        std::cout << get_enum_name(token.type)<<"->"<<token.value << std::endl;
    }
}