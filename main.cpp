#include"Gameplay.h"

int main()
{
	
	Gameplay *newGame;
	
	newGame = new Gameplay();
	
	int raund_result,press,i=0,random_value;
	
	cout << "Welcome The Ultimate TicTacToe Game..." << endl;
	cout << "Press 1 to play the game...";
	fflush(stdin);
	cin >> press;
	
	if(press == 1)
	{
				
			do{
				
				cout << "\n\n--------------Raund " << i+1 << " --------------\n\n" << endl;
				
				while(1)
				{
					cout << "\n";
					newGame->getTable(i);
					
					
							newGame->playerX(i);
							raund_result = newGame->check_raund_end(i);
				
								if(raund_result == 1)
									break;
							
					cout << "\n";
					newGame->getTable(i);
							
							
							newGame->playerO(i);
							raund_result = newGame->check_raund_end(i);
				
								if(raund_result == 1)
									break;		
				}
				
				cout << "Raund " << i+1 << " is finished " << endl;
				cout << "Winner is " << newGame->getWinner(i);
				
				i++;
				
			}while(i!= 2);
			
			random_value = newGame->generate_Random_num();
			
			if (random_value == 0)
			{
				-(*newGame);
				
				cout << "\n\nFirst Raund Winner is " << newGame->getWinner(0) << endl;
				cout << "Second Raund Winner is " << newGame->getWinner(1) << endl;
				cout << "Selected operation is -" << endl;
				cout << "Winner of the game is " << newGame->getResult() << endl;
				cout << "\n\n\nGood Bye..." << endl;
			}
			
			else
			{
				+(*newGame);
				cout << "First Raund Winner is " << newGame->getWinner(0) << endl;
				cout << "Second Raund Winner is " << newGame->getWinner(1) << endl;
				cout << "Selected operation is +" << endl;
				cout << "Winner of the game is " << newGame->getResult() << endl;
				cout << "\n\n\nGood Bye..." << endl;
			}
				
	}
	
	else
	{
		cout << "\nGood Bye..." << endl;
		return 0;
	}
	
	
	


	return 0;
}
