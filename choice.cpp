#include <iostream>
#include "choice.hpp"
#include "correct_guess.hpp"

/**
 * Setting the user's letter choice as right or wrong
*/
void choice(std::map<char, bool>& choices, std::vector<char>& wrong_choices, std::string& secret_word){
    std::cout << "Digite uma Letra da palavra: " << std::endl;
    char choice;
    std::cin >> choice;
    std::cout << std::endl;

    choices[choice] = true;

    if (correct_guess(choice, secret_word))
    {
        std::cout << "Você Acertou a Letra !" << std::endl;
    }else{
        std::cout << "Você Errou a Letra !" << std::endl;
        wrong_choices.push_back(choice);
    }

    std::cout << std::endl;
}