// AISHA IRFAN 
//20i-1851
//Project: KING AND 2 KNIGHTS
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
//globally declared variables
char const row=8;
char const col=8;
int r,c,r1,c1,r2,c2;
char board[row][col], b[row][col];
char x,y,opt,king='f';
//globally declared functions
void display();
void input();
void movesNdisp(char x, char y);
char checkKing();
void start();
void bequal();
void movesK(int x, int y);
void opponentTurn();
char checkKnight(char n);

void display()//displays array
{
	char (*ptr)[8]=b;
	cout << "   0  1  2  3  4  5  6  7\n";
	for(int i=0;i<8;i++)
	{
		cout << i << "  "; 
		for(int j=0;j<8;j++)
		{
			cout << *(*(ptr+i)+j) << "  ";
		}
		cout << endl;
	}
}


void bequal()//equate main board to new array to stop from messing up the original chessboard
{
	char (*ptr)[8]=board;
	for (int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			b[i][j]=*(*(ptr+i)+j);
		}
	}
}


void input()//menu
{
	char (*ptr)[8]=board;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			*(*(ptr+i)+j)='-';
		}
	}
	bequal();
	char choice;
	cout << "Choose the combination of your choice\n1. King and 2 rocks\n2. King and 2 Bishops\n3. King and 2 Knights\n4. King and Queen\n";
	cin >> choice;
	choice = 3;// as assigned for project
	switch(choice)
	{
		case 1:
		{
			cout << "Functionality Unavailable\n";
			break;
		}
		case 2:
		{
			cout << "Functionality Unavailable\n";
			break;
		}
		case 3:
		{
			//taking input for initial positions of selected pieces
			cout << endl;
			cout << "-----For King's Position-----\nEnter Row Number from 0-7: ";
			cin >> r;
			while(r>7||r<0)//check for valid input
			{
				cout << "Enter VALID Row Number from 0-7: ";
				cin >> r;
			}
			cout << "Enter column Number from 0-7: ";
			cin >> c;
			while(c>7||c<0)//check for valid input
			{
				cout << "Enter VALID Column Number from 0-7: ";
				cin >> c;
			}
			do
			{
				cout << endl;
				cout << "-----For Knight1's Position-----\nEnter Row Number from 0-7: ";
				cin >> r1;
				while(r1>7||r1<0)//check for valid input
				{
					cout << "Enter VALID Row Number from 0-7: ";
					cin >> r1;
				}
				cout << "Enter column Number from 0-7: ";
				cin >> c1;
				while(c1>7||c1<0)//check for valid input
				{
					cout << "Enter VALID Column Number from 0-7: ";
					cin >> c1;
				}
				cout << endl;
				cout << "-----For Knight2's Position-----\nEnter Row Number from 0-7: ";
				cin >> r2;
				while(r2>7||r2<0)//check for valid input
				{
					cout << "Enter VALID Row Number from 0-7: ";
					cin >> r2;
				}
				cout << "Enter column Number from 0-7: ";
				cin >> c2;
				while(c2>7||c2<0)//check for valid input
				{
					cout << "Enter VALID Column Number from 0-7: ";
					cin >> c2;
				}
			}while((r1==r2)&&(c1==c2));//so knight 1 does not overlap knight 2
			*(*(ptr+r)+c) = 'k';
			*(*(ptr+r1)+c1) = 'n';
			*(*(ptr+r2)+c2) = 'N';
			bequal();
			display();
			
			break;
		}
		case 4:
		{
			cout << "Functionality Unavailable\n";
			break;
		}
		default:
		{
			cout << "INVALID REQUEST\n";
			break;
		}
	}
}


char checkKing()//check if king is still present for position validation
{
	bequal();
	movesNdisp(r1,c1);
	movesNdisp(r2,c2);
	for (int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(b[i][j]=='k')
			{
				king='p';
			
			}
		}
	}
	return king;
}


void movesNdisp(char x, char y )//displays knights moves to player
{
	if(((x+2<8)&&(x+2>=0))&&((y+1<8)&&(y+1>=0))) 
	{
		b[x+2][y+1]='#';
	}
	if(((x+2<8)&&(x+2>=0))&&((y-1<8)&&(y-1>=0))) 
	{
		b[x+2][y-1]='#';	
	}
	if(((x-2<8)&&(x-2>=0))&&((y+1<8)&&(y+1>=0))) 
	{
		b[x-2][y+1]='#';
	}
	if(((x-2<8)&&(x-2>=0))&&((y-1<8)&&(y-1>=0))) 
	{
		b[x-2][y-1]='#';
	}
	if(((x+1<8)&&(x+1>=0))&&((y+2<8)&&(y+2>=0))) 
	{
		b[x+1][y+2]='#';
	}
	if(((x-1<8)&&(x-1>=0))&&((y+2<8)&&(y+2>=0))) 
	{
		b[x-1][y+2]='#';
	}
	if(((x+1<8)&&(x+1>=0))&&((y-2<8)&&(y-2>=0))) 
	{
		b[x+1][y-2]='#';
	}
	if(((x-1<8)&&(x-1>=0))&&((y-2<8)&&(y-2>=0))) 
	{
		b[x-1][y-2]='#';
	}
}


