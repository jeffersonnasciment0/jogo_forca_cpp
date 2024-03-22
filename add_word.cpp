#include <iostream>
#include "read_file.hpp"
#include "record_words.hpp"

/**
 * Add new words in secret words list
*/
void add_word(){
    std::cout << "Digite a nova palavra(USE LETRAS MAIUSCULAS !): "  << std::endl;
    std::string new_word;
    std::cin >> new_word;

    std::vector<std::string> words_list = read_file();
    words_list.push_back(new_word);

    record_words(words_list);
}
