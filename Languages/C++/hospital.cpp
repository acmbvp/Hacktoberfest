#include <iostream>
#include <fstream.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <ctype.h>

using namespace std;

class MENU
{
	public :
			void MAIN_MENU(void) ;
	private :
			void EDIT_MENU(void) ;
			int  st1, st2 ;
} ;

class PATIENT
{
	public :
			void ADMIT(void) ;
			void DISCHARGE(void) ;
			void MODIFY(void) ;
			void LIST(void) ;
			void DISPLAY(void) ;
	private :
			void MODIFY_RECORD(int, int, int, int, char[]) ;
			int  RECORDNO(int, int) ;
			void DISPLAY_RECORD(int, int) ;
			void DELETE_RECORD(int, int) ;
			int  roomno, bedno, age, dd, mm, yy ;
			char name[26], address[36], phone[10], sex, disease[16], doctor[26] ;
} ;

class ROOM
{
	public :
			void ADD_ROOMS(void) ;
			int  AVAILABLE(int, int) ;
			int  EMPTY(int) ;
			void CHANGE_STATUS(int, int, char) ;
			void LIST(void) ;
			int  ROOMNO() ;
			int  BEDNO(int) ;
			int  LAST_ROOMNO(void) ;
	private :
			int  RECORDNO(int, int) ;
			int  roomno, bedno ;
			char status ;
} ;

class DOCTOR
{
	public :
			void ADD(void) ;
			void DELETE(void) ;
			void LIST(void) ;
			char *DOCTOR_NAME(int) ;
			int  RECORDS(void) ;
			void DEFAULT(void) ;
	private :
			char name[26] ;
} ;



void MENU :: MAIN_MENU(void)
{
	while (1)
	{
	clrscr();
	int ch=7 ;
	gotoxy(33,8);
	cout<< "MAIN MENU   -   HOSPITAL" ;
	gotoxy(33,10);
	cout<<  "1:     Addition of patient   ";
	gotoxy(33,11);
	cout<<  "2:     Leaving of  patient  " ;
	gotoxy(33,12);
	cout<<  "3:     Room  record  " ;
	gotoxy(33,13);
	cout<<  "4:     Patient List  "  ;
	gotoxy(33,14);
	cout<<  "5:     Patient status "  ;
	gotoxy(33,15);
	cout<<  "6:     Modification "       ;
	gotoxy(33,16);
	cout<<  "7:     Return  "        ;
	gotoxy(33,18);
		cout <<"Make a Selection ";
		fflush(stdin);
		cin>>ch ;

		clrscr();
		gotoxy(37,3);
		cout<<" HOSPITAL" ;
		gotoxy(14,8) ;
		if (ch == 1)
		{
			PATIENT p ;
			p.ADMIT() ;
		}
		else
		if (ch == 2)
		{
			PATIENT p ;
			p.DISCHARGE() ;
		}
		else
		if (ch == 3)
		{
			ROOM r ;
			r.LIST() ;
		}
		else
		if (ch == 4)
		{
			PATIENT p ;
			p.LIST() ;
		}
		else
		if (ch == 5)
		{
			PATIENT p ;
			p.DISPLAY() ;
		}
		else
		if (ch == 6)
			EDIT_MENU() ;
		else
		if (ch == 7)
			break ;
	}
}
void MENU :: EDIT_MENU(void)
{
	int ch=0 ;

	while (1)
	{
		clrscr();
		gotoxy(35,8 );
		cout<<" M O D I F I C A T I O N";
		gotoxy(35,10);
		cout<<   " 1 : Addition of room";
		gotoxy(35,11);
		cout<<   " 2 : Modification of patient";
		gotoxy(35,12);
		cout<<   " 3 : Additon of Dr.   ";
		gotoxy(35,13);
		cout<<   " 4 : Deletion of Doctor ";
		gotoxy(35,14);
		cout<<   " 5 : Return to main menu " ;
		gotoxy(35,16);
		cout<<" Make a Selection ";
		cin>>ch;
		if (ch == 1)
		{
			ROOM r ;
			r.ADD_ROOMS() ;
		}
		else
		if (ch == 2)
		{
			PATIENT p ;
			p.MODIFY() ;
		}
		else
		if (ch == 3)
		{
			DOCTOR d ;
			d.ADD() ;
		}
		else
		if (ch == 4)
		{
			DOCTOR d ;
			d.DELETE() ;
		}
		else
		if (ch == 5)
			break ;
	}
}

int ROOM :: LAST_ROOMNO(void)
{
	fstream file ;
	file.open("ROOM.DAT", ios::in) ;
	if (file.fail())
	{
		file.close() ;
		return 0 ;
	}
	int last=0 ;
	while (file.read((char *) this, sizeof(ROOM)))
		last = roomno ;
	file.close() ;
	return last ;
}

