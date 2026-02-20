//
// Created by hubert on 2/19/26.
//

#ifndef CCOMP_CODE_GEN_H
#define CCOMP_CODE_GEN_H
#include <string>
#include "lexer.h"
#include "parser.h"

struct Generator {
    NodeExit root;
    explicit Generator(NodeExit root): root(std::move(root)) {}
    [[nodiscard]] std::string generate_code() const;
    void save_gen_code() const;
};

std::stringstream token_to_asm(std::vector<Token> &tokens);
void gen_asm(Lexer *lexer);

#endif //CCOMP_CODE_GEN_H