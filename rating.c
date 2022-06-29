#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "statuses.h"
#include "rating.h"

// Struct `record` represents necessary structure
typedef struct{
	unsigned int course;	// 4  bytes
	char group[6];		// 6  bytes
	char surname[25];	// 25 bytes
	unsigned int rating[4]; // 4  bytes
} record;			// Totally: 39 bytes


// Main function
int main(int argc, const char* argv[]){
	lineString("Welcome to \"Rating Cheker\"");

	int fd;
	char* datafile;
	datafile = (char*) calloc(1,128);
	strcpy(datafile, "records.txt");

	record* dynamic_array_of_structures = (record*) calloc(1,1024);

	// if file exists -> read array from file
	// else		  -> initilize empty array

	unsigned int user_choice = 0;
	while(1){
		switch(user_choice){
		case 0:
			menu_of_actions();
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:

			break;
		default:
			Warning("Bad option!");
		}
		printf("Op: ");
		scanf("%u", &user_choice);
	}


	printf("it works\n");

	return 0;
}