void ROOM :: ADD_ROOMS(void)
{
	clrscr() ;
	char ch ;
	do
	{
		gotoxy(5,5) ; clreol() ;
		cout <<"Do you want to add rooms (y/n) " ;
		ch = getche() ;
		ch = toupper(ch) ;
	} while (ch != 'Y' && ch != 'N') ;
	if (ch == 'N')
		return ;
	int rno = LAST_ROOMNO() + 1 ;
	int bno=1 ;
	fstream file ;
	file.open("ROOM.DAT", ios::app) ;
	for (int i=1; i<=2; i++)
	{
		roomno = rno ;
		bedno  = bno ;
		status = 'A' ;
		file.write((char *) this, sizeof(ROOM)) ;
		bno = 2 ;
	}
	gotoxy(10,10) ;
	cout <<"Room no. : " <<rno ;
	gotoxy(10,11) ;
	cout <<"Total no. of beds : 2" ;
	gotoxy(10,12) ;
	cout <<"STATUS:" ;
	gotoxy(20,13) ;
	cout <<"Bed no. 1 : Available" ;
	gotoxy(20,14) ;
	cout <<"Bed no. 2 : Available" ;
	file.close() ;
	gotoxy(5,24) ;
	cout <<"\7Room Added" ;
	gotoxy(5,25) ;
	cout <<"Press any key to continue..." ;
//	getch() ;
}


//**********************************************************
// THIS FUNCTION RETURNS 0 IF GIVEN ROOM IS NOT EMPTY
//**********************************************************

int ROOM :: EMPTY(int rno)
{
	fstream file ;
	file.open("ROOM.DAT", ios::in) ;
	int empty=1 ;
	while (file.read((char *) this, sizeof(ROOM)))
	{
		if (roomno == rno && status == 'N')
		{
			empty = 0 ;
			break ;
		}
	}
	file.close() ;
	return empty ;
}

int ROOM :: AVAILABLE(int rno, int bno)
{
	fstream file ;
	file.open("ROOM.DAT", ios::in) ;
	int avail=0 ;
	while (file.read((char *) this, sizeof(ROOM)))
	{
		if (roomno == rno && bedno == bno && status == 'A')
		{
			avail = 1 ;
			break ;
		}
	}
	file.close() ;
	return avail ;
}

int ROOM :: RECORDNO(int rno, int bno)
{
	fstream file ;
	file.open("ROOM.DAT", ios::in) ;
	int recordno=0 ;
	while (file.read((char *) this, sizeof(ROOM)))
	{
		recordno++ ;
		if (roomno == rno && bedno == bno)
			break ;
	}
	file.close() ;
	return recordno ;
}

void ROOM :: LIST(void)
{
	clrscr() ;
	int row = 4, flag ;
	int sta = 0 ;
	char ch ;
	gotoxy(1,1) ;
	cout<<"Room no.  Bed no.   Status             Room no.  Bed no.   Status             \n" ;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	fstream file ;
	file.open("ROOM.DAT", ios::in) ;
	if (file.fail())
	{
		gotoxy(5,10) ;
		cout <<"\7Records not found" ;
		getch() ;
		file.close() ;
		return ;
	}
	while (file.read((char *) this, sizeof(ROOM)))
	{
		flag = 0 ;
		delay(20) ;
		gotoxy(2,row) ;
		cout <<roomno ;
		gotoxy(12,row) ;
		cout <<bedno ;
		gotoxy(23,row) ;
		cout <<status ;
		if (status == 'A')
			sta++ ;
		file.read((char *) this, sizeof(ROOM)) ;
		gotoxy(41,row) ;
		cout <<roomno ;
		gotoxy(51,row) ;
		cout <<bedno ;
		gotoxy(62,row) ;
		cout <<status ;
		if (status == 'A')
			sta++ ;
		if (row == 22)
		{
			flag = 1 ;
			gotoxy(1,25) ;
			cout <<"Press any key to continue..." ;
			ch = getch() ;
			if (ch == 27)
				break ;
			row = 4 ;
		}
		else
			row++ ;
	}
	if (!flag)
	{
		gotoxy(1,25) ;
		cout <<"Press any key to continue..." ;

	}
	gotoxy(1,16) ;
	cout <<"Total room            :  " <<roomno ;
	gotoxy(1,17) ;
	cout <<"Total occupied beds   :  " <<(roomno*2)-sta ;
	gotoxy(1,18) ;
	cout<<"Total available beds  :  "<<sta ;
	gotoxy(1,25) ;
	cout <<"Press any key to continue..." ;
	getch() ;
	clrscr();
}


//**********************************************************
// THIS FUNCTION RETURNS THE FIRST AVAILABLE ROOM NO.
//**********************************************************

int ROOM :: ROOMNO(void)
{
	fstream file ;
	file.open("ROOM.DAT", ios::in) ;
	int rno=0 ;
	while (file.read((char *) this, sizeof(ROOM)))
	{
		if (status == 'A')
		{
			rno = roomno ;
			break ;
		}
	}
	file.close() ;
	return rno ;
}

