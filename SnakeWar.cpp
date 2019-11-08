#include <graphics.h>
#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <stdio.h>

//#pragma warn -wrch
#define MAX      50

#define UP_ARROW      72
#define DOWN_ARROW    80
#define LEFT_ARROW    75
#define RIGHT_ARROW   77

#define WinMinX       40
#define WinMaxX       600
#define WinMinY       40
#define WinMaxY       440

enum Direction {Forward,Backward,Upward,Downward};

struct Coord
{
int x , y;
};

class Snake;
class Point
{
int x , y , color ;
public:
Point ( )
{
set ();
}

void set();
void draw( );
int getx() {  return x; }
int gety() { return y;  }
friend int point_vanished ( Point &p , Snake &s );
};

class Snake
{
Coord *_Snake;
int _CurSize, _color,_MaxSize, _Points;
char _player;
Direction _Direction;
public:
Snake ( int size = 20, int color = RED , char player = 'M' )
{
_Snake = new Coord [ size ];
_CurSize = 3;
if ( player == 'C' )
{
_Snake [0].x = WinMaxX - 10;
_Direction = Backward;
}
else
{
_Snake [0].x = WinMinX + 10;
_Direction = Forward;
}
//_Snake [0].x = WinMinX + 10;
_Snake [0].y = WinMinY + 10;
_color = color;
_MaxSize = size;
_player = player;
_Points = 0;
}
void set( int size = 20, int color = RED , char player = 'M' )
{
delete _Snake;
_Snake = new Coord [ size ];
_CurSize = 3;
if ( player == 'C' )
{
_Direction = Backward;
_Snake [0].x = WinMaxX - 10;
}
else
{
_Snake [0].x = WinMinX + 10;
_Direction = Forward;
}
_Snake [0].x = WinMinX + 10;
//_Snake [0].y = WinMinY + 10;
_color = color;
_MaxSize = size;
_player = player;
_Points = 0;
}

void change_direction ( Direction d);
void increment ();
void inc_disp ();
void shift_all ();
void display ( int color = BLACK );
void com_play ( Point p1 );
friend int point_vanished ( Point &p , Snake &s );
};
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void Sound ( int s );
void Message_Display ( char msg[30] , char color );
void show_Header();
void signature();
int menu ();
void drawMenu ( int selected , int defCol , int selCol );
void show_About();
void show_HowTOPlay();
void show_New();
void Play();
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

int main()
{

int g = DETECT , d;
initgraph ( &g , &d , "d:\tc\bgi" );

int selected_option;

Start:
selected_option = menu();

switch ( selected_option )
{
case 1:
Play();
goto Start;
case 2:
show_HowTOPlay();
goto Start;
case 3:
show_New();
goto Start;
case 4:
show_About();
goto Start;
case 5:
return 1;
}
return 1;
}


void Snake :: increment ( )
{
 //int i;

shift_all();
if ( _Direction == Forward )
{
if ( _Snake[0].x >= WinMaxX )
{
_Snake[0].x = WinMinX ;
}
else
_Snake[0].x = _Snake[0].x + 10;
}
else if ( _Direction == Backward  )
{
if ( _Snake[0].x <= WinMinX )
{
_Snake[0].x = WinMaxX ;
}
else
_Snake[0].x = _Snake[0].x - 10;
}
else if ( _Direction == Upward  )
{
if ( _Snake[0].y <= WinMinY )
{
_Snake[0].y = WinMaxY ;
}
else
_Snake[0].y = _Snake[0].y - 10;
}
else if ( _Direction == Downward  )
{
if ( _Snake[0].y >= WinMaxY )
{
_Snake[0].y = WinMinY ;
}
else
_Snake[0].y = _Snake[0].y + 10;
}
}


void Snake :: shift_all ()
{
int i;
for ( i = _CurSize -1 ; i > 0; i-- )
{
_Snake[i].x = _Snake[i-1].x;
_Snake[i].y = _Snake[i-1].y;
}
}

