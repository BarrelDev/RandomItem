#include <iostream>
#include <ctime>
#include <windows.h>
#include <string>

std::string List[10] = {"sword", "axe", "pickaxe", "hoe", "shovel", "flint and steel", "bow", "crossbow", "potion", "armor"};
int upper = 9;
int lower = 0;
int Guess;

void ClearScreen();

int main()
{
    srand(time(0));
    //num = (rand() % (upper – lower + 1)) + lower
    std::string SelectedItem = List[rand() % (upper - lower + 1) + lower];
    int AnswerCounter = 0;
    std::string RandomItem;
    std::cout << "Check How many times the word " << SelectedItem << " is repeated\nPlease press enter to continue.";
    std::cin.ignore();
    ClearScreen();
    for(int i = 1; i <=10 ; i++)
    {
        RandomItem = List[rand() % (upper - lower + 1) + lower];
        std::cout << RandomItem << std::endl;
        Sleep(500);
        ClearScreen();
        if (RandomItem == SelectedItem)
        {
            AnswerCounter += 1;
        }
    }
    std::cout << "Please enter the number of times the word " << SelectedItem << " was repeated:\n";
    std::cin >> Guess;
    if (Guess == AnswerCounter)
    {
        std::cout << "Good Job! You guessed the right amount of times!";
        std::cin.ignore();
    }else
    {
        std::cout << "Good effort, but you did not guess the correct amount of times.";
        std::cin.ignore();
    }
    std::cin.ignore();
    return 0;
}

void ClearScreen()
  {
  HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Move the cursor home */
  SetConsoleCursorPosition( hStdOut, homeCoords );
  }