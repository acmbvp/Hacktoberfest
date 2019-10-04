#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<dos.h>
struct tim
{   double t;
    char ch;
}itime;

void fopen(fstream &);
void fwrite(fstream &);
void stop(double);

void main()
{ clrscr();
  st:
  cout<<"\nChoose one of below \n1.open \n2.write \n3.exit \n";
  int ch;
  cin>>ch;
  char str[20]="";
  fstream f;

  if(ch==1)
  {    cout<<"\nenter file name :";
       gets(str);
       f.open(str,ios::in|ios::binary);
       fopen(f);
       f.close();
       cout<<"\nPress any key to goto main menu...";
       getch();
       goto st;
  }
  else if(ch==2)
  {    cout<<"\nenter file name :";
       gets(str);
       f.open(str,ios::out|ios::binary);
       fwrite(f);
       f.close();
       goto st;
  }
  else if(ch==3)
  {
       return;
  }
  else
  {  cout<<"\nwrong choose !!! \nRESTARTING ...";
     delay(2000);
     clrscr();
     goto st;
  }
  getch();
}
void stop(double d)
{
   time_t ft,lt;
   ft=time(NULL);
   while(difftime(lt,ft)!=d)
     lt=time(NULL);
}
void fopen(fstream &f)
{
   clrscr();
   while(!f.eof())
   {
       f.read((char *)&itime,sizeof(itime));
       stop(itime.t);
       if(itime.ch==13)
	 cout<<'\n';
       else
	 cout<<itime.ch;
   }
}
void fwrite(fstream &f)
{
    time_t ft,lt;
    char ch=0;
    cout<<"\nPress 'esc' to jump to main menu ,Press any key to continue..";
    getch();
    clrscr();
    while(ch!=27)
    {  ft=time(NULL);
       ch=getch();
       if(ch==13)  cout<<'\n';
       else        cout<<ch;
       lt=time(NULL);
       itime.ch=ch;
       itime.t=difftime(lt,ft);
       f.write((char *)&itime,sizeof(itime));
    }
}