void Snake :: inc_disp ()
{
display ( BLACK );
increment();
display ( _color );
}


void Snake :: display ( int color)
{
setfillstyle ( 1, color );
if ( color == 0 )
{
setcolor ( 0 );
bar ( _Snake[_CurSize - 1].x - 5 , _Snake[_CurSize - 1].y - 5 , _Snake[_CurSize - 1].x + 5 , _Snake[_CurSize - 1].y + 5 );
rectangle ( _Snake[_CurSize - 1].x - 5 , _Snake[_CurSize - 1].y - 5 ,_Snake[_CurSize - 1].x + 5 , _Snake[_CurSize - 1].y + 5 );
 //return ;
}
else
{
setcolor ( WHITE );
for ( int i = 0; i< _CurSize; i++ )
{
bar ( _Snake[i].x - 5 , _Snake[i].y - 5 , _Snake[i].x + 5 , _Snake[i].y + 5 );
rectangle ( _Snake[i].x - 5 , _Snake[i].y - 5 , _Snake[i].x + 5 , _Snake[i].y + 5 );
}

/*
//int i = 0;
bar ( _Snake[i].x - 5 , _Snake[i].y - 5 , _Snake[i].x + 5 , _Snake[i].y+ 5 );
rectangle ( _Snake[i].x - 5 , _Snake[i].y - 5 , _Snake[i].x + 5 ,_Snake[i].y );
*/
setfillstyle ( 1 , 0 );
fillellipse ( _Snake[0].x  , _Snake[0].y  , 2  , 2);

char msg[50];
setcolor ( WHITE );

if ( _player == 'C' )
{
bar ( 250 , 12 , 630 , WinMinY - 10 );
sprintf ( msg , "Com Snake at :- ( %d , %d ) Score:- %d", _Snake[0].x, _Snake[0].y , _Points );
outtextxy ( 250 , 12 , msg );
}
else
{
bar ( 250 , 1 , 630 , WinMinY - 10 );
sprintf ( msg , "Ur Snake at :-  ( %d , %d ) Score:- %d", _Snake[0].x, _Snake[0].y , _Points );
outtextxy ( 250 , 1 , msg );
}
}
}


void Snake :: change_direction ( Direction d)
{
if ( ( _Direction == Forward ) && ( d == Backward ) )
{
Sound ( -1 );
}
else if ( ( _Direction == Backward ) && ( d == Forward ) )
{
Sound ( -1 );
}
else if ( ( _Direction == Upward ) && ( d == Downward ) )
{
Sound ( -1 );
}
else if ( ( _Direction == Downward ) && ( d == Upward ) )
{
Sound ( -1 );
}
else
{
_Direction = d;
Sound ( 1 );
}
}


void Point :: draw ( )
{
char msg[30];
setfillstyle ( 1 , color );
setcolor ( YELLOW );
bar ( x - 4 , y - 4 , x + 4 , y + 4 );
rectangle ( x - 4 , y - 4 , x + 4 , y + 4 );


setfillstyle ( 1 , 0 );
fillellipse ( x  , y  , 2 , 2 );

bar ( 1 , 1 , 300 , WinMinY - 10 );
sprintf ( msg , "Point at :- ( %d , %d )", x , y );
outtextxy ( 40 , 1 , msg );
}

void Point :: set ( )
{
color = random ( 15 ) + 1;
x = random ( ( ( WinMaxX - WinMinX  ) / 10 )  )   ;
y = random ( ( ( WinMaxY - WinMinY  ) / 10 )  )   ;
x = ( x * 10 ) + WinMinX;
y = ( y * 10 ) + WinMinY;
draw ( );
}

int point_vanished ( Point &p , Snake &s )
{
if ( ( s._Snake[0].x == p.x ) && ( s._Snake[0].y == p.y ) )
{
s._CurSize++;
if ( s._CurSize == s._MaxSize )
{
return 2;
}
s.increment ();
s.display ( RED );
Sound ( 2 );
delay ( 100 );

s._Points = s._Points + 20 ;
p.set();
return 1;
}
else
{
return -1;
}
}

