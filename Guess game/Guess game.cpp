
#include <iostream>
#include <vector>
#include<string>
#include<cctype>
#include<windows.h>
using namespace std;
const HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // for coloer text 
struct StGameState
{
	string Word = "";
	string WordGuss = "";
	int Round = 10;
	char GuessLetter = ' ';
	int LetterPosition = 0;
	bool IsCorrect = false;
};
int RandomNumber(int from, int to)
{
	int randomnumber = rand() % (to - from + 1) + from;
	return randomnumber;
}
void  SelectWord(StGameState& Game)
{
	string WordsArr[] = { "programing","course","intelligent","life","future","dream","love","freedom" };
	Game.Word = WordsArr[RandomNumber(0, 8)];
}
void  ReplaceLettersBy_(StGameState& Game)
{
	for (int i = 0; i < Game.Word.length(); i++)
	{
		Game.WordGuss = Game.WordGuss + "_";
	}
}
void  GusseLetter(StGameState& Game)
{
	char Letter;
	cout << "\nGusse a letter : ";
	cin >> Letter;
	Game.GuessLetter = Letter;
}
bool IsCorrect(StGameState& Game)
{
	for (int i = 0; i < Game.Word.length(); i++)
	{
		if (Game.Word[i] == Game.GuessLetter)
		{
			Game.IsCorrect = true;
			return true;
		}

	}
	return false;
}
void LetterPosition(StGameState& Game)
{
	for (int i = 0; i < Game.Word.length(); i++)
	{
		if (Game.Word[i] == Game.GuessLetter)
		{
			Game.Word[i] = '*';
			Game.LetterPosition = i;
			break;
		}
	}
}
void ReplaceUnderscoreByLetter(StGameState& Game)
{
	Game.WordGuss[Game.LetterPosition] = Game.GuessLetter;
}
void GuessGame()
{
	SetConsoleTextAttribute(h, 3); // color
	cout << "\t\tWelcome to the word Gussing Game !!\n\n";
	SetConsoleTextAttribute(h, 7);
	StGameState Game;
	SelectWord(Game);
	string OriginalWord = Game.Word;
	ReplaceLettersBy_(Game);
	cout << "\nHere us the word to gusse :" << Game.WordGuss <<"  " << OriginalWord.size()<<" Letters"<< endl;
	while (true)
	{
		GusseLetter(Game);
		system("cls");
		SetConsoleTextAttribute(h, 3); // color
		cout << "\t\tWelcome to the word Gussing Game !!\n\n";
		SetConsoleTextAttribute(h, 7); // reset black color
		if (IsCorrect(Game))
		{
			LetterPosition(Game);
			SetConsoleTextAttribute(h, 2);
			cout << "\nCorrect Guess ! the letter " << Game.GuessLetter << " is found \n\n";
			SetConsoleTextAttribute(h, 7);
			ReplaceUnderscoreByLetter(Game);
			cout << "Word :" << Game.WordGuss << endl;
		}
		else
		{
			Game.Round--;
			SetConsoleTextAttribute(h, 4);
			cout << "\nInccorect guess ! you have " << Game.Round << " gesses left\n" << endl;
			SetConsoleTextAttribute(h, 7);
			cout << "Word :" << Game.WordGuss << endl;
		}
		if (Game.WordGuss == OriginalWord)
		{
			cout << "\n\t\t.....Congratulation....Right Word\n";
			return;
		}
		if (Game.Round == 0)
		{
			cout << "\n\t\t...GAME OVER ...\n";
			return;
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	GuessGame();

	system("pause>0");
	return 0;
}