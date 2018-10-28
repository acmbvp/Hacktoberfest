#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
 
#define RIGHT 19712
#define LEFT 19200
#define UP 18432
#define DOWN 20480
 
int carArr[5][2];
unsigned long int score = 0;
 
//to draw the path
void drawPath() {
   bar(210,40,222,440);
   bar(318,40,322,440);
   bar(418,40,430,440);
}
 
//this function will draw the car at given position and in given color
void drawCar( int row, int col, int last, int color ) {
   int r = row,c = col;
   switch( last ) {
	 case LEFT  : c = col + 1;
 
		      break;
	 case RIGHT : c = col - 1;
		      break;
	 case UP    : r = row + 1;
		      break;
	 case DOWN  : r = row - 1;
		      break;
      }
   setfillstyle( SOLID_FILL, BLACK ); // to erase
   bar( 260 + c * 100 , 40 + r * 80 , 280 + c * 100 , 60 + r * 80 );
   bar( 240 + c * 100 , 60 + r * 80 , 300 + c * 100 , 80 + r * 80  );
   bar( 260 + c * 100 , 80 + r * 80 , 280 + c * 100 , 100 + r * 80  );
   bar( 240 + c * 100 , 100 + r * 80 , 300 + c * 100 , 120 + r * 80  );
   setfillstyle( SOLID_FILL, color );  // to draw
   bar( 260 + col * 100 , 40 + row * 80 , 280 + col * 100 , 60 + row * 80 );
   bar( 240 + col * 100 , 60 + row * 80 , 300 + col * 100 , 80 + row * 80  );
   bar( 260 + col * 100 , 80 + row * 80 , 280 + col * 100 , 100 + row * 80  );
   bar( 240 + col * 100 , 100 + row * 80 , 300 + col * 100 , 120 + row * 80  );
   carArr[row][col] = 1;
   carArr[r][c] = 0;
}
 
//this function will erase the car and place it in new position
//when we make a move
void eraseBottom( int c ) {
   int r = 4;
   setfillstyle( SOLID_FILL, BLACK ); // to erase
   bar( 260 + c * 100 , 40 + r * 80 , 280 + c * 100 , 60 + r * 80 );
   bar( 240 + c * 100 , 60 + r * 80 , 300 + c * 100 , 80 + r * 80  );
   bar( 260 + c * 100 , 80 + r * 80 , 280 + c * 100 , 100 + r * 80  );
   bar( 240 + c * 100 , 100 + r * 80 , 300 + c * 100 , 120 + r * 80  );
   carArr[r][c] = 0;
}
 
//this function will tell where we have to place the enemy car
void enemy( int row, int col) {
   if(  carArr[ row ][ col ] == 0 ) {
      if( row < 5 ) {
	 drawCar( row++, col , DOWN, WHITE );
      }
   } else if( carArr[ row ][ col ] == 1 ) {
      gotoxy(1,1);
      printf("You Lost The Game!!!!");
      getch();
      exit(0);
   }
}
//this is the master of all functions
//this will generate the random numbers and positions for enemy cars
//this function will instruct the action to be done according to the players
//move!!
//Here speed will be increasing gradually when score increases
void play() {
   int key;
   int row = 4, col = 0;
   int r = row,c = col;
   unsigned int last;
   int ctr1 = 0, ctr2 = -2;
   int col1, col2, col3;
   col1 = rand() % 2;
   col2 = rand() % 2;
   col3 = rand() % 2;
   drawCar( row, col, RIGHT, RED );
 
   while( key != 283 ) {
      while( bioskey( 1 ) == 0 ) {
	 while( kbhit() == 0 ) {
	    gotoxy(1,5);
	    printf("Score : %lu", score);
	    if( ctr1 < 5 ) {
	       enemy( ctr1 , col1 );
	       enemy( ctr2 , col2 );
	       if( ctr1 == 4 ) {
		  enemy( 0 , col3 );
	       }
	    } else {
	       score += 100;
	       gotoxy(1,5);
	       printf("Score : %lu", score);
	       eraseBottom(col1);
	       ctr1 = ctr2;
	       ctr2 = 1;
	       col1 = col2;
	       col2 = col3;
	       col3 = rand() % 2;
	       enemy( ctr1 , col1 );
	       enemy( ctr2 , col2 );
	    }
	    ctr1++;
	    ctr2++;
	    //delay(500);
	    if( score < 1000 )
	       delay(750);
	    else if( score < 2000 )
	       delay(500);
	    else if( score < 3000 )
	       delay(400);
	    else if( score < 4000 )
	       delay( 350 );
	    else if( score < 5000 )
	       delay(300);
 
	 }
      }
      key = bioskey( 0 );
 
      switch( key ) {
	 case LEFT  : c = col - 1;
		      last = LEFT;
		      break;
	 case RIGHT : c = col + 1;
		      last = RIGHT;
		      break;
	 case UP    : r = row - 1;
		      last = UP;
		      break;
	 case DOWN  : r = row + 1;
		      last = DOWN;
		      break;
      }
      if( c < 0 )   c = 0;
      if( r < 0 )   r = 0;
      if( c > 1 )   c = 1;
      if( r > 4 )   r = 4;
 
      if( carArr[r][c] != 0 ) {
	 gotoxy(1,1);
	 printf("You Lost The Game!!!!");
	 getch();
	 exit(0);
      }
      drawCar(r,c,last, RED);
      row = r;
      col = c;
   }
}
 
// and ofcourse... this is the main function() ;)
void main() {
   int gdriver = DETECT, gmode;
   initgraph( &gdriver, &gmode, "c:\\turboc3\\bgi" );
   drawPath();
   play();
   closegraph();
}