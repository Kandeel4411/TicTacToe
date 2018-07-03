#ifndef TICTACTOE_H
#define TICTACTOE_H


class TicTacToe
{
    public:
        TicTacToe(int &x)
        {

        while(correct)
            {

        std::cout<<"\t----____________________----\n\t|\t  [Welcome]\t   |\n\t|\t\t\t   |\n\t|   ~~   Tic-Tac-Toe  ~~   |\n\t|\t\t\t   |\n\t|\t  1. Play          |\n\t|\t  2. Exit          |\n\t----____________________----\n\n\n\t\t-_-_-\n\t\tChoice:";std::cin>>choice;

        if(choice==1)
                {
                    getnames();
                    correct = 0;
                }
        else if(choice != 2)
                {
                    ClearScreen();
                    std::cout<<"Wrong option number! Try again"<<std::endl;
                    ClearScreen();
                }
        else
                {
                    ClearScreen();
                    x = 0;
                    correct = 0;

                }

            }
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

        void getnames()
        {
            ClearScreen();
            std::cout<<"\n\n\t\t(*) Enter Player1 -<X> name: ";
                std::cin>>player1;
                    std::cout<<"\t\t(*) Enter Player2 -<O> name: ";
                        std::cin>>player2;

        }

        void viewBoard()
        {

    std::cout<<"\t\tTic Tac Toe"<<std::endl;
        std::transform(player1.begin(), player1.end(), player1.begin(), tolower);
            std::transform(player2.begin(), player2.end(), player2.begin(), tolower);

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

    std::cout<<"\t\t:\t:"<<std::endl;
        std::cout<<"\t"<<std::setw(4)<<board[0]<<"\t:"<<std::setw(4)<<board[1]<<"\t:"<<std::setw(4)<<board[2]<<std::endl;
            std::cout<<"\t"<<std::setfill('_')<<std::setw(8)<<"_"<<":"<<std::setfill('_')<<std::setw(7)<<"_"<<":"<<std::setfill('_')<<std::setw(8)<<""<<std::endl;
            std::cout<<"\t\t:\t:"<<std::endl;
    std::cout<<"\t"<<std::setfill(' ')<<std::setw(4)<<board[3]<<"\t:"<<std::setw(4)<<board[4]<<"\t:"<<std::setw(4)<<board[5]<<std::endl;
        std::cout<<"\t"<<std::setfill('_')<<std::setw(8)<<"_"<<":"<<std::setfill('_')<<std::setw(7)<<"_"<<":"<<std::setfill('_')<<std::setw(8)<<"_"<<std::endl;
            std::cout<<"\t\t:\t:"<<std::endl;
    std::cout<<"\t"<<std::setfill(' ')<<std::setw(4)<<board[6]<<"\t:"<<std::setw(4)<<board[7]<<"\t:"<<std::setw(4)<<board[8]<<std::endl;
        std::cout<<"\t\t:\t:"<<std::endl<<std::endl;
            std::cout<<"\t\t\t\t\t\t\t (*) Enter a number from 1-9 that isn't taken"<<std::endl;
            std::cout<<"\t\t\t\t\t\t\t (*) Enter 10 to exit"<<std::endl<<std::endl;
        }

    int checkwin()
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
    void PlayGame(int &x)
    {
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
                                                ClearScreen();
                                                    viewBoard();
                                                        winner = 1;
                                                break;
                                            }
                                        }

