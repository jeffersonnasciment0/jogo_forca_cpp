#include "correct_guess.hpp"


/**
 * Compare the user's choice with the letters of the
 * secret word
 * 
 * @return true if user choice is in secret word
 * 
 * @return false if the user's choice is not in secret word
*/
bool correct_guess(char choice, std::string& secret_word){
    for(char letter_word: secret_word){
        if (choice == letter_word)
        {
            return true;
        }
    }
    return false;
} 