int ROOM :: BEDNO(int rno)
{
	fstream file ;
	file.open("ROOM.DAT", ios::in) ;
	int bno=0 ;
	while (file.read((char *) this, sizeof(ROOM)))
	{
		if (rno == roomno && status == 'A')
		{
			bno = bedno ;
			break ;
		}
	}
	file.close() ;
	return bno ;
}

void ROOM :: CHANGE_STATUS(int rno, int bno, char rstatus)
{
	fstream file ;
	file.open("ROOM.DAT", ios::in) ;
	fstream temp ;
	temp.open("temp.dat", ios::out) ;
	file.seekg(0,ios::beg) ;
	while (!file.eof())
	{
		file.read((char *) this, sizeof(ROOM)) ;
		if (file.eof())
			break ;
		if (rno == roomno && bno == bedno)
		{
			status = rstatus ;
			temp.write((char *) this, sizeof(ROOM)) ;
		}
		else
			temp.write((char *) this, sizeof(ROOM)) ;
	}
	file.close() ;
	temp.close() ;
	file.open("ROOM.DAT", ios::out) ;
	temp.open("temp.dat", ios::in) ;
	temp.seekg(0,ios::beg) ;
	while (!temp.eof())
	{
		temp.read((char *) this, sizeof(ROOM)) ;
		if (temp.eof())
			break ;
		file.write((char *) this, sizeof(ROOM)) ;
	}
	file.close() ;
	temp.close() ;
}
void DOCTOR :: ADD(void)
{
	clrscr() ;
	if (RECORDS() >= 20)
	{
		gotoxy(5,10) ;
		cout <<"Sorry no more records can be added" ;
		getch() ;
		return ;
	}
	char ch ;
	do
	{
		gotoxy(5,5) ; clreol() ;
		cout <<"Do you want to add Doctors (y/n) " ;
		ch = getche() ;
		ch = toupper(ch) ;
	} while (ch != 'Y' && ch != 'N') ;
	if (ch == 'N')
		return ;
	LIST() ;
	int valid ;
	do
	{
		valid = 1 ;
		gotoxy(5,25) ; clreol() ;
		cout <<"Enter the name of the New Doctor" ;
		gotoxy(5,7) ; clreol() ;
		cout <<"Name : " ;
		gets(name) ;
		strupr(name) ;
		if (strlen(name) < 1 || strlen(name) > 25)
		{
			valid = 0 ;
			gotoxy(5,25) ; clreol() ;
			cout <<"\7Enter correctly (Range: 1..25)" ;
			getch() ;
		}
	} while (!valid) ;
	gotoxy(5,25) ; clreol() ;
	fstream file ;
	file.open("DOCTOR.DAT", ios::app) ;
	file.write((char *) this, sizeof(DOCTOR)) ;
	file.close() ;
	LIST() ;
	gotoxy(5,24) ;
	cout <<"Doctor Name Added" ;
	gotoxy(5,25) ;
	cout <<"Press any key to continue..." ;
	getch() ;
}

void DOCTOR :: DEFAULT(void)
{
	fstream file ;
	file.open("DOCTOR.DAT",ios::out) ;
	strcpy(name,"SANDEEP KUMAR") ;
	file.write((char *) this, sizeof(DOCTOR)) ;
	file.close() ;
}

void DOCTOR :: LIST(void)
{
	int row = 13, col=2, sno=1 ;
	char ch ;
	gotoxy(1,10);
	cout<<"------------------------------------" ;
	gotoxy(1,11) ; clreol() ;
	cout<<"S.No.   Name of the Doctors available\n" ;
	cout<<"------------------------------------";

	fstream file ;
	file.open("DOCTOR.DAT", ios::in) ;
	while (file.read((char *) this, sizeof(DOCTOR)))
	{
		delay(20) ;
		gotoxy(col,row) ;
		cout <<sno ;
		gotoxy(col+6,row) ;
		cout <<name ;
		if (row == 22)
		{
			row = 13 ;
			col = 40 ;
		}
		else
		{
			sno++ ;
			row++ ;
		}
	}
}

int DOCTOR :: RECORDS(void)
{
	fstream file ;
	file.open("DOCTOR.DAT", ios::in) ;
	int records=0 ;
	while (file.read((char *) this, sizeof(DOCTOR)))
		records++ ;
	file.close() ;
	return records ;
}

char *DOCTOR :: DOCTOR_NAME(int pd)
{
	fstream file ;
	file.open("DOCTOR.DAT", ios::in) ;
	int i=0 ;
	while (file.read((char *) this, sizeof(DOCTOR)))
	{
		i++ ;
		if (i == pd)
			break ;
	}
	file.close() ;
	return name ;
}


