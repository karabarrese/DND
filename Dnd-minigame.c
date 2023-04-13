//	
//	DND Mini-game!
//	winter 2023
//	author: Kara Barrese 
//


//  includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // for random numbers?
#include <stdbool.h> // for booleans
#include <ctype.h>// for evaluating input

// defines
const int MAX_PEOPLE = 10; // somehow try and get the struct to use this instead of 10 for length?
const int MAX_BOARDS = 10;
char north = '^';
char east = '>';
char south = 'v';
char west = '<';

//global variables
typedef struct person 
{
    //initial x pos
	int in_x;
    //initial y pos
	int in_y;

    //current x pos
	int cur_x;
    //current y pos
	int cur_y;

    //current direction {union?:(1,2,3,4) (^,>,v,<)}
	char cur_dir;

	char in_dir;

	/*//are they playable?
	bool is_playable_character;
	*/
	//instead of ^^, just put symbol that represents them
	char rep[100];

	// if they follow path differently like inversely or something, put it here
	int relation_to_player; // 1= follows, 2= does opposite, 
	//future: 3= waits one move and then does it?

}PERSON;

//don't they all need to be playable?

// how to write a board that can be a certain length but isn't determined

typedef struct board
{
    //length
	int length;
    //width
	int width;
    //num of people
	int num_people;
    //array of pointers to people max 10
	PERSON people[MAX_PEOPLE];

	/*	
		future: 
		the max # of people should be the amount of squares? 
		which is the length X width right?
		how do I make this initialize without a limit or define the 
		limit once the other stuff is defined
		what's the use of a union again? doesn't it use the other 
		variables to define the first one
		what if, a union that is an array of pointers to people but only 
		is decided based on the length & width
		- i think a union might not be able to do that :(
	*/
}BOARD;

char representation[2]= {' ',' '};

BOARD *boards[MAX_BOARDS];
int num_boards;

//functions
void new_board();
void show_board(BOARD *B);
int what_is_here(BOARD *B, int i, int j);
void new_person(BOARD *B);
void print_demo_board(int num_rows, int num_cols);
void pick_board();
void play(BOARD *B);
void reset(BOARD *B);

void show_board(BOARD *B)
{
	int i,j = 0;
	for(i=0; i<(B->length);i++)
	{
		for(j=0;j<(B->width);j++)
		{
			printf("[%s] ", representation);
		}
		printf("\n");
	}
}

int what_is_here(BOARD *B, int i, int j)
{
	representation[0] = ' ';
	representation[1] = ' ';
	int m;
	int num_people_on_spot = 0;
	for(m=0; m<= b->num_people; m++)
	{
		if((B->people[m]->cur_x == i)&&(B->people[m]->cur_y == j))
		{
			num_people_on_spot++;
			representation[0] = B->people[m]->rep;
			representation[1] = B->people[m]->cur_dir;
			return 1; // returns 1 if there's a person there
			//could return num of people?
		}
	}
	return 0;
	/*if (num_people_on_spot>1)
	{
		reset(B);
	}
	return num_people_on_spot;*/
	//this would make it slightly slower and idk if it's needed so i'll keep it ^
}

void new_board()
{
	
	BOARD *B;
	int n_rows, n_cols, n_people = 0;

	printf("in new_board function!\n");

	if (num_boards == MAX_BOARDS)
	{
		printf("no more saves for boards :(\n");
	}

	printf("How wide should the board be?",);
    fpurge(stdin);
	scanf ("%d", &n_cols);
	if(n_cols>0)
	{
		B->width = n_cols;
	}
	else
	{
		printf("invalid columns\n");
		new_board();
		return;
	}

	printf("How wide should the board be?",);
    fpurge(stdin);
	scanf ("%d", &n_rows);
	if(n_rows>0)
	{
		B->length = n_rows;
	}
	else
	{
		printf("invalid rows\n");
		new_board();
		return;
	}

	B->num_people = n_people;
	new_person(B);

	if (num_boards!=0)
	{
		boards[num_boards-1] = B;
	}
	else
	{
		boards[0] = B;
		printf("first board placed!\n");
	}
	num_boards++;
	return;
}

