// Program: connect 4 which means that who connect 4 of his symbol first, so he is the winner 
//          he can connect diagonally or horizontally or vertically


// Author:  fatema elzhraa ahmed mohamed elfiky and ID:20230280


// Version: version 5


// Date:  29/2/2024
#include <iostream>
#include <cctype>
#include <vector>
#include<string>
using namespace std;
//validation function for the input of the characters
string string2Validation(string player)
{
	
	while (player != "X" && player != "O" && player != "x" && player != "o")
	{
		cout << "enter a valid symbol\n";
		cin >> player;
		
	}
	return player;
}

int main()
{
	//game data
	string arr[6][7];//the body of the game
	string column;
	cout << "welcome to the connect for game" << endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			arr[i][j] = "#";
		}
	}
	for (int i = 0; i < 6; i++)//the body of the game printing
	{
		cout << i + 1;
		for (int j = 0; j < 7; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
	cout << " 1234567\n";
	//player1 and 2 are going to choose the characters to play with + their validations
	cout << "player1: choose X or O: ";
	string player1char, player2char;
	cin >> player1char;
	player1char= string2Validation(player1char);
	player1char = toupper(player1char[0]);
	cout << "player2: choose X or O: ";
	cin >> player2char;
	player2char = string2Validation(player2char);
	player2char = toupper(player2char[0]);
	//this part for player2 to check  player2 didn't choose the same symbol
	while (player2char == player1char)
	{
		cout << "enter a different symbol,pls\n";
		cin >> player2char;
		player2char = string2Validation(player2char);
		player2char = toupper(player2char[0]);
	}
	while (true)//the game starts
	{
		cout << "enter the column number,player1: ";
		cin >> column;
		vector<string>columnsnumbers = {"1","2","3","4","5","6","7"};
		while (true)//validate the number of column entered 
		{
			bool valid = false;
			for (int i = 0; i < 7; i++)
			{
				if (column == columnsnumbers[i])
				{
					valid = true;
					break;
				}
			}
			if (valid)
			{
				break;
			}
			cout << "enter a valid num\n";
			cin >> column;
		}
		for (int i = 5; i >= 0; i--)//to  fall the coin of the game into the bottom of the game
		{
			if (arr[i][stoi(column) - 1] == "#")
			{
				arr[i][stoi(column) - 1] = player1char;
				break;
			}
		}
		for (int i = 0; i < 6; i++)//to print game animation after putting the coin
		{
			cout << i + 1;
			for (int j = 0; j < 7; j++)
			{
				cout << arr[i][j];
			}
			cout << endl;
		}
		cout << " 1234567\n";
		//the idea of the game
		bool winner = false;
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 7; j++)/**/
			{
				if (arr[i][j] != "#")
				{
					if (j < 4)//the width part to validate if he wins horizontally or not
					{
						if (arr[i][j] == player1char && arr[i][j + 1] == player1char && arr[i][j + 2] == player1char && arr[i][j + 3] == player1char)
						{
							winner = true;
							cout << "player1 is the winner" << endl;
							break;

						}
					}
					else
					{
						if (arr[i][j] == player1char && arr[i][j - 1] == player1char && arr[i][j - 2] == player1char && arr[i][j - 3] == player1char)
						{
							winner = true;
							cout << "player1 is the winner" << endl;
							break;

						}
					}
					if (i < 3)//the vertical part to validate if he wins vertically or not
					{
						if (arr[i][j] == player1char && arr[i + 1][j] == player1char && arr[i + 2][j] == player1char && arr[i + 3][j] == player1char)
						{
							winner = true;
							cout << "player1 is the winner" << endl;
							break;

						}
					}
					else
					{
						if (arr[i][j] == player1char && arr[i - 1][j] == player1char && arr[i - 2][j] == player1char && arr[i - 3][j] == player1char)
						{
							winner = true;
							cout << "player1 is the winner" << endl;
							break;

						}
					}
					if (i - 3 >= 0 || j - 3 >= 0)//the principle diagonal part to validate if he wins diagonally or not
					{
						if (arr[i][j] == player1char && arr[i - 1][j - 1] == player1char && arr[i - 2][j - 2] == player1char && arr[i - 3][j - 3] == player1char)
						{
							winner = true;
							cout << "player1 is the winner" << endl;
							break;
						}
					}
					if (i>=3 && j<4)//the off diagonal part to validate if he wins diagonally or not
					{
						if (arr[i][j] == player1char && arr[i - 1][j + 1] == player1char && arr[i - 2][j + 2] == player1char && arr[i - 3][j + 3] == player1char)
						{
							winner = true;
							cout << "player1 is the winner" << endl;
							break;
						}
					}


				}
			}
			if (winner)
			{
				break;
			}
		}
		if (winner)
		{
			break;
		}
		bool StillPlaying = false;// this part to see if there is no any # ,so we are about to end the game 
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (arr[i][j] == "#")
				{
					StillPlaying = true;
					break;
				}
			}
			if (StillPlaying)
			{
				break;
			}
		}
		if (StillPlaying == false && winner == false)// if we are going about to finish the game and no one acheived the criteria of win, so the result is draw  
		{
			cout << "draw\n";
			break;
		}
		cout << "enter the column number,player2: ";
		cin >> column;
		while (true)// validate the columns
		{
			bool valid = false;
			for (int i = 0; i < 7; i++)
			{
				if (column == columnsnumbers[i])
				{
					valid = true;
					break;
				}
			}
			if (valid)
			{
				break;
			}
			cout << "enter a valid num\n";
			cin >> column;
		}
		for (int i = 5; i >= 0; i--)//placing the coin in the game 
		{
			if (arr[i][stoi(column) - 1] == "#")
			{
				arr[i][stoi(column) - 1] = player2char;
				break;
			}
		}
		for (int i = 0; i < 6; i++)//printing the board game after changes 
		{
			cout << i + 1;
			for (int j = 0; j < 7; j++)
			{
				cout << arr[i][j];
			}
			cout << endl;
		}
		cout << " 1234567\n";
		//the idea of the game
		bool winner2 = false;
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (arr[i][j] != "#")
				{
					if (j < 4)//the width part to see wether the user wins horizontally or not
					{
						if (arr[i][j] == player2char && arr[i][j + 1] == player2char && arr[i][j + 2] == player2char && arr[i][j + 3] == player2char)
						{
							winner2 = true;
							cout << "player2 is the winner" << endl;
							break;

						}
					}
					else
					{
						if (arr[i][j] == player2char && arr[i][j - 1] == player2char && arr[i][j - 2] == player2char && arr[i][j - 3] == player2char)
						{
							winner2 = true;
							cout << "player2 is the winner" << endl;
							break;

						}
					}
					if (i < 3)//the vertical part to see wether the user wins vertically or not
					{
						if (arr[i][j] == player2char && arr[i + 1][j] == player2char && arr[i + 2][j] == player2char && arr[i + 3][j] == player2char)
						{
							winner2 = true;
							cout << "player2 is the winner" << endl;
							break;

						}
					}
					else
					{
						if (arr[i][j] == player2char && arr[i - 1][j] == player2char && arr[i - 2][j] == player2char && arr[i - 3][j] == player2char)
						{
							winner2 = true;
							cout << "player2 is the winner" << endl;
							break;

						}
					}
					if (i - 3 >= 0 && j - 3 >= 0)//the principle diagonal part to see wether the user wins diagonaly or not
					{
						if (arr[i][j] == player2char && arr[i - 1][j - 1] == player2char && arr[i - 2][j - 2] == player2char && arr[i - 3][j - 3] == player2char)
						{
							winner2 = true;
							cout << "player2 is the winner" << endl;
							break;
						}
					}
					if (i >= 3 && j < 4)//the off diagonal part to see wether the user wins diagonaly or not
					{
						if (arr[i][j] == player2char && arr[i - 1][j + 1] == player2char && arr[i - 2][j + 2] == player2char && arr[i - 3][j + 3] == player2char)
						{
							winner2 = true;
							cout << "player2 is the winner" << endl;
							break;
						}
					}


				}
			}
			if (winner2)
			{
				break;
			}
		}
		if (winner2)
		{
			break;
		}
	    StillPlaying = false;
		for (int i = 0; i < 6; i++)// to check if the game is about to be done or not 
		{
			for (int j = 0; j < 7; j++)
			{
				if (arr[i][j] == "#")
				{
					StillPlaying = true;
					break;
				}
			}
			if (StillPlaying)
			{
				break;
			}
		}
		if (StillPlaying == false && winner == false&&winner2==false)// if the game is about to be done and the 2 players didn't achieve the criteria of win , so print draw
		{
			cout << "draw\n";
			break;
		}

	}
}

