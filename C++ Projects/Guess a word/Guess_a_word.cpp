#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
const int MAX_TRIES=5;
int letterFill (char, string, string&);
int main ()
{
string option;
string name;
char letter;
int num_of_wrong_guesses=0;
string word;
string words[] = {"same","about","all","also","and","brand","fool","be","because","but","boy","can","come","could","day","dig","even","find",
"first","foriegn","from","get","give","go","have","he","help","here","him","his","how","island","ice","in","into","it","icon","just","know",
"like","look","make","man","many","me","more","my","car","no","not","now","of","on","one","only","or","other","our","out","people","say",
"see","she","so","some","take","tell","than","that","the","their","them","then","there","these","they","thing","think","tall","those","time",
"to","two","up","use","very","want","way","we","well","what","when","which","who","will","with","would","year","you","your"};


cout << "play game(y/n):";
cin >> option;
if (option == "y")
{
    cout << "\nLet's play a game" << endl;

    srand(time(NULL));
    int n=rand()% 10;
    word=words[n];
    string unknown(word.length(),'_');
    cout << "\nWelcome to a game...Guess a word"<<endl;
    cout << "\nYou have " << MAX_TRIES << " tries to try and guess the word.";
while (num_of_wrong_guesses < MAX_TRIES)
{

    cout << "\n\nHere are the length of the word: " << unknown;
    cout << "\n\nGuess a letter: ";
    cin >> letter;
if (letterFill(letter, word, unknown)==0)
{
    cout << endl << "Oops! That letter isn't in there!" << endl;
    num_of_wrong_guesses++;
}
else
{
    cout << endl;
}
    cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
    cout << " guesses left." << endl;
if (word==unknown)
{
    cout << "Yeah! You Win!" << endl;;
    cout<< "The word was : " << word << endl;
    break;
}
}
if(num_of_wrong_guesses == MAX_TRIES)
{
    cout << "\nSorry, you lose..." << endl;
    cout << "The word was : " << word << endl;
}
}
else if (option == "n")
{
    cout << "\nExit game\n" << endl;
}
else
{
    cout << "\nInvalid Input\n" << endl;
}




}
int letterFill (char guess, string secretword, string &guessword)
{
    int i;
    int matches=0;
    int len=secretword.length();
for (i = 0; i< len; i++)
{
if (guess == guessword[i])
{
    return 0;
}
if (guess == secretword[i])
{
    guessword[i] = guess;
    matches++;
}
return matches;

}
}


