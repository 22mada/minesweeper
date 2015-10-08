#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
class Menu
{
public:
		
	Menu();
	//open file with names and highscores
	//sets choice, length, name and highscore arrays to zero
	// includes all functions

	~Menu();//save names and highscores to file

	bool quitGame();//returns true to quit and false to continue
	bool playTrue();//returns true to play
	void menuDisplay();//Displays menu
	void setNameScore(string, int);// takes in string and number and sets as name and score

private:
	int choice;
	int length;
	string topName[10];
	int topScore[10];
	bool repeat;
	string name;
	int score;
	bool quit;
	bool start;
	
	
	
	void menuChoice();//include play, highPlays, clearScores and quit
	// output "menu choice:" sets choice as input

	void menuHighScore();
	// displays names and scores of 10 highest scoring games

	void menuClearScores();
	// clears names and scores of 10 highest scoring games

	void startPlay();
	// sets start to true
	void menuQuit();
	// ends game by returning true

	void sortScore();
	//puts score and in correct array place
};

