#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char* playable_races[] = {
    "Dwarf",
    "Elf",
    "Halfling",
    "Human",
    "Dragonborn",
    "Gnome",
    "Half-Elf",
    "Half-Orc",
    "Tiefling",
    "Aasimar",
    "Bugbear",
    "Firbolg",
    "Goblin",
    "Goliath",
    "Hobgoblin",
    "Kenku",
    "Kobold",
    "Lizardfolk",
    "Orc",
    "Tabaxi",
    "Triton",
    "Yuan-ti Pureblood"
};

const char* classes[] = {
    "Barbarian",
    "Bard",
    "Cleric",
    "Druid",
    "Fighter",
    "Monk",
    "Paladin",
    "Ranger",
    "Rogue",
    "Sorcerer",
    "Warlock",
    "Wizard"
};

const char* backgrounds[] = {
    "Acolyte",
    "Charlatan",
    "Criminal",
    "Entertainer",
    "Folk Hero",
    "Guild Artisan",
    "Hermit",
    "Noble",
    "Outlander",
    "Sage",
    "Sailor",
    "Soldier",
    "Urchin",
    "Anthropologist",
    "Archaeologist",
    "Black Fist Double Agent",
    "City Watch",
    "Clan Crafter",
    "Cloistered Scholar",
    "Courtier",
    "Criminal Contact",
    "Dimir Operative",
    "Earthspur Miner",
    "Far Traveler",
    "Faction Agent",
    "Harborfolk",
    "Haunted One",
    "Inheritor",
    "Knight of the Order",
    "Mercenary Veteran",
    "Mythic Odysseys of Theros",
    "Urban Bounty Hunter",
    "Uthgardt Tribe Member",
    "Waterdhavian Noble"
};

int main (void)
{
    int lower = 0, upper = 21, min = 0, max = 21, i = 0, dmg = 0;
    int random = (rand() % (upper - lower +1)) + lower;
    printf("%s\n", playable_races[random]);
    int l = 0, u = 11, min = 0, max = 11;
    int r = (rand() % (u - l +1)) + l;
    printf("%s\n", classes[r]);

    int lo = 0, up = 11, mi = 0, max = 11;
    int r = (rand() % (up - lo)) + lo;
    printf("%s\n", classes[r]);

    

	
}