void Sound ( int s )
{
if ( s == -1 )
{
sound ( 150 );
delay ( 30 );

sound ( 250 );
delay ( 30 );
nosound ();
}
else if ( s == 1 )
{
sound ( 450 );
delay ( 20 );
nosound ();
}
else if ( s == 2 )
{
sound ( 650 );
delay ( 20 );
nosound ();
}

}

void Snake :: com_play ( Point p1 )
{
if ( p1.getx() < _Snake[0].x )
{
if ( _Direction == Forward )
_Direction = p1.gety() < _Snake[0].y ? Upward : Downward;
else
_Direction = Backward;
}
else if ( p1.getx() > _Snake[0].x )
{
if ( _Direction == Backward )
_Direction = p1.gety() < _Snake[0].y ? Upward : Downward;
else
_Direction = Forward;
}
else
{
if ( p1.gety() < _Snake[0].y )
{
_Direction = Upward;
}
else if ( p1.gety() > _Snake[0].y )
{
_Direction = Downward;
}
}
}

void Message_Display ( char msg[30] , char color )
{
settextstyle ( 1 , 0 , 5 );
setcolor ( 8 );
outtextxy ( 195 , 205 , msg);

settextstyle ( 1 , 0 , 5 );
setcolor ( color );
outtextxy ( 200 , 200 , msg);
delay ( 1000 );
}

