#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "presentention.hpp"
#include "show_wrong_guess.hpp"
#include "choice.hpp"
#include "sortition.hpp"
#include "add_word.hpp"
#include "show_word.hpp"
#include "read_file.hpp"
#include "wrong_guess.hpp"

using namespace std;

static string secret_word;
static map<char, bool> choices;
static vector<char> wrong_choices;
//static array<char, 5> wrong_choices;


/**
 * MAIN
*/
int main(){

	
    presentation();

    secret_word = sortition();

    while (wrong_guess(secret_word, choices) && wrong_choices.size() < 5)
    {

        show_word(secret_word, choices);
        Forca::show_wrong_guess(wrong_choices);

        cout << endl;
        cout << endl;
        
        choice(choices, wrong_choices, secret_word);
    }

    cout << "Fim de Jogo !" << endl;

    if (wrong_guess(secret_word, choices))
    {
        cout << "Você Perdeu ! A palavra secreta era " << secret_word << endl;
    }else{
        cout << "Você Ganhou !!! A palavra secreta era " << secret_word << endl;;
        cout << "Você deseja adicionar um nova palavra ao banco ? (S/N)" << endl;
        char resp;
        cin >> resp;
        if(resp == 'S'){
            add_word();
        }
    }
    
}