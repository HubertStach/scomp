#include <iostream>
#include <sstream>
#include "lexer.h"
#include "code_gen.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <file_name>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string file_name = argv[1];
    Lexer lexer;
    init_lexer(&lexer, file_name);
    //print_lexer(&lexer);

    Parser parser(lexer.tokens);
    NodeExit root = parse_exit(&parser);

    Generator generator(root);
    generator.save_gen_code();

    //creating executable from assembly file
    system("nasm -felf64 out.asm");
    system("ld -o out out.o");

    return 0;
}