#include "Menu.h"
#include "Play.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
Menu::Menu(){
	//set variables to default
	choice=0;
	quit= false;
	start= false;
	length = 10;
	repeat = true;
	name = " ";
	score = 0;
	for(int i =0; i< length; i++)//change this input from file
	{
		topName[i]= "";
		topScore[i]=0;
	}
}




Menu::~Menu(){
	cout<<"Thank you for playing Mine Sweeper"<< endl;
	}

bool Menu::quitGame(){
	return quit;
}

bool Menu::playTrue(){
	return start;
}
void Menu::setNameScore(string n, int num){
	name = n;
	score = num;
	}

void Menu::menuDisplay(){
	sortScore();
	start=false;
	cout<<"  ***************************************"<< endl;
	cout<<"  *                                     *"<< endl;
	cout<<"  *           Mine Sweeper              *"<< endl;
	cout<<"  *                                     *"<< endl;
	cout<<"  ***************************************"<< endl;
	cout<<"  *                                     *"<< endl;
	cout<<"  *       1)  Play Game                 *"<< endl;
	cout<<"  *       2)  High Scores               *"<< endl;
	cout<<"  *       3)  Clear Scores              *"<< endl;
	cout<<"  *       4)  Quit                      *"<< endl;
	cout<<"  *                                     *"<< endl;
	cout<<"  ***************************************"<< endl;
	cout<<endl;
	menuChoice();
}
	
	void Menu::menuChoice(){
	// output "menu choice:" sets choice as input
	cout<<"Enter choice and press return:";  
	cin>> choice;

	switch (choice)
	{
	case 1:
		startPlay();
		break;
	case 2: 
		menuHighScore();
		break;
	case 3:
		menuClearScores();
		break;
	case 4:
		menuQuit();
		break;
	default:
		cout << "That is an invalid choice.  Please enter a number from the menu and press enter.(ex. 1)"<<endl;
		
	}
	}

	void Menu::menuHighScore(){
	// displays names and scores of 10 highest scoring games
		cout<<"**************************************"<<endl;
		cout<<"              High Scores             "<<endl;
		cout<<"**************************************"<<endl;
		cout<< endl;
		for(int i=0; i<length; i++){
			cout<<"     "<< i+1  <<") "<< topName[i]<<"             "<< topScore[i]<<endl;
		}
		cout<<"**************************************"<<endl;
		
	char x='c';	
	cout<<"Press and key and Enter to Continue";
	cin>> x;
	
	}

	void Menu::menuClearScores(){
	// clears names and scores of 10 highest scoring games
	name=  " ";
	score= 0;

		for(int i=0; i< length; i++){
			topName[i]="";
			topScore[i]= 0;
		}
		cout<<"Scores cleared\n";
	char x='c';	
	cout<<"Press any key and Enter to Continue";
	cin>> x;
	}

	void Menu::menuQuit(){
	quit= true;
	// precondition while loop while true;
	}
	
	void Menu::startPlay(){
		start= true;
	}

	void Menu::sortScore(){
		string tempName= name;
		int tempNum= score;
		
		for(int i=0; i< length; i++){
			score= tempNum;
			name= tempName;
			if(score> topScore[i]){
				tempName=topName[i];
				topName[i]= name;
				tempNum= topScore[i];
				topScore[i]= score;
			}
		}
	}