void DOCTOR :: DELETE(void)
{
	clrscr() ;
	LIST() ;
	char t1[5] ;
	int  t2, sno ;
	do
	{
		gotoxy(5,5) ; clreol() ;
		cout <<"Enter S.No. of the Doctor to be Deleted " ;
		gets(t1) ;
		t2 = atoi(t1) ;
		if (t1[0] == '0')
			return ;
		sno = t2 ;
	} while (sno < 1 || sno > RECORDS()) ;
	fstream file ;
	file.open("DOCTOR.DAT", ios::in) ;
	fstream temp ;
	temp.open("temp.dat", ios::out) ;
	file.seekg(0,ios::beg) ;
	int i=0 ;
	while (!file.eof())
	{
		file.read((char *) this, sizeof(DOCTOR)) ;
		i++ ;
		if (file.eof())
			break ;
		if (i != sno)
			temp.write((char *) this, sizeof(DOCTOR)) ;
	}
	file.close() ;
	temp.close() ;
	file.open("DOCTOR.DAT", ios::out) ;
	temp.open("temp.dat", ios::in) ;
	temp.seekg(0,ios::beg) ;
	while (!temp.eof())
	{
		temp.read((char *) this, sizeof(DOCTOR)) ;
		if (temp.eof())
			break ;
		file.write((char *) this, sizeof(DOCTOR)) ;
	}
	file.close() ;
	temp.close() ;
	clrscr();
	LIST() ;
	gotoxy(5,7) ;
	cout <<"\7Record Deleted" ;
	gotoxy(5,25) ;
	cout <<"Press any key to continue..." ;
	getch() ;
}

void PATIENT :: ADMIT(void)
{
	int  t2, rno, bno, page, pd ;
	char t1[5], pname[26], paddress[36], pphone[10], psex, pdisease[16], pdoctor[26], ch ;
	int d1, m1, y1, valid ;
	ROOM r ;
	rno = r.ROOMNO() ;
	if (rno == 0)
	{
		gotoxy(5,10) ;
		cout <<"\7Sorry no room is available for the Patient" ;
		getch() ;
		return ;
	}
	bno = r.BEDNO(rno) ;
	struct date d;
	getdate(&d);
	d1 = d.da_day ;
	m1 = d.da_mon ;
	y1 = d.da_year ;
	gotoxy(60,1) ;
	cprintf("Room no.: %d",rno) ;
	gotoxy(60,2) ;
	cprintf("Bed no. : %d",bno) ;
	gotoxy(5,3) ;
	cout <<"Name of patient    =>  " ;
	gotoxy(5,4) ;
	cout <<"Address of patient =>  " ;
	gotoxy(5,5) ;
	cout <<"Phone of patient   =>  " ;
	gotoxy(5,6) ;
	cout <<"Age of patient     =>  " ;
	gotoxy(5,7) ;
	cout <<"Sex of patient     =>  " ;
	do
	{
		valid = 1 ;
		gotoxy(5,25) ; clreol() ;
		cout <<"ENTER NAME OF THE PATIENT" ;
		gotoxy(30,3) ; clreol() ;
		gets(pname) ;
		strupr(pname) ;
		if (pname[0] == '0')
			return ;
		if (strlen(pname) < 1 || strlen(pname) > 25)
		{
			valid = 0 ;
			gotoxy(5,25) ; clreol() ;
			cout <<"\7Enter correctly (Range: 1..25)" ;
			getch() ;
		}
	} while (!valid) ;
	do
	{
		valid = 1 ;
		gotoxy(5,25) ; clreol() ;
		cout <<"ENTER ADDRESS OF THE PATIENT" ;
		gotoxy(30,4) ; clreol() ;
		gets(paddress) ;
		strupr(paddress) ;
		if (paddress[0] == '0')
			return ;
		if (strlen(paddress) < 1 || strlen(paddress) > 35)
		{
			valid = 0 ;
			gotoxy(5,25) ; clreol() ;
			cout <<"\7Enter correctly (Range: 1..35)" ;
			getch() ;
		}
	} while (!valid) ;
	do
	{
		valid = 1 ;
		gotoxy(5,25) ; clreol() ;
		cout <<"ENTER PHONE NO. OF THE PATIENT or <ENTER> FOR NONE" ;
		gotoxy(30,5) ; clreol() ;
		gets(pphone) ;
		if (pphone[0] == '0')
			return ;
		if ((strlen(pphone) < 7 && strlen(pphone) > 0) || (strlen(pphone) > 9))
		{
			valid = 0 ;
			gotoxy(5,25) ; clreol() ;
			cout <<"\7Enter correctly" ;
			getch() ;
		}
	} while (!valid) ;
	do
	{
		valid = 1 ;
		gotoxy(5,25) ; clreol() ;
		cout <<"ENTER AGE OF THE PATIENT" ;
		gotoxy(30,6) ; clreol() ;
		gets(t1) ;
		t2 = atoi(t1) ;
		page = t2 ;
		if (t1[0] == '0')
			return ;
		if (page < 1 || page > 100)
		{
			valid = 0 ;
			gotoxy(5,25) ; clreol() ;
			cout <<"\7ENTER CORRECTLY" ;
			getch() ;
		}
	} while (!valid) ;
	do
	{
		gotoxy(5,25) ; clreol() ;
		cout <<"ENTER SEX OF THE PATIENT (M/F)" ;
		gotoxy(30,7) ; clreol() ;
		psex = getche() ;
		psex = toupper(psex) ;
	} while (psex != 'M' && psex != 'F') ;
	do
	{
		valid = 1 ;
		gotoxy(5,25) ; clreol() ;
		cout <<"ENTER DISEASE OF THE PATIENT" ;
		gotoxy(28,8) ; clreol() ;
		cout <<"Disease : " ;
		gets(pdisease) ;
		strupr(pdisease) ;
		if (pdisease[0] == '0')
			return ;
		if (strlen(pdisease) < 1 || strlen(pdisease) > 15)
		{
			valid = 0 ;
			gotoxy(5,25) ; clreol() ;
			cout <<"\7Enter correctly (Range: 1..15)" ;
			getch() ;
		}
	} while (!valid) ;
	gotoxy(5,25) ; clreol() ;
	DOCTOR dr ;
	fstream file ;
	file.open("DOCTOR.DAT", ios::in) ;
	if (file.fail())
		dr.DEFAULT() ;
	file.close() ;
	dr.LIST() ;
	do
	{
		valid = 1 ;
		gotoxy(5,25) ; clreol() ;
		gotoxy(5,24) ; clreol() ;
		cout <<"ENTER S.No. OF THE DOCTOR  " ;
		gets(t1) ;
		t2 = atoi(t1) ;
		pd = t2 ;
		if (t1[0] == '0')
			return ;
		if (pd < 1 || pd > dr.RECORDS())
		{
			valid = 0 ;
			gotoxy(5,25) ; clreol() ;
			cout <<"\7ENTER CORRECTLY" ;
			getch() ;
		}
	} while (!valid) ;
	strcpy(pdoctor,dr.DOCTOR_NAME(pd)) ;
	do
	{
		gotoxy(5,17) ; clreol() ;
		cout <<"Do you want to save this record (y/n) => " ;
		fflush(stdin);
		ch = getche() ;
		ch = toupper(ch) ;
	} while (ch != 'Y' && ch != 'N') ;
	if (ch == 'N')
		return ;
	r.CHANGE_STATUS(rno,bno,'N') ;
	roomno = rno ;
	bedno = bno ;
	strcpy(name,pname) ;
	strcpy(address,paddress) ;
	strcpy(phone,pphone) ;
	age = page ;
	sex = psex ;
	dd = d1 ;
	mm = m1 ;
	yy = y1 ;
	strcpy(disease,pdisease) ;
	strcpy(doctor,pdoctor) ;
	file.open("PATIENT.DAT", ios::app) ;
	file.write((char *) this, sizeof(PATIENT)) ;
	file.close() ;
}