//future: make different functions for each variable inputted that you can call if inputted wrong with recursion!
//recursive and goes till people doesn't exceed total num of people 
void new_person(BOARD *B)
{
	PERSON P;
	int x_pos, y_pos, direction, representation, rel_to_player, make_more;
	int n_rows = B->length;
	int n_cols = B->width;
	int n_people_place = (B -> num_people)-1;

	if((B->num_people)==MAX_PEOPLE)
	{
		printf("Can't make any new people!\n");
		return;
	}
	else if ((B->num_people) == 0)
	{
		n_people_place = 0;
	}
	

	printf("in new_person function (get ready to make a cool human!)\n");


	printf("Where do you want your person to be?:\n");
	print_demo_board(B->width, B->length); // this is the x,y or i,j
	printf("What column do they start on?\n    - this would be the B in [A x B] for where you want it)\n    - must be between 0 - %d\n",n_rows);
    fpurge(stdin);
	scanf ("%d", &x_pos);
	// do validation later
	// should take care of number input maybe?

	if(x_pos>n_rows)
	{
		printf("That column doesn't exist, try again and make sure it's %d or below:\n", n_rows);

		//recursion!
		new_person(B); // do I put in *B or B here?

		return;
		//is return needed?
	}


	printf("What row do they start on?\n    - this would be the B in [A x B] for where you want it)\n    - must be between 0 - %d\n",n_cols);
    fpurge(stdin);
	scanf ("%d", &y_pos); 
	// do validation later
		// can use isdigit() with new library :>
	// should take care of number input maybe

	if(y_pos>n_cols)
	{
		printf("That row doesn't exist, try again and make sure it's %d or below:\n", n_cols);

		//recursion!
		new_person(B); // do I put in *B or B here?

		return;
		//is return needed?
	}
	else
	{
		printf("valid input");
	}

	printf("What symbol would you like to represent the person?:\n");
    fpurge(stdin);
	scanf ("%s", P.rep);

	printf("What is this person?\n    1: they follow the inputs\n    2: they go opposite from the main person\n");
	fpurge(stdin);
	scanf("%d", &P.relation_to_player);

	printf("What direction are they starting off in?\n    1: north (^)\n    2: east (>)\n    3: south (v)\n    4: west (<)\n");
	fpurge(stdin);
	scanf("%d", &rel_to_player);
	
	if((rel_to_player<0) || (rel_to_player>5))
	{
		printf("That's not a valid direction, please pick a number from 1-4!\n");
		new_person(B);
		return;
	}

	P.in_x = x_pos;
	P.cur_x = x_pos;
	P.in_y = y_pos;
	P.cur_y = y_pos;

	//i think it might be simpler to store a value and then read if it's within 2 spaces of the value
	switch(rel_to_player){
		case 1:
			P.in_dir = '^';
			P.cur_dir = '^';
		case 2:
			P.in_dir = '>';
			P.cur_dir = '>';
		case 3:
			P.in_dir = 'v';
			P.cur_dir = 'v';
		case 4:
			P.in_dir = '<';
			P.cur_dir = '<';
		default:
			printf('no valid direction? setting to '^'\n');
			P.in_dir = '^';
			P.cur_dir = '^';
	}

	B->people[n_people_place] = P;
	B->num_people++;

	printf("Do you want to make another person? (1 = yes, 2 = no):\n");
	fpurge(stdin);
	scanf("%d", &make_more);
	if(make_more == 1)
	{
		new_person(B);
		return;
	}
	else if (make_more == 2)
	{
		return;
	}
	return;
}

void print_demo_board(int num_rows, int num_cols)
{
	int i,j=0;

	printf("Demo Board: \n");

	for(i=0;i<num_rows,i++)
	{
		for(j=0;j<num_cols,j++)
		{
			printf("[%d x %d] ", i, j);
		}
		printf("\n");
	}
	printf("\n");
}

//asks the user which board they want to play with 
void pick_board()
{
	printf("in pick board function\n");
	//listing boards
	int i, brd;
	for(i=1;i<=num_boards;i++)
	{
		printf("1: Board #%d \n", i);
	}

	printf("which board would you like to play on?\n");
	fpurge(stdin);
	scanf("%d", &brd);

	printf("choose which direction you'd like to move in and type in an answer whenever prompted with ">"\n    W: north (^)\n    A: west (<)\n    S: south (v)\n    D: east (>)\nTry not to get players to overlap!\nHave fun :)\n");
	play(boards[brd-1]);
}

