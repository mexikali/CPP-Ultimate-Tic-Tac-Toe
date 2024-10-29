/* Ömer Faruk Sezen – 2315539
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only */

#ifndef ULTIMATETTT_H
#define ULTIMATETTT_H
#include<iostream>
#include<time.h>
#include<cstdlib>
#include"TicTacToe.h"
using namespace std;

class UltimateTTT
{
    private:

        TicTacToe *gameboard[9];
        char round_winner;



    public:

	        UltimateTTT()
	        {
	            int i;
	
	            round_winner = '-';
	
	                for(i=0;i<9;i++)
	                {
	                    gameboard[i] = new TicTacToe();
	                }
	            
	        } 


	        void printGameBoard(void)
	        {
	            int i,j,k,line=1;
	            
	            cout << "    1 2 3  4 5 6  7 8 9\n" << endl;
	
	                for(i=0;i<9;i+=3)
	                {
	                    for(k=0;k<3;k++)
	                    {
	                    	cout << line << "   ";
	                    	line += 1;
	                    	
							for(j=i;j<i+3;j++)
	                    	{
	                    		gameboard[j]->printline(k);
	                    		cout << " ";
							}
							cout << "\n";
						}
						
	
	                        cout << "\n";
	                }
	         
	        }
	        
	        
	        int findBoardNumber(int i,int j)	//i row --- j coloumn 
	        {
	        	i--;
	        	j--;
	        	
	        	i = i / 3;
	        	j = j / 3;
	        	
	        	return (3*i) + j + 1;
	        	
			}
			
			
			int checkPlaceIsFull(int i,int j)
			{
				
				int board,x,y;
				
				board = findBoardNumber(i,j);
				
				x= findSmallTableLocation(i);
				y= findSmallTableLocation(j);
				
			//	cout << "X: " << x << " Y: " << y << endl; 
				
				if(gameboard[board-1]->getChar(x,y) == 'X' || gameboard[board-1]->getChar(x,y) == 'O')
					return 1;
				else
					return 0;
					
			}
			
			
			int findSmallTableLocation(int i)
			{
					
					if (i == 1 || i == 4 || i == 7)
					{
						return 0;
					}
					
					else if (i == 2 || i == 5 || i == 8)
					{
						return 1;
					}
					
					else
					{
						return 2;
					}
					
			}
			
			
			char getRaundWinner()
			{
				return round_winner;
			}
			
			
			void move(int i, int j,char player)
			{
				int board_no;
				
				board_no = findBoardNumber(i,j) - 1;
				
				
				gameboard[board_no]->setChar(findSmallTableLocation(i),findSmallTableLocation(j),player);
			}
			
			
			int check_big_winner(void)
			{
				int i;
			
				this->check_small_winner();
			
				for(i=0;i<3;i++)  // checks coloumn
				{
					
						if( (gameboard[i]->getWinner() == 'X' && gameboard[i+3]->getWinner() == 'X' && gameboard[i+6]->getWinner() == 'X') )
						{
							this->round_winner = 'X';
							return 1;
						}
						
						else if( (gameboard[i]->getWinner() == 'O' && gameboard[i+3]->getWinner() == 'O' && gameboard[i+6]->getWinner() == 'O') )
						{
							this->round_winner = 'O';
							return 0;
						}
				
				}
				
				
				for(i=0;i<9;i+=3)  // checks row
				{
					
						if( (gameboard[i]->getWinner() == 'X' && gameboard[i+1]->getWinner() == 'X' && gameboard[i+2]->getWinner() == 'X') )
						{
							this->round_winner = 'X';
							return 1;
						}
						
						else if( (gameboard[i]->getWinner() == 'O' && gameboard[i+1]->getWinner() == 'O' && gameboard[i+2]->getWinner() == 'O') )
						{
							this->round_winner = 'O';
							return 0;
						}
				
				}
				
				
				// checks diagonal
				
				if( ( gameboard[0]->getWinner() == 'X' && gameboard[4]->getWinner() == 'X' && gameboard[8]->getWinner() == 'X' ) || ( gameboard[2]->getWinner() == 'X' && gameboard[4]->getWinner() == 'X' && gameboard[6]->getWinner() == 'X' ) )
				{
					this->round_winner = 'X';
					return 1;
				}
					
				
				else if( ( gameboard[0]->getWinner() == 'O' && gameboard[4]->getWinner() == 'O' && gameboard[8]->getWinner() == 'O' ) || ( gameboard[2]->getWinner() == 'O' && gameboard[4]->getWinner() == 'O' && gameboard[6]->getWinner() == 'O' ) )
				{
					this->round_winner = 'O';
					return 0;
				}
				
								
				
			return -1;	//if there is no winner it returns -1
		}
		
		
		int checkBigDraw()
		{
			int i,total_move=0;
			
			for(i=0;i<9;i++)
			{
				total_move += gameboard[i]->getNumberOfMove();
			}
			
			
			
			if(this->check_big_winner() == -1 && total_move == 81)
				{
					this->round_winner = 'D';
					return 1;
				}
		
		return 0;		
		}
		
		void check_small_winner()
		{
			int i=0,small_table_result,small_table_draw;
			
			for(i=0;i<9;i++)
			{
				small_table_result = gameboard[i]->check_Winner();
				small_table_draw = gameboard[i]->check_draw();
				
					if(small_table_draw == 1)
					{
						!(*gameboard[i]);
					}
			
			
			}
			cout << "\n\n";
		}
			
			
			
};


#endif
