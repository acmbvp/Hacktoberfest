#include<iostream>
#include<string>
using namespace std;
int main()
{

	int chances=5,number=0,i,j,win=0;
	// i and used for iteration of loops
	// chances for number of chances
	// number tocount number of letter
	// to exit the loop if won
	char choice,letter;

	string word,duplicate,used,guess,hint;

	// Word is used to input Word
	// duplicate for duplicate String
	// Choice to guess letter or Word
	// Letter for player 2 to guess Letter
    // used for used letters
    // guess for guessed word by player 2
    // hint for a hint
	cout<<"Hangman Game";
	cout<<"\n\n";
	cout<<"Player's 1 turn.Player 1 needs to enter word-";
	getline(cin,word);  //Input String
	cout<<word<<endl;;
	cout<<"Enter hint for Player 2-";
	getline(cin,hint);
	cout<<hint<<endl;
	for(i=0;word[i]!='&#092;&#048;';i++)
		word[i]=toupper(word[i]); //Convert the input String into uppercase


	system("clear"); // Clear the entered string
	cout<<"\nNow It is time for Player 2 to guess ";

	for(i=0;word[i]!='&#092;&#048;';i++)
	{	cout<<"-" ; //Convert the input String into dashes
	    duplicate[i]='-';
	}

	cout<<"\n\n";
	cout<<"Player 2 have 5 chances to guess the word"<<endl;
	cout<<"In the end Player 2 needs to enter the full word\n\n";

	do
	{
		cout<<"1.Guess Letter\n";
		cout<<"2.Guess Word\n";
		cout<<"Enter choice-";
		cin>>choice;
		cout<<choice<<endl;

		if(choice=='1')
		{   number++;
			int flag=0; // To check character present or not
			cout<<"Enter character-";
			cin>>letter;
			letter=toupper(letter); // Convert into Upper case
			cout<<letter<<endl;
			used[number]=letter;// To show used letters

			for(i=0;word[i]!='&#092;&#048;';i++)
				if(word[i]==letter) // To check whether character is present
				{
					duplicate[i]=word[i];
					flag=1;;
				}

			for(j=0;j<i;j++)
				cout<<duplicate[j];     // To show Duplicate string

			cout<<endl;
			if (flag!=0)
			    cout<<"Letter found\n";
			else
			{
				chances--;
				cout<<"Letter not found\n";
				cout<<"No. of chances are "<<chances;
				cout<<endl;
			}
			cout<<"Letter used\n";
			for(int f=1;f<=number;f++)
				cout<<used[f]<<","; //To display used letters
			cout<<endl<<endl;
			if(chances==0)
			{
				cout<<"You have lost.\n";
				cout<<endl;
			}
		}
		if(choice=='2')
		{
			cout<<"Enter word-";
		    cin>>guess;
			cout<<guess<<endl;
			for(i=0;guess[i]!='&#092;&#048;';i++)
		        guess[i]=toupper(guess[i]); //Convert the input String into uppercase

			int x = word.compare(guess); // 0 if strings are same
			if (x==0)
			{
			    cout<<"Player 1 won";
			    win=1;
			}
			else
			{
				chances--;
				cout<<"The answer is not correct.Try again.\n";
				cout<<"Chances left\n"<<chances<<endl;
			}
		cout<<endl;
		if(chances==0)
		{
			cout<<"You have lost\n";
		}
		}
	}while(chances>0 && win!=1) ;
	return 0;
}
