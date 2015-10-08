#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
class Play{ //:public Menu{
public: 
	Play();// sets repeat loop to true
	~Play();//outputs name and score
	bool playTrue();//returns true to play
	string setName();//returns name
	int setScore();//returns score
		
private:
	string name;
	int score;
	int length;
	int store[10][10];
	bool select[10][10];
	char display[10][10];
	bool bomb, number, zero;
	bool game_over;
	int moveI, moveJ;
	int bombI, bombJ;
	char pickRow;
	int pickColumn;
	bool start;

	void setBoard();
	//sets mine location in store matrix with random row and columnn numbers
	//

	void proximity(int val1, int val2);
	//moves right through matarix looking for val1
	//and adds val2 to location around val1 

	void displayBoard();
	//outputs board to screen 
	//displays store[] if select[] is true and display is select is false
	
	void setMove();
	//take in two integers and sets them as row and column 

	void moveCheck();
	// checks store[row, column] 
	//for three conditions 1)bomb 2)number 3) zero sets each to T/F

	void calculate();
	//checks if bomb condition true
	//outpouts game over sets score numbers of trues in select[]
	//sets bool select[row, column] to  true
	//sets string display[row, column] to "X"
	//display board
			
	void checkWinner();
	//checks for win
	//checks select[] number of False = number of bombs and bomb locations = False 
	// adds 100 bonus to score
	// outputs Congratulations you win 
	bool getGame_over();
	//retrieves game_over bool
};

