#include <iostream>
#include "show_wrong_guess.hpp"


/**
 * shows the wrong letters already chosen
*/
void Forca::show_wrong_guess(const std::vector<char>& wrong_choices)
{
	std::cout << "Chutes errados: " << std::endl; 
	for (char choices: wrong_choices)
	{
		std::cout << choices;
	}
}