void PATIENT :: LIST(void)
{
	clrscr() ;
	int row = 5 , found=0, flag=0 ;
	char ch ;
	gotoxy(1,1) ; clreol() ;
	cout<<"List of the patient\n";
	cout<<"~~~~~~~~~~~~~~~~~~~";
	gotoxy(1,3) ;
	cout <<"ROOM NO.    BED NO.        PATIENT'S NAME" ;
	fstream file ;
	file.open("PATIENT.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	while (file.read((char *) this, sizeof(PATIENT)))
	{
		flag = 0 ;
		delay(20) ;
		found = 1 ;
		gotoxy(3,row) ;
		cout <<roomno ;
		gotoxy(15,row) ;
		cout <<bedno ;
		gotoxy(28,row) ;
		cout	<<name ;
		if ( row == 23 )
		{
			flag = 1 ;
			row = 5 ;
			gotoxy(1,25) ;
			cout <<"Press any key to continue or Press <ESC> to exit" ;
			ch = getch() ;
			if (ch == 27)
				break ;
			clrscr() ;
			textcolor(BLACK) ; textbackground(WHITE) ;
			gotoxy(31,1) ;
			cout <<" LIST OF PATIENTS " ;
			gotoxy(1,3) ; clreol() ;
			gotoxy(1,3) ;
			cout <<"ROOM NO.    BED NO.        PATIENT'S NAME" ;
			textcolor(LIGHTGRAY) ; textbackground(BLACK) ;
		}
		else
			row++ ;
	}
	if (!found)
	{
		gotoxy(5,10) ;
		cout <<"\7Records not found" ;
	}
	if (!flag)
	{
		gotoxy(1,25) ;
		cout <<"Press any key to continue..." ;
		getche() ;
	}
	file.close () ;
}

void PATIENT :: DISPLAY_RECORD(int rno, int bno)
{
	fstream file ;
	file.open("PATIENT.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	while (file.read((char *) this, sizeof(PATIENT)))
	{
		if (rno == roomno && bno == bedno)
		{
			textcolor(BLACK) ; textbackground(WHITE) ;
			gotoxy(5,1) ;
			cprintf("Date of Admit : %d/%d/%d",dd,mm,yy) ;
			gotoxy(60,1) ;
			cprintf("Room no.: %d",roomno) ;
			gotoxy(60,2) ;
			cprintf("Bed no. : %d",bedno) ;
			textcolor(LIGHTGRAY) ; textbackground(BLACK) ;
			gotoxy(5,3) ;
			cout <<"Name    : " <<name ;
			gotoxy(5,4) ;
			cout <<"Address : " <<address ;
			gotoxy(5,5) ;
			cout <<"Phone   : " <<phone ;
			gotoxy(5,6) ;
			cout <<"Age     : " <<age ;
			gotoxy(5,7) ;
			cout <<"Sex     : " <<sex ;
			gotoxy(5,8) ;
			cout <<"Disease : " <<disease ;
			gotoxy(5,10) ;
			cout <<"Doctor Assigned : Dr." <<doctor ;
			break ;
		}
	}
	file.close() ;
}

void PATIENT :: DISPLAY(void)
{
	clrscr() ;
	char t1[5], ch ;
	int  rno, bno, valid, t2 ;
	ROOM r ;
	do
	{
		valid = 1 ;
		gotoxy(5,5) ;
		cout <<"Room no. : " ;
		gotoxy(5,7) ;
		cout <<"Bed no.  : " ;
		gotoxy(5,25) ; clreol() ;
		cout <<"ENTER ROOM NO. OF THE PATIENT or <ENTER> FOR HELP" ;
		gotoxy(16,5) ; clreol() ;
		gets(t1) ;
		t2 = atoi(t1) ;
		rno = t2 ;
		if (t1[0] == '0')
			return ;
		if (strlen(t1) == 0)
		{
			valid = 0 ;
			r.LIST() ;
			clrscr() ;
		}
		if ((rno < 1 || rno > r.LAST_ROOMNO()) && valid)
		{
			valid = 0 ;
			gotoxy(5,25) ; clreol() ;
			cout <<"\7ENTER CORRECTLY" ;
			getch() ;
		}
	} while (!valid) ;
	do
	{
		valid = 1 ;
		gotoxy(5,5) ;
		cout <<"Room no. : " <<rno ;
		gotoxy(5,7) ;
		cout <<"Bed no.  : " ;
		gotoxy(5,25) ; clreol() ;
		cout <<"ENTER BED NO. OF THE PATIENT or <ENTER> FOR HELP" ;
		gotoxy(16,7) ; clreol() ;
		gets(t1) ;
		t2 = atoi(t1) ;
		bno = t2 ;
		if (t1[0] == '0')
			return ;
		if (strlen(t1) == 0)
		{
			valid = 0 ;
			r.LIST() ;
			clrscr() ;
		}
		if ((bno < 1 || bno > 2) && valid)
		{
			valid = 0 ;
			gotoxy(5,25) ; clreol() ;
			cout <<"\7ENTER CORRECTLY" ;
			getch() ;
		}
	} while (!valid) ;
	gotoxy(5,25) ; clreol() ;
	if (r.AVAILABLE(rno,bno))
	{
		gotoxy(5,20) ;
		cout <<"\7Sorry, there is no. Patient in this Room no." ;
		getch() ;
		return ;
	}
	clrscr() ;
	DISPLAY_RECORD(rno,bno) ;
	gotoxy(5,25) ;
	cout <<"Press any key to continue..." ;
	getch() ;
}

void PATIENT :: DELETE_RECORD(int rno, int bno)
{
	fstream file ;
	file.open("PATIENT.DAT", ios::in) ;
	fstream temp ;
	temp.open("temp.dat", ios::out) ;
	file.seekg(0,ios::beg) ;
	while (!file.eof())
	{
		file.read((char *) this, sizeof(PATIENT)) ;
		if (file.eof())
			break ;
		if (rno != roomno || bno != bedno)
			temp.write((char *) this, sizeof(PATIENT)) ;
	}
	file.close() ;
	temp.close() ;
	file.open("PATIENT.DAT", ios::out) ;
	temp.open("temp.dat", ios::in) ;
	temp.seekg(0,ios::beg) ;
	while (!temp.eof())
	{
		temp.read((char *) this, sizeof(PATIENT)) ;
		if (temp.eof())
			break ;
		file.write((char *) this, sizeof(PATIENT)) ;
	}
	file.close() ;
	temp.close() ;
}

void PATIENT :: DISCHARGE(void)
{
	clrscr() ;
	char *t1, ch ;
	int  rno, bno, valid, t2 ;
	ROOM r ;
	do
	{
		valid = 1 ;
		gotoxy(5,5) ;
		cout <<"Room no. : " ;
		gotoxy(5,7) ;
		cout <<"Bed no.  : " ;
		gotoxy(5,25) ; clreol() ;
		cout <<"ENTER ROOM NO. OF THE PATIENT or <ENTER> FOR HELP" ;
		gotoxy(16,5) ; clreol() ;
		gets(t1) ;
		t2 = atoi(t1) ;
		rno = t2 ;
		if (t1[0] == '0')
			return ;
		if (strlen(t1) == 0)
		{
			valid = 0 ;
			r.LIST() ;
			clrscr() ;
		}
		if ((rno < 1 || rno > r.LAST_ROOMNO()) && valid)
		{
			valid = 0 ;
			gotoxy(5,25) ; clreol() ;
			cout <<"\7ENTER CORRECTLY" ;
			getch() ;
		}
	} while (!valid) ;
	do
	{
		valid = 1 ;
		gotoxy(5,5) ;
		cout <<"Room no. : " <<rno ;
		gotoxy(5,7) ;
		cout <<"Bed no.  : " ;
		gotoxy(5,25) ; clreol() ;
		cout <<"ENTER BED NO. OF THE PATIENT or <ENTER> FOR HELP" ;
		gotoxy(16,7) ; clreol() ;
		gets(t1) ;
		t2 = atoi(t1) ;
		bno = t2 ;
		if (t1[0] == '0')
			return ;
		if (strlen(t1) == 0)
		{
			valid = 0 ;
			r.LIST() ;
			clrscr() ;
		}
		if ((bno < 1 || bno > 2) && valid)
		{
			valid = 0 ;
			gotoxy(5,25) ; clreol() ;
			cout <<"\7ENTER CORRECTLY" ;
			getch() ;
		}
	} while (!valid) ;
	gotoxy(5,25) ; clreol() ;
	if (r.AVAILABLE(rno,bno))
	{
		gotoxy(5,20) ;
		cout <<"\7Sorry, there is no. Patient in this Room no." ;
		getch() ;
		return ;
	}
	clrscr() ;
	DISPLAY_RECORD(rno,bno) ;
	do
	{
		gotoxy(5,13) ; clreol() ;
		cout <<"Discharge this Patient (y/n) " ;
		ch = getche() ;
		ch = toupper(ch) ;
	} while (ch != 'Y' && ch != 'N') ;
	if (ch == 'N')
		return ;
	r.CHANGE_STATUS(rno,bno,'A') ;
	DELETE_RECORD(rno,bno) ;
	gotoxy(5,23) ;
	cout <<"\7Record Deleted" ;
	gotoxy(5,25) ;
	cout <<"Press any key to continue..." ;
	getch() ;
}

int PATIENT :: RECORDNO(int rno, int bno)
{
	fstream file ;
	file.open("PATIENT.DAT", ios::in) ;
	int recordno=0 ;
	while (file.read((char *) this, sizeof(PATIENT)))
	{
		recordno++ ;
		if (roomno == rno && bedno == bno)
			break ;
	}
	file.close() ;
	return recordno ;
}

void PATIENT :: MODIFY_RECORD(int rno, int bno, int rno1, int bno1, char pdoctor[26])
{
	int recno ;
	recno = RECORDNO(rno,bno) ;
	fstream file ;
	file.open("PATIENT.DAT", ios::out | ios::ate) ;
	roomno = rno1 ;
	bedno = bno1 ;
	strcpy(doctor,pdoctor) ;
	int location ;
	location = (recno-1) * sizeof(PATIENT) ;
	file.seekp(location) ;
	file.write((char *) this, sizeof(PATIENT)) ;
	file.close() ;
}

void PATIENT :: MODIFY(void)
{
	clrscr() ;
	char t1[5], ch, pdoctor[26] ;
	int  rno, bno, valid, t2, rno1, bno1, pd ;
	ROOM r ;
	do
	{
		valid = 1 ;
		gotoxy(5,5) ;
		cout <<"Room no. : " ;
		gotoxy(5,7) ;
		cout <<"Bed no.  : " ;
		gotoxy(5,25) ; clreol() ;
		cout <<"ENTER ROOM NO. OF THE PATIENT or <ENTER> FOR HELP" ;
		gotoxy(16,5) ; clreol() ;
		gets(t1) ;
		t2 = atoi(t1) ;
		rno = t2 ;
		if (t1[0] == '0')
			return ;
		if (strlen(t1) == 0)
		{
			valid = 0 ;
			r.LIST() ;
			clrscr() ;
		}
		if ((rno < 1 || rno > r.LAST_ROOMNO()) && valid)
		{
			valid = 0 ;
			gotoxy(5,25) ; clreol() ;
			cout <<"\7ENTER CORRECTLY" ;
			getch() ;
		}
	} while (!valid) ;
	do
	{
		valid = 1 ;
		gotoxy(5,5) ;
		cout <<"Room no. : " <<rno ;
		gotoxy(5,7) ;
		cout <<"Bed no.  : " ;
		gotoxy(5,25) ; clreol() ;
		cout <<"ENTER BED NO. OF THE PATIENT or <ENTER> FOR HELP" ;
		gotoxy(16,7) ; clreol() ;
		gets(t1) ;
		t2 = atoi(t1) ;
		bno = t2 ;
		if (t1[0] == '0')
			return ;
		if (strlen(t1) == 0)
		{
			valid = 0 ;
			r.LIST() ;
			clrscr() ;
		}
		if ((bno < 1 || bno > 2) && valid)
		{
			valid = 0 ;
			gotoxy(5,25) ; clreol() ;
			cout <<"\7ENTER CORRECTLY" ;
			getch() ;
		}
	} while (!valid) ;
	gotoxy(5,25) ; clreol() ;
	if (r.AVAILABLE(rno,bno))
	{
		gotoxy(5,20) ;
		cout <<"\7Sorry, there is no. Patient in this Room no." ;
		getch() ;
		return ;
	}
	clrscr() ;
	DISPLAY_RECORD(rno,bno) ;
	do
	{
		gotoxy(5,13) ; clreol() ;
		cout <<"Modify this Patient Record (y/n) " ;
		ch = getche() ;
		ch = toupper(ch) ;
	} while (ch != 'Y' && ch != 'N') ;
	if (ch == 'N')
		return ;
	do
	{
		valid = 1 ;
		clrscr() ;
		gotoxy(29,1) ;
		cout <<"MODIFY PATIENT RECORD" ;
		gotoxy(29,2) ;
		cout <<"~~~~~~~~~~~~~~~~~~~~~" ;
		gotoxy(5,4) ;
		cout <<"Room no. : " ;
		gotoxy(5,6) ;
		cout <<"Bed no.  : " ;
		do
		{
			valid = 1 ;
			gotoxy(5,25) ; clreol() ;
			cout <<"ENTER ROOM NO. OF THE PATIENT" ;
			gotoxy(16,4) ; clreol() ;
			gets(t1) ;
			t2 = atoi(t1) ;
			rno1 = t2 ;
			if (t1[0] == '0')
				return ;
			if (rno1 < 1 || rno1 > r.LAST_ROOMNO())
			{
				valid = 0 ;
				gotoxy(5,25) ; clreol() ;
				cout <<"\7ENTER CORRECTLY" ;
				getch() ;
			}
		} while (!valid) ;
		do
		{
			valid = 1 ;
			gotoxy(5,25) ; clreol() ;
			cout <<"ENTER BED NO. OF THE PATIENT" ;
			gotoxy(16,6) ; clreol() ;
			gets(t1) ;
			t2 = atoi(t1) ;
			bno1 = t2 ;
			if (t1[0] == '0')
				return ;
			if (bno1 < 1 || bno1 > 2)
			{
				valid = 0 ;
				gotoxy(5,25) ; clreol() ;
				cout <<"\7ENTER CORRECTLY" ;
				getch() ;
			}
		} while (!valid) ;
		gotoxy(5,25) ; clreol() ;
		if (!r.AVAILABLE(rno1,bno1) && (rno1 != rno || bno1 != bno))
		{
			valid = 0 ;
			gotoxy(5,20) ;
			cout <<"\7Sorry, there is already a Patient in this Room no." ;
			getch() ;
		}
	} while (!valid) ;
	DOCTOR dr ;
	dr.LIST() ;
	do
	{
		valid = 1 ;
		gotoxy(5,25) ; clreol() ;
		gotoxy(5,24) ; clreol() ;
		cout <<"ENTER S.No. OF THE DOCTOR  " ;
		gets(t1) ;
		t2 = atoi(t1) ;
		pd = t2 ;
		if (t1[0] == '0')
			return ;
		if (pd < 1 || pd > dr.RECORDS())
		{
			valid = 0 ;
			gotoxy(5,25) ; clreol() ;
			cout <<"\7ENTER CORRECTLY" ;
			getch() ;
		}
	} while (!valid) ;
	strcpy(pdoctor,dr.DOCTOR_NAME(pd)) ;
	gotoxy(5,8) ;
	cout <<"Doctor Assigned : Dr." <<pdoctor ;
	r.CHANGE_STATUS(rno,bno,'A') ;
	r.CHANGE_STATUS(rno1,bno1,'N') ;
	MODIFY_RECORD(rno,bno,rno1,bno1,pdoctor) ;
	gotoxy(5,23) ;
	cout <<"\7Record Modified" ;
	gotoxy(5,25) ;
	cout <<"Press any key to continue..." ;
	getch() ;
}

void main(void)
{
	MENU menu ;
	menu.MAIN_MENU() ;
}

