/* Ömer Faruk Sezen – 2315539
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only */

#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include<iostream>
#include<time.h>
#include<cstdlib>
#include"UltimateTTT.h"
using namespace std;

class Gameplay
{
	private:
		
		UltimateTTT *ultimate[2];
		char result;
		
	
	public:
		
		Gameplay()
		{
			int i;
			
			result = '-';
			
			for(i=0;i<2;i++)
	                {
	                    ultimate[i] = new UltimateTTT();
	                }
			
		}
		
		
		
		void operator+()
		{
			
			if( (this->ultimate[1]->getRaundWinner() == 'X' || this->ultimate[0]->getRaundWinner() == 'X'))
			{
				this->result = 'X';
			}
			
			
			else if((this->ultimate[1]->getRaundWinner() == 'D' || this->ultimate[0]->getRaundWinner() == 'D'))
			{
					if(this->generate_Random_num() == 0)
					{
						this->result = 'O';	
					}
					
					else
					{
						this->result = 'X';
					}
			}
			
			else
			{
				this->result = 'O';
			}
			
		}
		
		
		void operator-()
		{
			
			if( (this->ultimate[1]->getRaundWinner() == 'O' || this->ultimate[0]->getRaundWinner() == 'O'))
			{
				this->result = 'O';
			}
			
			
			else if((this->ultimate[1]->getRaundWinner() == 'D' || this->ultimate[0]->getRaundWinner() == 'D'))
			{
					if(this->generate_Random_num() == 0)
					{
						this->result = 'O';	
					}
					
					else
					{
						this->result = 'X';
					}
			}
			
			else
			{
				this->result = 'X';
			}
			
		}
		
		
		void playerX(int gameRaundNum)
		{
			int row,coloumn,check=0,check_place;
			
			while(check != 1)
			{
			
			cout << "Enter the row number for X: ";
			cin >> row;
			
			cout << "Enter the coloumn number for X: ";
			cin >> coloumn;
			
			check_place = ultimate[gameRaundNum]->checkPlaceIsFull(row,coloumn);
			
			
					if(check_place == 1)
					{
						cout << "\nPlace is Full. Please choose empty places...\n\n";
						check = 0;
					}
					
					else if( row < 1 || row > 9 || coloumn < 1 || coloumn > 9 )
					{
						cout << "\nPlease enter the correct coordinates...\n\n";
						check = 0;
					}
					
					else
					{
						ultimate[gameRaundNum]->move(row,coloumn,'X');
						check = 1;
					}
							
			}

		}
		
		
		void playerO(int gameRaundNum)
		{
			int row,coloumn,check=0,check_place;
			
			while(check != 1)
			{
			
			cout << "Enter the row number for O: ";
			fflush(stdin);
			cin >> row;
			
			cout << "Enter the coloumn number for O: ";
			fflush(stdin);
			cin >> coloumn;
			
			check_place = ultimate[gameRaundNum]->checkPlaceIsFull(row,coloumn);
			
					if( check_place == 1)
					{
						cout << "\nPlace is Full. Please choose empty places...\n\n";
						check = 0;
					}
					
					else if( row < 1 || row > 9 || coloumn < 1 || coloumn > 9 )
					{
						cout << "\nPlease enter the correct coordinates...\n\n";
						check = 0;
					}
					
					else
					{
						ultimate[gameRaundNum]->move(row,coloumn,'O');
						check = 1;
					}
							
			}
			
		}
		
		int generate_Random_num()
		{
			int random;
			
			srand(time(NULL));
			
			random = rand() % 2;
			
			return random;
		}
		
		
		int check_raund_end(int raund_num)
		{
			int winner,draw;
			
			
			winner = this->ultimate[raund_num]->check_big_winner();
			draw = this->ultimate[raund_num]->checkBigDraw();
			
			
				if(winner == 0 || winner == 1 || draw == 1)
				{
					return 1;
				}
				
			
		return 0;	
		}
		
		
		void getTable(int raund_no)
		{
			ultimate[raund_no]->printGameBoard();
		}
		
		
		char getWinner(int raund_no)
		{
			return ultimate[raund_no]->getRaundWinner();
		}
		
		char getResult()
		{
			return this->result;
		}	
};



#endif
