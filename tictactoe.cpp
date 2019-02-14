#include <iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

int check_winning(char a[3][3])
{
	int flag, i, j;

	
//for checking rowss
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 2; ++j)
		{ 

		  if( (a[i][j] != a[i][j+1]) )
			break;
		}

		if (j == 2)
			return 1;
	}

//for checking columnss
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 2; ++j)
		{ 

		  if( (a[j][i] != a[j+1][i]) )
			break;
		}

		if (j == 2)
			return 1;
	}

//for checking diagonal 1
	for (i = 0; i < 2; ++i)
	{
		if(a[i][i] != a[i+1][i+1])
			break;
	}

	if(i == 2)
		return 1;

//for checking diagonal2
	for (i = 0; i < 2; ++i)
	{
		if(a[i][2-i] != a[i+1][abs(i-1)] )
			break;
	}

	if(i == 2)
		return 1;

	return 0;
}

void display(char t[3][3])
{
	for (int i = 0; i < 3; ++i)
	cout<<"====";

	cout<<endl;

	for(int i = 0; i < 3; i++)
	{ 
		cout<<"| ";

		for (int j = 0; j < 3; ++j)
		{
			cout<<t[i][j]<<" | ";
		}
		cout<<endl;

	//for (int k = 0; k < 3; ++k)
	//cout<<"====";

	//if(i != 2)
	//cout<<endl;


	}

	for (int i = 0; i < 3; ++i)
	cout<<"====";
	
}

int main()
{
	char t[3][3] = { {'0', '1', '2'}, {'3', '4', '5'}, {'6', '7', '8'}

	};
	int index, count = 0;

//  clrscr();
	cout<<"\t\tTIC TAC TOE\n";

	display(t);


	while(count < 9)
	{
		inputX:
		cout<<"\nPlayer 1: ";

		cin>>index;

		if(index > 8)
		{
			cout << "Wrong input";
			goto inputX;
		}

		else if((t[index/3][index%3] != 'X') && (t[index/3][index%3] != 'O'))
			t[index/3][index%3] = 'X';
		else
		{   
			cout<<"\nEnter again: ";
			goto inputX;
		}
		
		display(t);

		if(check_winning(t) == 1)
		{   
			cout<<"\nPlayer1 won\n";
			exit(0);
		}
		count++;


		if(count == 9)
			break;

		inputO:
		cout<<"\nPlayer 2: ";
		cin>>index;

		if(index > 9)
		{
			cout << "Wrong input";
			goto inputO;
		}

		else if((t[index/3][index%3] != 'X') && (t[index/3][index%3] != 'O'))
			t[index/3][index%3] = 'O';

		else
		{
			cout<<"\nEnter again: ";
			goto inputO;
		}

		display(t);

		if(check_winning(t) == 1)
		{
			cout<<"\nPlayer2 won\n";
			exit(0);
		}

		count++;
	}


	cout<<"\n-------GAME OVER-------\n";
}
