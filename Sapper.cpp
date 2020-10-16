#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


int main()
{
    cout << R"(    Welcome to the game - <<Sapper>>

    Rules of the game :

1) Array must be at least 4 characters
2) If you opened a cell with a mine, then the game is lost 
3) The game continues until you open all non-mined lands

    Good luck


)";


    int sizeRows,               //  размер строки и столбца динамического массива
        sizeCols,

        iRand,                  //   рандомное разброска мины
        jRand,

        col,                    //  для поиска значение в массиве
        row,

        mines = 0,              //  счетчик для минных участков 
        freeLand = 0,           //  счетчик для свободных участков
        checkfreeLand = 0;      // найденные свободные участки
    const int quitQame = -1;    // выход из игры
    const int minSize = 1;      // минимальный размер (строки/столбца)

    srand(time(nullptr));

    // минимальный размер массива должен быть 2х2;
    do
    {
        cout << " Quit game  " << quitQame << " \n Enter rows size - ";
        cin >> sizeRows;
        if (sizeRows == quitQame)
        {
            cout << "You quit game\n";
            return 1;
        }
        if (sizeRows <= minSize)
        {
            cout << "\n Minimum size should be " << minSize << "\n Try again\n";
        }

    } while (sizeRows <= minSize);

    do
    {
        cout << " Quit game  " << quitQame << " \n Enter cols size - \n";
        cin >> sizeCols;
        if (sizeCols == quitQame)
        {
            cout << " You quit game\n";
            return 1;
        }
        if (sizeCols <= minSize)
        {
            cout << "\n Minimum size should be " << minSize << "\n Try again\n";
        }

    } while (sizeCols <= 1);



    char** arr = new char* [sizeRows];

    for (size_t i = 0; i < sizeRows; i++)
    {
        arr[i] = new char[sizeCols];

        for (size_t j = 0; j < sizeCols; j++)
        {
            arr[i][j] = '*';
        }
    }

    // рандомное разброска мины

    int averageNumMine = (sizeCols * sizeRows) / 2;

    for (size_t i = 0; i < averageNumMine; i++)
    {
        iRand = rand() % sizeRows;
        jRand = rand() % sizeCols;

        arr[iRand][jRand] = 'X';
    }

    // подсчет мины (в данной игре мины это << X >> ) 
    // подсчет свободного участка (в данной игре свободный участок  это  << + >> ) 

    for (size_t i = 0; i < sizeRows; i++)
    {
        for (size_t j = 0; j < sizeCols; j++)
        {
            if (arr[i][j] == 'X')
            {
                mines++;
            }
            else {
                freeLand++;
            }
            cout << "|";
            cout << "___";
            cout << "|";
        }
        cout << endl;
    }

    do
    {

        cout << " Quit game  " << quitQame << endl;
        cout << " " << mines << " mines on the map\n";
        cout << " You found " << checkfreeLand << " free land out of " << freeLand << " free land\n\n";
        do
        {
            cout << " Enter size row - ";
            cin >> row;

            if (row == quitQame)
            {
                cout << " You quit game\n";
                return 1;
            }
            else if (row >= sizeRows)
            {
                cout << " Size row must not be greater than or equal to " << sizeRows << " ,please try again\n";
            }
        } while (row >= sizeRows);

        do
        {
            cout << " Enter size col - ";
            cin >> col;

            if (col == quitQame)
            {
                cout << " You quit game\n";
                return 1;
            }
            else if (col >= sizeCols)
            {
                cout << " Size col must not be greater than or equal to " << sizeCols << " ,please try again\n";
            }
        } while (col >= sizeCols);


        system("cls");

        if (arr[row][col] == 'X')
        {
            cout << " GAME OVER\n You hit a mine \n";
            for (int i = 0; i < sizeRows; i++)
            {
                for (int j = 0; j < sizeCols; j++)
                {

                    cout << "|";
                    if (arr[i][j] == 'X') {
                        cout << "_X_";
                    }
                    else if (arr[i][j] == '+') {
                        cout << "_+_";
                    }
                    else {
                        cout << "___";
                    }

                    cout << "|";
                }
                cout << endl;
            }
            break;
        }
        else {
            cout << " Right choice\n";
            arr[row][col] = '+';
        }

        for (int i = 0; i < sizeRows; i++)
        {
            for (int j = 0; j < sizeCols; j++)
            {
                cout << "|";
                if (arr[i][j] == '+') {
                    cout << "_+_";
                }
                else {
                    cout << "___";
                }

                cout << "|";
            }
            cout << endl;
        }
        checkfreeLand = 0;
        for (size_t i = 0; i < sizeRows; i++)
        {
            for (size_t j = 0; j < sizeCols; j++)
            {
                if (arr[i][j] == '+')
                {
                    checkfreeLand++;
                }
            }
        }

        if (freeLand == checkfreeLand)
        {
            cout << "Congratulations, you have opened all mine - free sites\n";
            break;
        }
    } while (arr[row][col] != 'X');


    for (size_t i = 0; i < sizeRows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
