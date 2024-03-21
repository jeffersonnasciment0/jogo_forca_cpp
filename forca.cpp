#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

/*
Definitions globals 
*/
string secret_word = "MELANCIA";
map<char, bool> choices;
vector<char> wrong_choices;

/**
 * Game presentention
*/
void presentation(){
    cout << "*************************" << endl;
    cout << "***** JOGO DA FORCA *****" << endl;
    cout << "*************************" << endl;
}

/**
 * Compare the user's choice with the letters of the
 * secret word
 * 
 * @return true if user choice is in secret word
 * 
 * @return false if the user's choice is not in secret word
*/
bool correct_guess(char choice){
    for(char letter_word: secret_word){
        if (choice == letter_word)
        {
            return true;
        }
    }
    return false;
} 

/**
 * Checks if the user made a mistake in choosing
 * 
 * @return true if the user guessed wrong
 * 
 * @return false is the user guessed correct
*/
bool wrong_guess(){
    for (char letter_word : secret_word)
    {
        if (!choices[letter_word])
        {
            return true;
        }
    }
    return false;
}

/**
 * Checks if the user was not hanged (lost all chances)
 * 
 * @return true if the wrong estimates are less than 5
*/
bool not_hanged(){
    return wrong_choices.size() < 5; 
}

/**
 * shows the word according to the correct letter
*/
void show_word(){
    for (char letter_word: secret_word)
    {
        if (choices[letter_word])
        {
            cout << letter_word << " ";
        }
        else{
            cout << "_ ";
        }  
    }
    
    cout << endl;
    cout << endl;
}

/**
 * shows the wrong letters already chosen
*/
void show_wrong_guess(){
    cout << "Chutes errados: " << endl; 
    for (char choices: wrong_choices)
    {
        cout << choices;
    }
}

/**
 * Setting the user's letter choice as right or wrong
*/
void choice(){
    cout << "Digite uma Letra da palavra: " << endl;
    char choice;
    cin >> choice;
    cout << endl;

    choices[choice] = true;

    if (correct_guess(choice))
    {
        cout << "Você Acertou a Letra !" << endl;
    }else{
        cout << "Você Errou a Letra !" << endl;
        wrong_choices.push_back(choice);
    }

    cout << endl;
}

/**
 * Reads a file with the secret words
 * 
 * @return the words from the secret word file 
*/
vector<string> read_file(){
    ifstream file;
    file.open("secrets_words.txt");

    if (file.is_open()){
        int number_words;
        file >> number_words;

        vector<string> words_file;

        for (int i = 1; i < number_words+1; i++)
        {
            string word_read;
            file >> word_read;
            words_file.push_back(word_read);
        }

        file.close();
        return words_file;

    }else
    {
        cout << "Não foi possível acessar o banco de palavras !" << endl;
        exit(0);
    }
    
    
}

/**
 * Choose a random secret word from the secret word file
*/
void sortition(){
    vector<string> words = read_file();

    srand(time(NULL));
    int index_choice = rand() % words.size();

    secret_word = words[index_choice];
}

/**
 * Writes new words to the secret word file
*/
void record_words(vector<string> nova_lista){
    ofstream file;
    file.open("secrets_words.txt");
    if (file.is_open())
    {
        file << nova_lista.size() << endl;

        for (string word : nova_lista)
        {
            file << word << endl;
        }

        file.close();

    }else{
        cout << "Não foi possível acessar o banco de palavras ! " << endl;
        exit(0);
    }
    
}

/**
 * Add new words in secret words list
*/
void add_word(){
    cout << "Digite a nova palavra(USE letter_wordS MAIUSCULAS !): "  << endl;
    string new_word;
    cin >> new_word;

    vector<string> words_list = read_file();
    words_list.push_back(new_word);

    record_words(words_list);
}

/**
 * MAIN
*/
int main(){

    presentation();
    read_file();
    sortition();

    while (wrong_guess() && not_hanged())
    {

        show_word();
        show_wrong_guess();

        cout << endl;
        cout << endl;
        
        choice();
    }

    cout << "Fim de Jogo !" << endl;

    if (wrong_guess())
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