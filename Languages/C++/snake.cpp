#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

bool gameOver;
const int width = 36;
const int height = 24;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void Reset(){
	gameOver=false;
	nTail=0;
	tailX[100]={0};
	tailY[100]={0};
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void Setup(){
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}
void Draw(){
	system("cls");
	for(int i=0; i<width; i++) cout<<"_";
	cout<<endl;
	
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			if(j==0 || j==width-1) cout<<"|";
			else if(i==y && j==x)	cout<<"O";
			else if(i== fruitY && j==fruitX)	cout<<"X";
			else{
				bool print = false;
				for(int k=0; k< nTail; k++){
					if(tailX[k]==j && tailY[k]==i){
						cout<<"o";
						print = true;
					}
				}
				if(!print)	cout<<" ";
			}	
		}
		cout<<endl;
	}
	
	for(int i=0; i<width; i++) cout<<"_";
	cout<<endl;
	
	cout<<"Score: "<< score <<endl;
	
}

void Input(){
	if(_kbhit()){
		switch(_getch()){
			case 'a':
				dir = LEFT;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 'w':
				dir = UP;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'x':
				gameOver = true;
				break;	
		}
	}
}

void Logic(){
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i=1; i<nTail; i++){
		prev2X = tailX[i];
		tailX[i] = prevX;
		prevX = prev2X;
		prev2Y = tailY[i];
		tailY[i] = prevY;
		prevY = prev2Y;
	}
	switch(dir){
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		default:
			break;
	}
	if( x>= width-1) x = 1; else if (x<=0) x = width - 1;
	if( y>= height) y = 0; else if (y<0) y = height - 1;
	if (x>width || x<0 || y>height || y<0)	{
		cout<<endl<<"GAME OVER!!!!!!!"<<endl;
		gameOver=true;
	}
	
	for(int i=0; i<nTail; i++)
		if(tailX[i] == x && tailY[i] == y) gameOver = true;
	
	
	if( x == fruitX && y == fruitY ){
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
	}
}

int main(){
	Setup();
	char ch;
	int high=0;
	
	do{
		cout<<"Press any key to start"<<endl<<"Press 'x' to exit"<<endl;
		cin>>ch;
		switch(ch){
			case 'x':
				break;
			default:
				while( !gameOver){
					Draw();
					Input();
					Logic();
					Sleep(30);
				}
				gameOver = false;
				high=max(high,score);
				Reset();
				break;	
		}
	}while(ch!='x');
	cout<<"HIGH SCORE: "<<high<<endl<<endl<<endl;
	cout<<"GAME OVER!"<<endl;
	return 0;
}
