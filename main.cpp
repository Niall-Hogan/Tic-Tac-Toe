#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <time.h>

using namespace std;

// boolean values to determine players and game status
bool play = true;
bool humanPlayer;

// PROTOTYPE FUNCTIONS
void mainMenu(string&, string&);
void printboard(string board[][3]);
void playerTurn(string board[][3], string, int&);
void player2Turn(string board[][3], string, int&);
void computerTurn(string board[][3]);
void gameplay();
bool checkWin(string board[][3],string,string,int&);
bool exit ();
void delay();


void delay() // delays for 3 seconds so player can see where computer has chosen
{
    auto start = std::chrono::high_resolution_clock::now();


    for (int i=1; i< 3; i++)
    {

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end-start;


}

void mainMenu(string &y, string &z) // name1 and name 2 passed by reference
{


    int x;
    cout << "Welcome to Tic Tac Toe!\n\nWhat's your name player one?: \t";
    cin >> y;


    cout << "\nWould you like to play the computer ( 1 ) or a friend ( 2 ):\t";
    cin >> x;

    //selection to choose to play a human or computer

    while (cin.fail() || x > 2)   // if anything but a number
    {
        cin.clear(); // clear cin of previous input
        cin.ignore(); // ignore previous input
        cout << "Please choose option ( 1 ) or ( 2 ):\t";
        cin >> x;
    }

    if (x == 2)
    {
        humanPlayer = true;

        cout << "\nWhat's your name player two?: \t";
        cin >> z;


    }
    else if ( x == 1)
    {

        humanPlayer = false;


    }


    system("CLS");// clears screen


}
bool exit()
{
    int x;

    cout << "Press 1 to play again or 2 to exit \t";
    cin >> x;

      while (cin.fail() || x > 2)   // only accepts 1 -2 , no chars.
    {
        cin.clear(); // clear cin of previous input
        cin.ignore(); // ignore previous input
        cout << "Please enter 1 or 2: \n";
        cin >> x;
    }

    if (x == 1)
    {
        system("CLS");
        gameplay();
    } else {

    play = false;
    return play;
    }

}

bool checkWin(string mainBoard[][3], string x, string y, int &t) // function to check win
{


    if (y =="") // if name 2 is blank
    {
        y = "Computer"; // name = computer
    }

    // O wins

    // diagonal wins
    if (mainBoard[0][0] == "O" && mainBoard[1][1]== "O" && mainBoard[2][2] == "O")
    {
        cout << "\t\t" <<  x  <<" wins!\n\n";
        printboard(mainBoard);
        cout << "\n\n";
        exit();


    }
    else if (mainBoard[0][2] == "O" && mainBoard[1][1]== "O" && mainBoard[2][0] == "O")
    {
        cout << "\t\t" <<  x  <<" wins!\n\n";
        printboard(mainBoard);
        cout << "\n\n";
        exit();
    }


    // for loop to cycle through horizontal and vertical wins
    for (int i = 0; i < 3; ++i)
    {

        // checks for horizontal wins
        if (mainBoard[i][0] == "O" && mainBoard[i][1]== "O" && mainBoard[i][2] == "O")
        {
            cout << "\t\t" <<  x  <<" wins!\n\n";
            printboard(mainBoard);
            cout << "\n\n";
            exit();

        }// checks for vertical wins
        else if (mainBoard[0][i] == "O" && mainBoard[1][i]== "O" && mainBoard[2][i] == "O")
        {
            cout << "\t\t" <<  x  <<" wins!\n\n";
            printboard(mainBoard);
            cout << "\n\n";
            exit();
        }


    }




    // X wins

    // checks for diagonal wins
    if (mainBoard[0][0] == "X" && mainBoard[1][1]== "X" && mainBoard[2][2] == "X")
    {
        cout << "\t\t" <<  y  <<" wins!\n\n";
        printboard(mainBoard);
        cout << "\n\n";
        exit();

    }
    else if (mainBoard[0][2] == "X" && mainBoard[1][1]== "X" && mainBoard[2][0] == "X")
    {
        cout << "\t\t" <<  y  <<" wins!\n\n";
        printboard(mainBoard);
        cout << "\n\n";
        exit();

    }


    // for loop to cycle through horizontal and vertical wins
    for (int i = 0; i < 3; i++)
    {
        // checks horizontal wins
        if (mainBoard[i][0] == "X" && mainBoard[i][1]== "X" && mainBoard[i][2] == "X")
        {

            cout << "\t\t" <<  y  <<" wins!\n\n";
            printboard(mainBoard);
            cout << "\n\n";
            exit();


        } // checks vertical wins
        else if (mainBoard[0][i] == "X" && mainBoard[1][i]== "X" && mainBoard[2][i] == "X")
        {

            cout << "\t\t" <<  y  <<" wins!\n\n";
            printboard(mainBoard);
            cout << "\n\n";
            exit();
        }
    }

    //Checks for draw

    if (t == 9 && play == true)
    {
        cout << "\t\tTie Game!\n\n";
        printboard(mainBoard);
        cout << "\n\n";
        exit();
    }



    return play;
}

void printboard(string mainBoard[][3]) // prints game board
{


    // nested for loops to print 2D array to construct the board

    for (int i = 0; i < 3; ++i )
    {
        cout << "\n\t\t";

        for (int j = 0; j < 3; ++j)
        {
            // if statement to print the lines of the board in the correct places

            if (j < 2)
            {
                cout << mainBoard[i][j] << " | "; // inserts vertical lines correctly

            }
            else if (j ==2)
            {
                cout << mainBoard[i][j];
            }

            if (i < 2 &&j == 2)
            {
                cout <<"\n\t\t=========="; // inserts horizontal lines correctly

            }
        }
    }


}

void playerTurn(string mainBoard[][3], string pName, int &t) // player ones turn
{


    int pMove;
    cout << "\n\nWhere would you like to place your 'O' " << pName << "?:\t";
    cin >> pMove;


    while (cin.fail() || pMove > 9)   // only accepts 1 -9, no chars.
    {
        cin.clear(); // clear cin of previous input
        cin.ignore(); // ignore previous input
        cout << "Please enter a number between 1 - 9 \n";
        cin >> pMove;
    }



    switch (pMove) // handles player input, checks if square is taken and places piece in free space
    {
    case 1:
        if (mainBoard[0][0] == "X" || mainBoard[0][0] == "O")
        {
            cout << "This square is already taken!";
            playerTurn(mainBoard, pName, t);
        }
        else
        {
            mainBoard[0][0] = "O";
        }

        break;

    case 2:
        if (mainBoard[0][1] == "X" || mainBoard[0][1] == "O")
        {
            cout << "This square is already taken!";
            playerTurn(mainBoard, pName, t);
        }
        else
        {
            mainBoard[0][1] = "O";
        }

        break;

    case 3:
        if (mainBoard[0][2] == "X" || mainBoard[0][2] == "O")
        {
            cout << "This square is already taken!";
            playerTurn(mainBoard, pName, t);
        }
        else
        {
            mainBoard[0][2] = "O";
        }
        break;

    case 4:
        if (mainBoard[1][0] == "X" || mainBoard[1][0] == "O")
        {
            cout << "This square is already taken!";
            playerTurn(mainBoard, pName, t);
        }
        else
        {
            mainBoard[1][0] = "O";
        }

        break;

    case 5:
        if (mainBoard[1][1] == "X" || mainBoard[1][1] == "O")
        {
            cout << "This square is already taken!";
            playerTurn(mainBoard, pName, t);
        }
        else
        {
            mainBoard[1][1] = "O";
        }

        break;

    case 6:
        if (mainBoard[1][2] == "X" || mainBoard[1][2] == "O")
        {
            cout << "This square is already taken!";
            playerTurn(mainBoard, pName, t);
        }
        else
        {
            mainBoard[1][2] = "O";
        }

        break;

    case 7:
        if (mainBoard[2][0] == "X" || mainBoard[2][0] == "O")
        {
            cout << "This square is already taken!";
            playerTurn(mainBoard, pName, t);
        }
        else
        {
            mainBoard[2][0] = "O";
        }

        break;

    case 8:
        if (mainBoard[2][1] == "X" || mainBoard[2][1] == "O")
        {
            cout << "This square is already taken!";
            playerTurn(mainBoard, pName, t);
        }
        else
        {
            mainBoard[2][1] = "O";
        }
        break;

    case 9:
        if (mainBoard[2][2] == "X" || mainBoard[2][2] == "O")
        {
            cout << "This square is already taken!";
            playerTurn(mainBoard, pName, t);
        }
        else
        {
            mainBoard[2][2] = "O";
        }
        break;


    }

    t++;
    system("CLS");
}

void player2Turn(string mainBoard[][3], string pName, int &t)
{

    int cMove;
    cout << "\n\nWhere would you like to place your 'X' " << pName << "?:\t";
    cin >> cMove;

    while (cin.fail()|| cMove > 9)   // if anything but a number
    {
        cin.clear(); // clear cin of previous input
        cin.ignore(); // ignore previous input
        cout << "Please enter a number between 1 - 9 \n";
        cin >> cMove;
    }




    switch (cMove)
    {
    case 1:

        if (mainBoard[0][0] == "O" || mainBoard[0][0] == "X")
        {
            cout << "This square is already taken!";
            player2Turn(mainBoard,pName, t);

        }
        else
        {
            mainBoard[0][0] = "X";
        }

        break;

    case 2:

        if (mainBoard[0][1] == "O" || mainBoard[0][1] == "X")
        {
            cout << "This square is already taken!";
            player2Turn(mainBoard,pName, t);

        }
        else
        {
            mainBoard[0][1] = "X";
        }
        break;

    case 3:
        if (mainBoard[0][2] == "O" || mainBoard[0][2] == "X")
        {
            cout << "This square is already taken!";
            player2Turn(mainBoard,pName, t);

        }
        else
        {
            mainBoard[0][2] = "X";
        }

        break;

    case 4:
        if (mainBoard[1][0] == "O" || mainBoard[1][0] == "X")
        {
            cout << "This square is already taken!";
            player2Turn(mainBoard,pName, t);

        }
        else
        {
            mainBoard[1][0] = "X";
        }

        break;

    case 5:
        if (mainBoard[1][1] == "O" || mainBoard[1][1] == "X")
        {
            cout << "This square is already taken!";
            player2Turn(mainBoard,pName, t);

        }
        else
        {
            mainBoard[1][1] = "X";
        }

        break;

    case 6:
        if (mainBoard[1][2] == "O" || mainBoard[1][2] == "X")
        {
            cout << "This square is already taken!";
            player2Turn(mainBoard,pName, t);

        }
        else
        {
            mainBoard[1][2] = "X";
        }

        break;

    case 7:
        if (mainBoard[2][0] == "O" || mainBoard[2][0] == "X")
        {
            cout << "This square is already taken!";
            player2Turn(mainBoard,pName, t);

        }
        else
        {
            mainBoard[2][0] = "X";
        }

        break;

    case 8:
        if (mainBoard[2][1] == "O" || mainBoard[2][1] == "X")
        {
            cout << "This square is already taken!";
            player2Turn(mainBoard,pName, t);

        }
        else
        {
            mainBoard[2][1] = "X";
        }

        break;

    case 9:
        if (mainBoard[2][2] == "O" || mainBoard[2][2] == "X")
        {
            cout << "This square is already taken!";
            player2Turn(mainBoard,pName, t);

        }
        else
        {
            mainBoard[2][2] = "X";
        }
        break;
    default:
        cout << "Please enter a number between 1 - 4 \n";
        break;
    }

    t++;
    system("CLS");

}


void computerTurn(string mainBoard[][3])
{

    int computerMove; // integer to store computer move
    bool found = false;


    while(found == false) // loop to find a free square
    {

        computerMove = 1 + rand() % 9; // assigns random value to computerMove

        string str = to_string(computerMove); // converts int to string

        for (int i = 0; i < 3; ++i) // nested for loop to cycle through the squares
        {
            for (int j = 0; j < 3; ++j)
            {
                if (str == mainBoard[i][j]) // if the square the computer chose is free
                {

                    cout << "\nComputer chose " << str;
                    delay(); // calls delay function
                    mainBoard[i][j] = "X"; // places computer piece
                    found = true; // breaks while loop
                }


            }
        }


    }




    system("CLS");


}




void gameplay()
{

    string name1, name2; // strings to hold player names
    string board[3][3] = {{"1","2","3"}, {"4","5","6"}, {"7","8","9"}}; // 2d array that holds grid values
    int turns = 0; // counter to monitor turns

    mainMenu(name1,name2); // passes name strings to mainMenu

       while (play != false && humanPlayer != false) // player 1 vs 2 while loop
    {

        printboard(board);
        playerTurn(board,name1,turns);
        checkWin(board,name1,name2,turns);
        if (play == false)
        {
            break;
        }
        printboard(board);
        player2Turn(board,name2,turns);
        checkWin(board,name1,name2,turns);
        if (play == false)
        {
            break;
        }


    }

        while (play != false && humanPlayer != true) // player 1 vs computer player while loop
    {

        printboard(board);
        playerTurn(board,name1, turns);
        checkWin(board,name1,name2,turns);
        if (play == false)
        {
            break;
        }
        printboard(board);
        computerTurn(board);
        checkWin(board,name1,name2,turns);
        if (play == false)
        {
            break;
        }


    }
}

int main()
{

    gameplay();



}