                                    else if(number == 10)
                                        {
                                            ClearScreen();
                                            x = 0;
                                            break;
                                        }
                                    else
                                        {
                                            turn = 0;
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
                                                ClearScreen();
                                                    viewBoard();
                                                        winner = 2;
                                                break;
                                            }
                                        }
                                    else if(number == 10)
                                        {
                                            ClearScreen();
                                            x = 0;
                                            break;
                                        }
                                    else
                                        {
                                            turn = 1;
                                            count++;
                                        }

                            }

                    ClearScreen();
                    viewBoard();
                }
        }

        void Winner(int &x)
        {
            if(winner == 3)
            {

                  correct = 1;
                        while(correct)
                        {

                            std::cout<<"\t----____________________----\n\t|\t   [ TIE ] \t   |\n\t|\t\t\t   |\n\t| ~Thank you for playing!~ |\n\t|\t\t\t   |\n\t|\t  1. Play again    |\n\t|\t  2. Exit          |\n\t----____________________----\n\n\n\t\t-_-_-\n\t\tChoice:";std::cin>>choice;

                                        if(choice==1)
                                                {
                                                    ClearScreen();
                                                    std::cout<<"\t----____________________----\n\t|\tSame players?\t   |\n\t|\t  1. Yes           |\n\t|\t  2. No            |\n\t----____________________----\n\n\n\t\t-_-_-\n\t\tChoice:";std::cin>>choice;
                                                    if(choice==2)
                                                    getnames();
                                                    correct = 0;
                                                    again = 1;

                                                }
                                        else if(choice != 2)
                                                {
                                                    ClearScreen();
                                                    std::cout<<"Wrong option number! Try again"<<std::endl;
                                                    ClearScreen();
                                                }
                                        else
                                                {
                                                    ClearScreen();
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

                                         std::cout<<"\t----____________________----\n\t|\t";
                                         std::transform(player2.begin(), player2.end(), player2.begin(), toupper);
                                         std::cout<<player2<<"   [ WON ] \t   |\n\t|\t\t\t   |\n\t| ~Thank you for playing!~ |\n\t|\t\t\t   |\n\t|\t  1. Play again    |\n\t|\t  2. Exit          |\n\t----____________________----\n\n\n\t\t-_-_-\n\t\tChoice:";std::cin>>choice;

                                                if(choice==1)
                                                        {
                                                            ClearScreen();
                                                            std::cout<<"\t----____________________----\n\t|\tSame players?\t   |\n\t|\t  1. Yes           |\n\t|\t  2. No            |\n\t----____________________----\n\n\n\t\t-_-_-\n\t\tChoice:";std::cin>>choice;
                                                            if(choice==2)
                                                            getnames();
                                                            correct = 0;
                                                            again = 1;

                                                        }
                                                else if(choice != 2)
                                                        {
                                                            ClearScreen();
                                                            std::cout<<"Wrong option number! Try again"<<std::endl;
                                                            ClearScreen();
                                                        }
                                                else
                                                        {
                                                            ClearScreen();
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
                                                     std::cout<<"\t----____________________----\n\t|\t";
                                                     std::transform(player1.begin(), player1.end(), player1.begin(), toupper);
                                                     std::cout<<player1<<"   [ WON ] \t   |\n\t|\t\t\t   |\n\t| ~Thank you for playing!~ |\n\t|\t\t\t   |\n\t|\t  1. Play again    |\n\t|\t  2. Exit          |\n\t----____________________----\n\n\n\t\t-_-_-\n\t\tChoice:";std::cin>>choice;

                                                        if(choice==1)
                                                                {
                                                                    ClearScreen();
                                                                    std::cout<<"\t----____________________----\n\t|\tSame players?\t   |\n\t|\t  1. Yes           |\n\t|\t  2. No            |\n\t----____________________----\n\n\n\t\t-_-_-\n\t\tChoice:";std::cin>>choice;
                                                                    if(choice==2)
                                                                    getnames();
                                                                    correct = 0;
                                                                    again = 1;

                                                                }
                                                        else if(choice != 2)
                                                                {
                                                                    ClearScreen();
                                                                    std::cout<<"Wrong option number! Try again"<<std::endl;
                                                                    ClearScreen();
                                                                }
                                                        else
                                                                {
                                                                    ClearScreen();
                                                                    x = 0;
                                                                    correct = 0;

                                                                }

                                                    }
            }
        }



        bool Again()
        {
            for(int i = 0,j = 49; i < 9; ++i,++j)
                board[i] = j;

            choice = 0;
                number = 0;
                    winner = 3;
                            count = 9;
                    turn = 0;
                flag = 0;
            correct = 1;
                            return again;
        }

    protected:

    private:
        std::string player1{"players"},player2{"player"};
        char board[10] = {'1','2','3','4','5','6','7','8','9'};
        int choice{0},number{0},winner{3},count{9};
        bool turn{0},flag{0},again{0},correct{1};
};

#endif // TICTACTOE_H