int menu ()
{
int ch;
int selected = 1;
int TotalOptions = 5;

cleardevice();
setbkcolor ( BLUE );
show_Header();
signature();

drawMenu ( selected , RED , GREEN );
do
{
ch = getch();
if ( ch == DOWN_ARROW )
{
selected = selected >= TotalOptions ? 1 : selected + 1;
drawMenu ( selected , RED , GREEN );
}
else if ( ch == UP_ARROW )
{
selected = selected < 2 ? TotalOptions : selected - 1;
drawMenu ( selected , RED , GREEN );
}

}while ( ch != '
' );

return selected;
}

void drawMenu ( int selected , int defCol , int selCol )
{
int x = 250;
int y = 100;
int width = 150;
int height = 30;
int i;
int TotalOptions = 5;
char menu_option[5][14]= {
"    PLAY     ",
" HOW TO PLAY ",
" WHAT'S NEW  ",
"   ABOUT ME  ",
"     EXIT    "
};
setcolor ( WHITE );

for ( i = 1; i <= TotalOptions; i++ )
{
if ( i == selected )
setfillstyle ( 1 , selCol );
else
setfillstyle ( 1 , defCol );
bar ( x , y , x + width , y + height );
rectangle ( x , y , x + width , y + height );
outtextxy ( x + 20 , y + 10 , menu_option[i - 1] );
y = y + height + 30;
}
}

void show_About()
{
cleardevice();
setbkcolor ( BLACK );
show_Header();
setcolor ( WHITE );
settextstyle ( 0 , 0 , 0 );

signature();

getch();
}

void show_HowTOPlay()
{
cleardevice();
setbkcolor ( BLACK );
show_Header();
settextstyle ( 0 , 0 , 0 );
setcolor ( WHITE );
outtextxy ( 20 , 100 , "Objective:" );
outtextxy ( 20 , 150 , "Playing:" );
outtextxy ( 20 , 220 , "Tip:" );

setcolor ( LIGHTGREEN );
outtextxy ( 120 , 120 , "To collect 50 boxes before the computer Snake." );
outtextxy ( 120 , 170 , "1. Use arrow keys to control your Snake." );
outtextxy ( 120 , 180 , "2. To collect the box just come near to the BOX." );
outtextxy ( 120 , 190 , "3. Press <ESC> to QUIT any time." );
outtextxy ( 120 , 240 , "1. Use shortcuts to collect the BOX. [ Computer Snake never " );
outtextxy ( 120 , 250 , "   uses shortcut]" );
outtextxy ( 120 , 260 , "2. Computer Snake can't Hurt you, so enjoy moving around." );

signature();

getch();
}

void signature()
{
outtextxy ( 350 , 400 , "WWW " );
}

void show_Header()
{
setcolor ( RED );
settextstyle ( 1 , 0 , 4 );
outtextxy ( 193 , 27 , " SNAKE WAR - I " );
setcolor ( YELLOW );
outtextxy ( 195 , 25 , " SNAKE WAR - I " );
}

void show_New()
{
cleardevice();
setbkcolor ( BLACK );
show_Header();
settextstyle ( 0 , 0 , 0 );
setcolor ( WHITE );

outtextxy ( 20 , 100 , "What's new" );
outtextxy ( 20 , 150 , "What's next" );
outtextxy ( 20 , 260 , "When to expect next version" );
outtextxy ( 20 , 320 , "Comments, Bugs and Suggestions" );

setcolor ( LIGHTGREEN );
outtextxy ( 70 , 120 , "Nothing, cos it's the first version. :-)" );

outtextxy ( 70 , 170 , "In next version of this Game:- " );
outtextxy ( 90 , 180 , " > One or more player will be able to play." 
outtextxy ( 90 , 190 , " > You'll be able to select Zero or more computer players." );
outtextxy ( 90 , 200 , " > You'll be able to PAUSE the Game any time." );
outtextxy ( 90 , 210 , " > You'll be able to select the color of each snake." );
outtextxy ( 90 , 220 , " > Keys will be customizable." );
outtextxy ( 90 , 230 , " > Snakes will be able to Hurt each other." );

outtextxy ( 70 , 280 , "Don't worry, i'll mail the code of next version too. [ Very Soon ]" );

outtextxy ( 70 , 340 , "For any suggestion or comment or Bug report feel free to mail me." );
outtextxy ( 70 , 350 , "There may be Bugs too in this game, so please let me know them." );

signature();
getch();
}

void Play()
{
Snake s1 ( MAX , GREEN , 'M' );
Snake s2 ( MAX , MAGENTA , 'C' );

char ch , KeyPressed = 0;

cleardevice();
randomize ();

rectangle ( WinMinX - 7, WinMinY - 7, WinMaxX + 7 , WinMaxY + 7 );
Point p1;

setbkcolor ( BLUE );
s1.inc_disp();
s2.inc_disp();

setcolor ( YELLOW );
outtextxy ( 10 , 450 , "> Collect 50 Boxes to WIN.   > Use shortcuts to WIN.");
setcolor ( CYAN );
outtextxy ( 10 , 460 , "> Use <ESC> to QUIT anytime. > LEFT , RIGHT , UP , DOWN Arrow Keys to Play. ");
getch();

KeyPressed = 1;
ch = 'R';
while ( 1 )
{
while ( !kbhit() )
{
s1.inc_disp();
if ( point_vanished ( p1 , s1 ) == 2 )
{
Message_Display ( "YOU WIN " , GREEN );
ch=0x1b;
getch();
break;
}

s2.com_play ( p1 );
s2.inc_disp();
if ( point_vanished ( p1 , s2 ) == 2 )
{
Message_Display ( "YOU LOSE " , GREEN );
ch=0x1b;
getch();
break;
}

delay ( 100 );
if ( KeyPressed == 1 )KeyPressed = 0;
}
if ( ch == 0x1b )
break;

ch = getch();
if ( KeyPressed == 1 )
{
KeyPressed = 0;
continue;
}
if ( ch == 0x1b )
break;
else if ( ch == 0 )
{
ch = getch ();
if ( ch == UP_ARROW )
{
s1.change_direction ( Upward );
KeyPressed = 1;
}
else if ( ch == DOWN_ARROW )
{
s1.change_direction ( Downward );
KeyPressed = 1;
}
else if ( ch == LEFT_ARROW )
{
s1.change_direction ( Backward );
KeyPressed = 1;
}
else if ( ch == RIGHT_ARROW )
{
s1.change_direction ( Forward );
KeyPressed = 1;
}
}
}
}
