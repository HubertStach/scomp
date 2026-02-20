//
// Created by hubert on 2/19/26.
//

#include "code_gen.h"

#include <fstream>
#include <sstream>

std::string Generator::generate_code() const {
    std::stringstream result;
    result << "global _start\n_start:\n";
    result << "    mov rax, 60\n";
    result << "    mov rdi, " << root.expr.token.value << "\n";
    result << "    syscall";
    return result.str();
}

void Generator::save_gen_code() const {
    std::ofstream file("out.asm", std::ios::out);
    std::string code = generate_code();
    file << code;
    file.close();
}

