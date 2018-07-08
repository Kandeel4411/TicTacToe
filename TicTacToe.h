#ifndef TICTACTOE_H
#define TICTACTOE_H


class TicTacToe
{
    public:

        TicTacToe(int &x)
        {
            //Welcome Window
        while(correct)
            {

        std::cout<< "\t  ----____________________----  \n"
                    "\t  |         [Welcome]        |  \n"
                    "\t  |                          |  \n"
                    "\t  |   ~~   Tic-Tac-Toe  ~~   |  \n"
                    "\t  |                          |  \n"
                    "\t  |         1. Play          |  \n"
                    "\t  |         2. Exit          |  \n"
                    "\t  ----____________________----  \n\n"

                    "\n\t          -_-_-                \n"
                    "\t           Choice:";
        std::cin>>choice;

        if(choice==1)
                {
                    getnames();
                    correct = 0;
                }
                    else if(choice != 2)
                            {
                                std::cout<<"\a";
                                WindowsClear();
                            }
                                else
                                        {
                                            WindowsClear();
                                            x = 0;
                                            correct = 0;

                                        }

            }
        }
///////////////////////////////////////////////////////////////
        void getnames()
        {
            //WINDOW FOR NAMES
            WindowsClear();
            std::cout<<"\n\n\t\t(*) Enter Player1 -<X> name: ";
                std::cin>>player1;
                    std::cout<<"\t\t(*) Enter Player2 -<O> name: ";
                        std::cin>>player2;

        }
///////////////////////////////////////////////////////////////
        void correctNames()
        {

             //De-captilize
                std::transform(player1.begin(), player1.end(), player1.begin(), tolower);
                std::transform(player2.begin(), player2.end(), player2.begin(), tolower);
            //If same name, adds crossponding signs
            if(player1==player2||flag == 1)
            {
                        if(flag == 0)
                        {
                        player1+=" <X>";
                            player2+=" <O>";
                        }

                        std::cout<<"\t"<<player1<<"  --  "<<player2<<std::endl<<std::endl;
                        flag = 1;
            }

            else
            {
                    std::cout<<"\t"<<player1<<" <X>  --  "<<player2<<"  <O>"<<std::endl<<std::endl;
            }
        }
///////////////////////////////////////////////////////////////
        void viewBoard()
        {
            //BOARD

    std::cout<<"\t\tTic Tac Toe"<<std::endl;
    correctNames();
    std::cout<<"\t        :        :          \n"

               "\t    "<<board[0]<<"   :"
               "    "<<board[1]<<"   :"
               "    "<<board[2]<<"   \n  "

               "\t________:________:________  \n"
               "\t        :        :          \n"

               "\t    "<<board[3]<<"   :"
               "    "<<board[4]<<"   :"
               "    "<<board[5]<<"   \n  "

               "\t________:________:________  \n"
               "\t        :        :          \n"

               "\t    "<<board[6]<<"   :"
               "    "<<board[7]<<"   :"
               "    "<<board[8]<<"     \n"

               "\t        :        :          \n"
               "\t                                                    (*) Enter a number from 1-9 that isn't taken  \n"
               "\t                                                    (*) Enter 10 to exit                          \n\n";
        }
///////////////////////////////////////////////////////////////
    int checkwin()
    //NEEDS WORK
    {
            for(int i = 0; i < 3;i++)
            {

                if(board[i]=='X'&&board[i+3]=='X'&&board[i+6]=='X')
                        return 1;
                    if(board[i]=='O'&&board[i+3]=='O'&&board[i+6]=='O')
                            return 2;
            }
            if(board[0]=='X'&&board[1]=='X'&&board[2]=='X')
                            return 1;
            if(board[3]=='X'&&board[4]=='X'&&board[5]=='X')
                            return 1;
            if(board[6]=='X'&&board[7]=='X'&&board[8]=='X')
                            return 1;
        if(board[0]=='O'&&board[1]=='O'&&board[2]=='O')
                        return 2;
        if(board[3]=='O'&&board[4]=='O'&&board[5]=='O')
                        return 2;
        if(board[6]=='O'&&board[7]=='O'&&board[8]=='O')
                        return 2;
            if(board[0]=='X'&&board[4]=='X'&&board[8]=='X')
                            return 1;
            if(board[2]=='X'&&board[4]=='X'&&board[6]=='X')
                            return 1;

        if(board[0]=='O'&&board[4]=='O'&&board[8]=='O')
                        return 2;
        if(board[2]=='O'&&board[4]=='O'&&board[6]=='O')
                        return 2;

        return 3;
    }
///////////////////////////////////////////////////////////////
    void PlayGame(int &x)
    {
        //GAME BASED ON TURNS

        while(count--)
        {

                if(turn == 0)
                    {
                            std::cout<<"\t"<<player1<<", enter a number: ";
                            turn = 1;
                            std::cin>>number;
                            if((number >= 1 && number <= 9) && board[number-1]!='O' && board[number-1]!='X')
                                {
                                    board[number-1] = 'X';
                                    if(checkwin()==1)
                                    {
                                        WindowsClear();
                                            viewBoard();
                                                winner = 1;
                                        break;
                                    }
                                }

                            else if(number == 10)
                                {
                                    WindowsClear();
                                    x = 0;
                                    break;
                                }
                            else
                                {
                                    turn = 0;
                                    std::cout<<"\a";
                                    count++;
                                }
                    }

                else
                    {

                            std::cout<<"\t"<<player2<<", enter a number: ";
                            turn = 0;
                            std::cin>>number;
                            if((number >= 1 && number <= 9) && board[number-1]!='O' && board[number-1]!='X')
                                {
                                    board[number-1] = 'O';
                                    if(checkwin()==2)
                                    {
                                        WindowsClear();
                                            viewBoard();
                                                winner = 2;
                                        break;
                                    }
                                }
                            else if(number == 10)
                                {
                                    WindowsClear();
                                    x = 0;
                                    break;
                                }
                            else
                                {
                                    turn = 1;
                                    std::cout<<"\a";
                                    count++;
                                }

                    }

            WindowsClear();
            viewBoard();
        }
    }
///////////////////////////////////////////////////////////////
        void PlayersMenu()
        {
            correct = 1;
            while(correct)
            {

                 WindowsClear();
        std::cout<< "\t  ----____________________----  \n"
                    "\t  |                          |  \n"
                    "\t  |                          |  \n"
                    "\t  | ~     Same players?    ~ |  \n"
                    "\t  |                          |  \n"
                    "\t  |         1. Yes           |  \n"
                    "\t  |         2. No            |  \n"
                    "\t  ----____________________----  \n\n\n"
                    "\t             -_-_-               \n"
                    "\t            Choice:";
                                std::cin>>choice;

            if(choice==2)
                    {
                        getnames();
                        correct = 0;
                        again = 1;
                    }
            else if(choice==1)
                    {
                        correct = 0;
                        again = 1;
                    }
            else
                    {
                        std::cout<<"\a";
                        WindowsClear();
                    }
            }
        }
///////////////////////////////////////////////////////////////
        void Winner(int &x)
        {
            if(winner == 3)
            {

              correct = 1;
              while(correct)
                {

                    std::cout<< "\t  ----____________________----  \n\a"
                                "\t  |          [ TIE ]         |  \n"
                                "\t  |                          |  \n"
                                "\t  | ~Thank you for playing!~ |  \n"
                                "\t  |                          |  \n"
                                "\t  |     1. Play again        |  \n"
                                "\t  |     2. Exit              |  \n"
                                "\t  ----____________________----  \n\n\n"
                                "\t             -_-_-               \n"
                                "\t            Choice:";
                                            std::cin>>choice;

            if(choice==1)
                    {
                        PlayersMenu();
                    }
            else if(choice != 2)
                    {
                        std::cout<<"\a";
                        WindowsClear();
                    }
            else
                    {
                        WindowsClear();
                        x = 0;
                        correct = 0;

                    }

            }

        }

        else if(winner == 2)
        {
                correct = 1;
                while(correct)
                    {

                     std::transform(player2.begin(), player2.end(), player2.begin(), toupper);
                     std::cout<< "\t  ----____________________----  \n\a"
                                 "\t  |                          |  \n"

                                 "\t  |"<<std::setw(14)<<player2;
                                         std::cout<<" [ WON ]    |  \n"
                                 "\t  |                          |  \n"
                                 "\t  | ~Thank you for playing!~ |  \n"
                                 "\t  |                          |  \n"
                                 "\t  |   1. Play again          |  \n"
                                 "\t  |   2. Exit                |  \n"
                                 "\t  ----____________________----  \n\n\n"
                                 "\t            -_-_-               \n"
                                 "\t            Choice:";
                                 std::cin>>choice;

                            if(choice==1)
                                    {
                                      PlayersMenu();
                                    }
                            else if(choice != 2)
                                    {
                                        std::cout<<"\a";
                                        WindowsClear();
                                    }
                            else
                                    {
                                        WindowsClear();
                                        x = 0;
                                        correct = 0;

                                    }

                    }

        }
        else
        {
                correct = 1;
                while(correct)
                    {

                     std::transform(player1.begin(), player1.end(), player1.begin(), toupper);
                     std::cout<< "\t  ----____________________----  \n\a"
                                 "\t  |                          |  \n"

                                 "\t  |"<<std::setw(14)<<player1;
                                         std::cout<<" [ WON ]    |  \n"
                                 "\t  |                          |  \n"
                                 "\t  | ~Thank you for playing!~ |  \n"
                                 "\t  |                          |  \n"
                                 "\t  |   1. Play again          |  \n"
                                 "\t  |   2. Exit                |  \n"
                                 "\t  ----____________________----  \n\n\n"
                                 "\t            -_-_-               \n"
                                 "\t            Choice:";
                                 std::cin>>choice;

                            if(choice==1)
                                    {
                                      PlayersMenu();
                                    }
                            else if(choice != 2)
                                    {
                                        std::cout<<"\a";
                                        WindowsClear();
                                    }
                            else
                                    {
                                        WindowsClear();
                                        x = 0;
                                        correct = 0;

                                    }

                        }
                }
        }
///////////////////////////////////////////////////////////////
        bool Again()
        {
            for(int i = 0,j = 49; i < 9; ++i,++j)
                board[i] = j;

            winner = 3;
            count = 9;
            flag = 0;
                            return again;
        }
///////////////////////////////////////////////////////////////
        void WindowsClear()
        {
//Windows API
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
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
    protected:

    private:
        std::string player1{"players"},player2{"player"};
        char board[10] = {'1','2','3','4','5','6','7','8','9'};
        int choice{0},number{0},winner{3},count{9};
        bool turn{0},flag{0},again{0},correct{1};
};

#endif // TICTACTOE_H
