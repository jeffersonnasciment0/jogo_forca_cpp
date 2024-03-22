#include <vector>
#include <ctime>
#include <cstdlib>
#include "read_file.hpp"


/**
 * Choose a random secret word from the secret word file
*/
std::string sortition(){
    std::vector<std::string> words = read_file();

    srand(time(NULL));
    int index_choice = rand() % words.size();

    return words[index_choice];
}
