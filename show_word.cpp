#include <iostream>
#include "show_word.hpp"

/**
 * shows the word according to the correct letter
*/
void show_word(std::string& secret_word,const std::map<char, bool>& choices){
    for (char letter_word: secret_word)
    {
        if (choices.find(letter_word) != choices.end())
        {
            std::cout << letter_word << " ";
        }
        else{
            std::cout << "_ ";
        }  
    }
    
    std::cout << std::endl;
    std::cout << std::endl;
}