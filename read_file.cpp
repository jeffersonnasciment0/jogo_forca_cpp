#include <iostream>
#include <fstream>
#include "read_file.hpp"



/**
 * Reads a file with the secret words
 * 
 * @return the words from the secret word file 
*/
std::vector<std::string> read_file(){
    std::ifstream file;
    file.open("secrets_words.txt");

    if (file.is_open()){
        int number_words;
        file >> number_words;

        std::vector<std::string> words_file;

        for (int i = 1; i < number_words+1; i++)
        {
            std::string word_read;
            file >> word_read;
            words_file.push_back(word_read);
        }

        file.close();
        return words_file;

    }else
    {
        std::cout << "Não foi possível acessar o banco de palavras !" << std::endl;
        exit(0);
    }
}