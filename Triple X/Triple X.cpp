#include <iostream>
#include <windows.h>
#include <ctime>

using  namespace std;
void PrintIntroduction(int Difficulty)
{
	char* welcome = (char*)"*** You are a employee in the goverment agency focused on homeland security.\n Terrorists have broken into the building and hacked the mainframe after which they changed security codes for all elevators and entrances.\n In order to reach server room and retake control of the building you have to use your BreakThrough apk installed on your smartphone.\n BreakThrough.apk shall allow you to try and crack security pins so you can advance towards the upper floors. ***\n\n\n";
		int x = 0;
	for (int x = 0; welcome[x] != '\0'; x++) {
		cout << welcome[x];
		if (welcome[x] != ' ' && welcome[x] != '\n')
			Beep(40, 5);
		Sleep(50);
	}
	cout << std::endl;

}
bool PlayGame(int Difficulty)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	const int CodeA = rand() % Difficulty + Difficulty;
	const int CodeB = rand() % Difficulty + Difficulty;
	const int CodeC = rand() % Difficulty + Difficulty;

	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;
	cout << "\nYou are on the floor " << Difficulty << ".\nEnter correct codes to continue...\n";
	cout << std::endl;
	cout << "+ There are 3 numbers in the code" << endl;
	cout << "+ The codes add-up to:  " << CodeSum << endl;
	cout << "+ The codes multiply to give: " << CodeProduct << endl;


	int GuessA, GuessB, GuessC;
	cin >> GuessA >> GuessB >> GuessC;

	cout << "You entered: " << GuessA << " " << GuessB << " " << GuessC << endl;

	cout << std::endl;
	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;


	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{
		cout << "\n*** Well done! You have cracked the pin, and now you can advance towards upper floor! ***\n";
		
		return true;
	}
	else
	{
		cout << "\n*** You have entered the wrong code! Be careful and try again! ***\n";
		return false;
	}
}

int main()
{
	srand(time(NULL));

	int LevelDifficulty = 1;
	int const MaxDifficulty = 7;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	PrintIntroduction(LevelDifficulty);
	while (LevelDifficulty <= MaxDifficulty) {
		bool bLevelComplete = PlayGame(LevelDifficulty);
		std::cin.clear();
		std::cin.ignore();
		if (bLevelComplete)
		{
			++LevelDifficulty;

		}
	}

	cout << "\n*** Great job! You have successfully managed to reach the server room and lock terrorists inside the building while law enforcements arrive! ***";
	return 0;
}