void opponentTurn()//opponent's turn to move knights
{
	int a,d;
	char l;
	do//moves validation
	{
		do
		{	
			l='x';
			cout << "Enter New position for knight '" << opt <<"' \nEnter row: \n";
			cin >> a;
			cout << "Enter column: \n";
			cin >> d;
			if(opt=='n')
			{			
				if((a==(r1+2))&&(d==c1+1))
				{
					l='n';
				}
				else if((a==r1+2)&&(d==c1-1))
				{
					l='n';
				}
				else if((a==r1-2)&&(d==c1+1))
				{
					l='n';
				}
				else if((a==r1-2)&&(d==c1-1))
				{
					l='n';
				}
				else if((a==r1+1)&&(d==c1+2))
				{
					l='n';
				}
				else if((a==r1+1)&&(d==c1-2))
				{
					l='n';
				}
				else if((a==r1-1)&&(d==c1+2))
				{
					l='n';
				}
				else if((a==r1-1)&&(d==c1-2))
				{
					l='n';
				}
				else {l='x';}
			}
			else if(opt=='N')
			{
				if((a==r2+2)&&(d==c2+1))
				{
					l='N';
				}
				else if((a==r2+2)&&(d==c2-1))
				{
					l='N';
				}
				else if((a==r2-2)&&(d==c2+1))
				{
					l='N';
				}
				else if((a==r2-2)&&(d==c2-1))
				{
					l='N';
				}
				else if((a==r2+1)&&(d==c2+2))
				{
					l='N';
				}
				else if((a==r2+1)&&(d==c2-2))
				{
					l='N';
				}
				else if((a==r2-1)&&(d==c2+2))
				{
					l='N';
				}
				else if((a==r2-1)&&(d==c2-2))
				{
					l='N';
				}
				else {l='z';}	
			}
		}while((l=='x')||(l=='z'));
		if(l=='n')
		{
			board[r1][c1]='-';
			board[a][d]='n';
			r1=a;
			c1=d;
		}
		else
		{
			board[r2][c2]='-';
			board[a][d]='N';
			r2=a;
			c2=d;
		}
		if((r1==r2)&&(c1==c2))
		{
			cout << "INVALID MOVE\nKnights overlap eachother\n";
		}
	}while((r1==r2)&&(c1==c2));
	
}
	
	
void movesK(int x,int y)//randomly generated kings moves 
{
	do
	{
		
		srand(time(NULL));
		int q,w;//storage variables
		q=x;
		w=y;
		char choice=rand()%8;
		board[x][y]='-';
		if(choice==0)	
		{
			if(((x+1<8)&&(x+1>=0))&&((y+1<8)&&(y+1>=0)))
			{
				x=x+1;
				y=y+1;
			}
		}
		else if(choice==1)
		{
			if(((x-1<8)&&(x-1>=0))&&((y+1<8)&&(y+1>=0)))
			{
				x=x-1;
				y=y+1;
			}
		}
		else if(choice==2)
		{
			if(((x<8)&&(x>=0))&&((y+1<8)&&(y+1>=0)))
			{
				x=x;
				y=y+1;
			}
		}
		else if(choice==3)
		{
			if(((x+1<8)&&(x+1>=0))&&((y<8)&&(y>=0)))
			{
				x=x+1;
				y=y;
			}
		}
		else if(choice==4)
		{
			if(((x-1<8)&&(x-1>=0))&&((y<8)&&(y>=0)))
			{
				x=x-1;
				y=y;
			}
		}
		else if(choice==5)
		{
			if(((x+1<8)&&(x+1>=0))&&((y-1<8)&&(y-1>=0)))
			{
				x=x+1;
				y=y-1;
			}
		}
		else if (choice==6)
		{
			if(((x-1<8)&&(x-1>=0))&&((y-1<8)&&(y-1>=0)))
			{
				x=x-1;
				y=y-1;
			}
		}
		else if (choice==7)
		{
			if(((x<8)&&(x+1>=0))&&((y-1<8)&&(y-1>=0)))
			{
				x=x;
				y=y-1;
			}
		}
		board[x][y]='k';
		bequal();
		movesNdisp(r1,c1);
		movesNdisp(r2,c2);
		king='f';
		king=checkKing();
		if(king=='f')
		{
			board[x][y]='-';
			x=q;//original value is stored in y
			y=w;//original value is stored in x
		}
		
	}while(king=='f');
	cout << "KING HAS MOVED\n";
	bequal();
	display();
	r=x,c=y;
}


void start()//game begins
{
	cout << "*___________________CHESS BOARD GAME BEGINS___________________*\n";
	cout << "'k' represents king, 'n' represents knight1, 'N' represents knight2\n";
	do
	{
		input();
		checkKing();
		if(king=='f')
		{
			cout << "Invalid positions set for chess pieces\n";
		}
	}while(king!='p');
	char quit;
	do
	{
		do
		{
			cout << "Enter 'n' to display moves for knight1 and 'N' to display moves for knight2: \n";
			cin >> opt;
		}while((opt!='n') && (opt!='N'));
		bequal();
		if(opt=='n')
		{
			movesNdisp(r1,c1);
		}
		if(opt=='N')
		{
			movesNdisp(r2,c2);
		}
		display();
		cout << " '#' shows where your knight can move to.\n";
		opponentTurn();
		cout << "KNIGHT HAS MOVED\n";
		bequal();
		display();
		movesK(r,c);
		if(((r==r1)&&(c==c1))||((r==r2)&&(c==c2)))//game cannot progress further if one knight is killed
		{
			cout << "YOUR KNIGHT HAS BEEN KILLED\n*****GAME OVER*****\n";
			break;
		}
		cout << "Quit Game? \n(y/n): ";
		cin >> quit;
	}while(quit=='n');
}

	
int main()
{
	start();	
	return 0;
}

	
		
		
	
