#include "Play.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
Play::Play()
{
bomb=false;
zero=false;
number=false;
game_over=false;
moveI=0;
moveJ=0;
length=6; 
name= " ";
score= 0;

for(int i=0; i<10; i++){
	 for(int j=0; j<10; j++){
			store[i][j] = 0;
			select[i][j] = false;
			display[i][j] = ' ';
	 }
		}
	cout<< " What is your name?"<< endl;
		cin>> name;

	//step 1.  set board
		setBoard();
	//step 2. display board (loop next steps until winner or loser)
		while(game_over ==false){
			displayBoard();
	//step 3. get move 
			setMove();
	//step 4. check move for win or lose;
			moveCheck();
			//includes calculate() and checkWinner()
			// returns true if win or lose

}
		}

Play::~Play()
{
	cout<<"Name: "<< name << "Score: " << score<< endl;
}

string Play::setName(){
	return name;
}

int Play::setScore(){
	return score;
}

void Play::setBoard(){//step 1
		//fills store matrix with numbers based on proximity to bombs
		// create 3 random bomb locations in store[][]
		srand(time(0));
		for (int i=0; i<length-3; i++){
		bombI = rand()%5;
		bombJ = rand()%5;
		store[bombI][bombJ]= 10;
		}
		// populate store[][] with numbers based on how many bombs square is next to.
		proximity(10,1);

	}

void Play::displayBoard(){//step 2
	//outputs board to screen 
	//displays display[] if select[] is true
				 
		cout<< "Score: "<< score<<endl;
		cout<<"\tA\t\tB\t\tC\t\tD\t\tE"<<endl;
		cout<<" ------------------------------------------------------------------------------"<<endl;
		for(int i=0; i<length-1; i++){
			cout<< i+1;
		 for(int j=0; j<length-1; j++){
			if(select[i][j]==true) 
				cout<< "\t"<<store[i][j];
			else
				cout<< "\t"<<display[i][j];
		if (j< length-2)
			cout<<"\t|" ;
	}
		 cout<<endl<<" ------------------------------------------------------------------------------"<<endl;
		}
		

	}

void Play::setMove(){//step 3
			
	int temp = 0;
	bomb = false;
	zero = false;
	number = false;
	moveI=0;
	moveJ=0;
	pickRow=' ';
	pickColumn=0;

	cout<<name<<  " make your move.\n Pick a letter then a number and press enter:";
	cin>> pickRow>> pickColumn;
			
	switch (pickRow){
		case 'A': 
		case 'a':
			moveJ=0;
			break;
		case 'B':
		case 'b':
			moveJ=1;
			break;
		case 'C':
		case 'c': 
			moveJ=2;
			break;
		case 'D':
		case 'd':
			moveJ=3;
			break;
		case 'E':
		case 'e':
			moveJ=4;
			break;
		default:
			cout<<"Invalid entry please enter a letter between A-D.\n";
				setMove();
			}

	temp= pickColumn;
	cout<<temp;
	if (temp>5 || temp<1){
		cout<<"Invalid entry please enter a number between 1-5.\n";
		setMove();
			}
	else{
		moveI=temp-1;
		
			}
			
			
	}

void Play::moveCheck(){// step 4
	if (store[moveI][moveJ]==10)
			bomb=true;
	if (store[moveI][moveJ]==0)
			zero=true;
	if (store[moveI][moveJ]>0 && store[moveI][moveJ]<10)
		number= true;

		score+=20;
		calculate();
		checkWinner();


	}
void Play::proximity(int val1, int val2){
		int cond = val1;
		int val = val2;

		for(int i=0; i<length; i++){
		 for(int j=0; j<length; j++){
			if (store[i][j]== cond){
				if(i+1 <= length){
					if(store[i+1][j]!=cond)
						store[i+1][j]+=val;}
				if(j+1 <= length){
					if (store[i][j+1]!=cond)
						store[i][j+1] +=val;}
				if(i-1 >=0){
					if(store[i-1][j]!=cond)
						store[i-1][j] += val;}
				if(j-1 >=0){
					if(store[i][j-1]!=cond)
						store[i][j-1] += val;}
				if(i+1 <= length && j+1 <= length){
					if(store[i+1][j+1]!=cond)
						store[i+1][j+1] += val;}
				if(i+1 <= length && j-1 >= 0){
					if (store[i+1][j-1]!=cond)
						store[i+1][j-1] += val;}
				if(i-1 >= 0 && j+1 <= length){
					if(store[i-1][j+1]!=cond)
						store[i-1][j+1] += val;}
				if(i-1 >=0 && j-1 >=0){
					if(store[i-1][j-1]!=cond)
						store[i-1][j-1] += val;}
		 }
		}
	}
	}

// Steps support functions
	void Play::calculate(){
	if (bomb == true){
		display[moveI][moveJ]='X';
		cout<<"Boom!\n Game over\n";
		displayBoard();
		game_over=true;
		
	}
	if (number ==true){
		select[moveI][moveJ]=true;
	}
	
	if(zero==true){
		select[moveI][moveJ]=true;
		for(int i=moveI; i<length; i++){
		 for(int j=moveJ; j<length; j++){
			if (store[i][j]== 0){
				select[i][j]=true;
				if(i+1 <= length){
					select[i+1][j]=true;}
				if(j+1 <= length){
					select[i][j+1] =true;}
				if(i-1 >=0){
					select[i-1][j] = true;}
				if(j-1 >=0){
					select[i][j-1] = true;}
				if(i+1 <= length && j+1 <= length){
					select[i+1][j+1] = true;}
				if(i+1 <= length && j-1 >= 0){
					select[i+1][j-1] = true;}
				if(i-1 >= 0 && j+1 <= length){
					select[i-1][j+1] = true;}
				if(i-1 >=0 && j-1 >=0){
					select[i-1][j-1] = true;}
		 }
		}
	}

	for(int i=moveI; i>0; i--){
		 for(int j=moveJ; j>0; j--){
			if (store[i][j]== 0){
				select[i][j]=true;
				if(i+1 <= length){
					select[i+1][j]=true;}
				if(j+1 <= length){
					select[i][j+1] =true;}
				if(i-1 >=0){
					select[i-1][j] = true;}
				if(j-1 >=0){
					select[i][j-1] = true;}
				if(i+1 <= length && j+1 <= length){
					select[i+1][j+1] = true;}
				if(i+1 <= length && j-1 >= 0){
					select[i+1][j-1] = true;}
				if(i-1 >= 0 && j+1 <= length){
					select[i-1][j+1] = true;}
				if(i-1 >=0 && j-1 >=0){
					select[i-1][j-1] = true;}
		 }
		}
	
	}
		}
	}
		
	bool Play::playTrue(){
		start= false;
		return start;
	}

	void Play::checkWinner(){
	//checks for win
	//checks select[] number of False = number of bombs and bomb locations = False 
	// adds 100 bonus to score
	// outputs Congratulations you win 
		int count=0;
		for(int i=0; i<length-1; i++){
		 for(int j=0; j<length-1; j++){
			 if (store[i][j]!= 10 && select[i][j] == false)
				 count++;
		 }
		}
		if (count==0){
			score+=100;
			cout<<"Congratulations you win!\n";
			displayBoard();
			game_over=true;
		}
	}
	bool Play::getGame_over()
	{
		return game_over;
	}





