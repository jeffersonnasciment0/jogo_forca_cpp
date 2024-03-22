#include "wrong_guess.hpp"

/**
 * Checks if the user made a mistake in choosing
 * 
 * @return true if the user guessed wrong
 * 
 * @return false is the user guessed correct
*/
bool wrong_guess(std::string& secret_word, const std::map<char, bool>& choices)
{
    for (char letter_word : secret_word)
    {
        if (choices.find(letter_word) == choices.end() || !choices.at(letter_word))
        {
            return true;
        }
    }
    return false;
}