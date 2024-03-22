#include <iostream>
#include <fstream>
#include "record_words.hpp"

/**
 * Writes new words to the secret word file
*/
void record_words(std::vector<std::string> nova_lista){
    std::ofstream file;
    file.open("secrets_words.txt");
    if (file.is_open())
    {
        file << nova_lista.size() << std::endl;

        for (std::string word : nova_lista)
        {
            file << word << std::endl;
        }

        file.close();

    }else{
        std::cout << "Não foi possível acessar o banco de palavras ! " << std::endl;
        exit(0);
    }
    
}