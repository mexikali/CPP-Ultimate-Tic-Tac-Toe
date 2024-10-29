/* Ömer Faruk Sezen – 2315539
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only */

#ifndef TICTACTOE_H
#define TICTACTOE_H
#include<iostream>
#include<time.h>
#include<cstdlib>
using namespace std;

class TicTacToe
{
    private:

        char board[3][3];
        char board_winner;

    public:

        TicTacToe()
        {
            int i,j;

            board_winner = '-';

            for(i=0;i<3;i++)
            {
                for(j=0;j<3;j++)
                {
                    board[i][j] = '-';
                }
            }
        }
        
        
        void operator!()
        {
			int i,j,x_val=0,y_val=0,counter=1;
        	
        	for(i=0;i<3;i++)
        	{
        		for(j=0;j<3;j++)
        		{
        			if ((board[i][j]) == 'X')
        			{
        				x_val += counter;
        				++counter;
					}
					
					else if ((board[i][j]) == 'O')
					{
						y_val += counter;
						++counter; 
					}
				}
			}
			
			
			if(x_val > y_val)
			{
				this->board_winner = 'X';
			}
			
			else if(y_val > x_val)
			{
				this->board_winner = 'O';	
			}
		}

        
		
		void printline(int i)
        {
            int j;

                for(j=0;j<3;j++)
                {
                    cout << board[i][j] << " ";
                }
				
                //cout << "\n";
            
        }
		
		
		
		char getChar(int i, int j)	// i is row number and j is coloumn number
		{
			return board[i][j];
		}
		
		
		
		void setChar(int i, int j,char move)
		{
			board[i][j] = move;
		}
		
		
		char getWinner(void)
		{
			return board_winner;
		}
		
		
		int getNumberOfMove(void)
		{
			int i,j,counter=0;
			
			for(i=0;i<3;i++)
			{
					
					for(j=0;j<3;j++)
					{
							if(board[i][j] == 'X' || board[i][j] == 'O')
							{
								counter++;
							}
					}
					
			}
			
			return counter;
		}
		
		
		
		
		int check_Winner(void)
		{
			int i;
			
				for(i=0;i<3;i++)  // checks row and coloumn
				{
					
						if( (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X') || (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') )
						{
							this->board_winner = 'X';
							return 1;
						}
						
						else if( (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O') || (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O') )
						{
							this->board_winner = 'O';
							return 0;
						}
				
				}
				
				// checks diagonal
				
				if( ( board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X' ) || ( board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X' ) )
				{
					this->board_winner = 'X';
					return 1;
				}
					
				
				else if( ( board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O' ) || ( board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O' ) )
				{
					this->board_winner = 'O';
					return 0;
				}
				
								
				
			return -1;	//if there is no winner it returns -1
		}
		
		
		int check_draw(void)
		{
			
				if(this->check_Winner() == -1 && this->getNumberOfMove() == 9)
				{
					return 1;
				}
				
				else
				{
					return 0;
				}
			
		}
		
		
		void printBoard(void)
		{
			int i,j;
			
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					cout << board[i][j] << " ";
				}
				
				cout << "\n";
			}
		}
};

#endif
