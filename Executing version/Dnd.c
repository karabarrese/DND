#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//attack bonuses/stats -> how much extra damage it does if it hits, it's a strength score
/*number of attacks
to hit bonuses
dice definitions
crit bonus damage
mini crit damage
role attack
determine hit, mini- crit, crit, miss (determine which one happens)
display damage*/

int party_ac = 16;

typedef struct monster 
{
    char monster_name[100];
    //d20 roll plus melee weapon attack
    int melee_weapon_attack;
    int num_dice;
    int type_of_dice;
    int add_to_attack;

}MONSTER;

MONSTER monsters[100];
int num_monsters = 0;

void display_damage(MONSTER m);

void list_monsters()
{
   // printf("first monster numdice: %d \n", monsters[0]-> num_dice);
    printf("in list monster function montster!\n");
    if(num_monsters == 0)
    {
        printf("no monsters yet!\n");
        return;
    }
    //int i = num_monsters;
    
    /*int i = 0;
    printf("1!\n");
    MONSTER  *P;
    P = monsters[0];
    printf("2!\n");
    int index = i+1;
    printf("3!\n");
    while(P!= NULL)
    {
        printf("Monster #%d: %s\n", index, P -> monster_name);
        P++;
    }*/
    /*if (monsters[0]==NULL)
    {
        printf("no monsters yet!\n");
        return;
    }*/
    int i = 0;
    for(i = 0; i < num_monsters; i++)
    {
        int index = i+1;
        printf("Monster #%d: %s\n", index, monsters[i].monster_name);
    }
    
    printf("Which would you like to display damage for (pick a number):\n");
    fpurge(stdin);
    int nm;
	scanf("%d", &nm);
    int num_monster = nm-1;
    if(num_monster>num_monsters)
    {
        printf("no monsters @ #%d\n ", num_monster);
        return;
    }
    else
    {
        display_damage(monsters[num_monster]);
        return;
    }
}

void display_damage(MONSTER m)
{
    int lower = 1, upper = 20, min = 1, max = m.type_of_dice, i = 0, dmg = 0;
    int d20roll = (rand() % (upper - lower +1)) + lower;
    printf("you rolled a %d\n", d20roll);
    //int mini_crit = ?;
    if((((m.melee_weapon_attack))+(d20roll)) > (party_ac + 10))
    {
        //if it exceeds party's ac by 10, roll max dmg
        dmg = (((m.type_of_dice)*(m.num_dice)) + m.add_to_attack);
        printf("WOWZA!!! Nice shot! %d damage\n", dmg);
        return;
    }
    else if(((m.melee_weapon_attack)+(d20roll)) > party_ac)
    {
        //THIS FUNCTION IS WAY TOO MUCH
        int min = 1, max = m.type_of_dice;
        for (i=0; i <( m.num_dice); i++)
        {
            dmg +=( (rand() % (max - min +1)) + min);
        }
        dmg += m.add_to_attack;
        printf("Nice shot! %d damage\n", dmg);
        return;
    }
    else
    {
        printf("Miss! %d was so close\n", d20roll);
        return;
    }

}

void create_new_monster()
{
    int mwa,nd,tod,ata , i;
    MONSTER m;

    printf("What type of monster do you want to add?:\n");
    fpurge(stdin);
	scanf ("%s", m.monster_name); // was tasks[counter]

    printf("What is added to the meelee weapon attack for the monster?\n");
    fpurge(stdin);
	scanf ("%d", &mwa);
    m.melee_weapon_attack = mwa;

    int num_dice;
    int type_of_dice;
    int add_to_attack;

    printf("How many dice does the %s roll?\n", m.monster_name);
    fpurge(stdin);
	scanf ("%d", &nd);
    m.num_dice = nd;

    printf("What type of dice does the %s roll? (ex: 20 for a d20):\n", m.monster_name);
    fpurge(stdin);
	scanf ("%d", &tod);
    m.type_of_dice = tod;

    printf("How much gets added to the %s's attack if it hits?:\n", m.monster_name);
    fpurge(stdin);
	scanf ("%d", &ata);
    m.add_to_attack = ata;

    printf("looking for spot for montster!\n");
    if(num_monsters==0)
    {
        monsters[0] = m;
        num_monsters++;
        return;
    }
    else //if (i==(num_monsters-1))
    {
        printf("found spot for montster @ %d!\n", i);
        monsters[num_monsters] = m;
        num_monsters++;
        return;
    }
    printf("didn't find spot for monster!\n");
    return;
}

int main (void)
{
	int option;
    printf("what's your party's current ac?:\n");
    scanf ("%d", &party_ac);
	while (1)
	{
		printf ("Choose an option:\n    1: see monsters\n    2: add new monster\n    0: exit\nEnter option: ");
		if (scanf ("%d", &option) != 1)
		{
			printf ("error\n");
			return 0;
		}

		switch (option)
		{
			case 1:
				printf("see monsters:\n");
				list_monsters();				
				break;

			case 2:
				printf ("add a new monster:\n");
				create_new_monster();
				break;

			case 0:
				printf ("exit\n");
				return 0;

			default:
				printf ("wrong option\n");
		}
	}	
}