void play(BOARD *B)
{
	
	int i, j, k = 0;
	char direction;

	while(lose(B) != 0)
	{
		printf("\n>");
		fpurge(stdin);
		scanf("%s", direction);

		switch(direction) {
			case 'W':
				move(B,north);
			case 'A':
				move(B,east);
			case 'S':
				move(B,south);
			case 'D':
				move(B,west);
			default:
				printf("invalid input\n");
		}
	}
}

void forward(BOARD *B, char direction)
{
	int i;
	for(i=0;i<B->num_people;i++)
	{
		//if direction matches B->people[i]->cur_dir
	}
		/*//if(strcmp(B->people[i]->cur_dir,north) == 0)
		//north
		if(strcmp(B->people[i]->cur_dir,direction) == 0)
		{
			if((B->people[i]->cur_y)>0) && (B->people[i]->cur_y)<=((B->length))
			{
				B->people[i]->cur_y--;
			}
		}
		else if(strcmp(B->people[i]->cur_dir, direction) == 0) //south
		{
			if(((B->people[i]->cur_y)>=0) && (B->people[i]->cur_y)<((B->length)-1))
			{
				B->people[i]->cur_y++;
			}
		}
		else if(strcmp(B->people[i]->cur_dir,east) == 0)
		{
			if(((B->people[i]->cur_x)>=0) && (B->people[i]->cur_y)<((B->width)-1))
			{
				B->people[i]->cur_y++;
			}
		}
		else if(strcmp(B->people[i]->cur_dir,west) == 0)
		{
			if(((B->people[i]->cur_x)>0) && (B->people[i]->cur_x)<((B->width)))
			{
				B->people[i]->cur_x--;
			}
		}


	}*/
	/*for(i=0;i<B->num_people;i++)
	{
		switch(B->people[i]->cur_dir)
		{
			case '^':
				if(((B->people[i]->cur_y)>0) && (B->people[i]->cur_y)<=((B->length)))
				{
					B->people[i]->cur_y--;
				}
			/*case 'v':
				if(((B->people[i]->cur_y)>=0) && (B->people[i]->cur_y)<((B->length)-1))
				{
					B->people[i]->cur_y++;
				}
			case '<':
				if(((B->people[i]->cur_x)>0) && (B->people[i]->cur_x)<((B->width)))
				{
					B->people[i]->cur_x--;
				}
			case '>':
				if(((B->people[i]->cur_x)>=0) && (B->people[i]->cur_y)<((B->width)-1))
				{
					B->people[i]->cur_y++;
				}*/
			case '<':
				B->people[i]->cur_dir = '^';
			case '>':
				B -> people[i]->cur_dir = '^';
			default:
				printf("doesn't have an arrow?\n");
		}

	}
	*/
}

//checks to see if there is more than one person on a spot
//returns 1 if you lose
int lose(BOARD *B)
{
	int i, j =0;
	for(i=0;i<(B->num_people);i++)
	{
		for(j=0;j<(B->num_people);j++)
		{
			if(((B->people[i]->x_pos) == (B->people[j]->x_pos)) && ((B->people[i]->y_pos) == (B->people[j]->y_pos)))
			{
				return 1;
			}
		}
	}
	return 0;
}
//resets people to their starting positions
void reset(BOARD *B)
{
	int i =0;
	for(i=0;i<(B->num_people);i++)
	{
		B->people[i]->x_pos = B->people[i]->in_x;
		B->people[i]->y_pos = B->people[i]->in_y;
	}
	return;
}

//future list stuff might be needed
//list  *board[];
//make a list of pointers to new boards

// create an array of boards where you select which one and can make new ones
// each one will have a 2D array of people and where they are
// when you select one it will put people at their starting positions
//print function will print the board at any position
// going forward changes current x pos to +1 if 2, -1 if 4 and y pos to be +1 if 1, and -1 if 3. 



int main (void)
{
	int option;

	while (1)
	{
		printf ("Choose an option:\n    1: make new board\n    2: see boards & pick which one to play\n    0: exit\nEnter option: ");
		if (scanf ("%d", &option) != 1)
		{
			printf ("error\n");
			return 0;
		}

		switch (option)
		{
			case 1:
				printf("make new board:\n");
				new_board();				
				break;
			case 2:
				printf("seeing boards:\n");
				pick_board();		
				break;

			default:
				printf ("wrong option\n");
		}
	}	
}