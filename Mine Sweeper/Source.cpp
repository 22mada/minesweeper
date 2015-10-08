// Name:		Mine Sweeper - Final Project C++
//Purpose:		Find all the mines without blowing up!
//Programmer:	Sarah Daugherty on April 23, 2014

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Menu.h"
#include "Play.h"

using namespace std;


int main(){
	//declare variables
	bool quit= false;
	bool start= false;
	string val1= " ";
	int val2= 0;
	Menu menu1;
	//make loop while repeat = true;
	while (quit==false){
			menu1.menuDisplay();//displays menu
			quit= menu1.quitGame();//checks to see if quit game selected
			start= menu1.playTrue();//checks to see if play game selected
		while(start==true){
			Play play1;//starts game
			val1=play1.setName();//gets name 
			val2=play1.setScore();//gets score
			menu1.setNameScore(val1, val2);// score in menu class
			start= play1.playTrue();//sets to false
		}
		start=false;
	
}
	return 0;
}
	
	
	