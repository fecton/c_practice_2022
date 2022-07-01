#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>

#include "rating.h"
#include "statuses.h"

// Main function
int main(int argc, const char* argv[]){
	lineString("Welcome to \"Rating Cheker\"");

	int fd;
	char *datafile, *buffer;

	datafile = (char*) ec_malloc(1024);
	buffer	 = (char*) ec_malloc(2048);

	memset(datafile, 0, 1024);
	memset(buffer,   0, 2048);

	strcpy(datafile, "records.txt");

	record records[1024];

	if(fd = open(datafile, O_RDONLY) == -1){
		Info("File didn't exists! Creating new one...");
		if(fd = open(datafile, O_WRONLY|O_APPEND|O_CREAT, S_IRUSR|S_IWUSR) == -1){
			CritError("In function main() during creating new file");	
		}
		else{
			long int ltime = time(0);
			char* last_modified_time = asctime(localtime(ltime));
			sprintf(buffer, "Last modified: %s\nCreated by: %s\n", last_modified_time, getenv("USER"));
			Info(buffer);
			if(write(fd, buffer, strlen(buffer)) == -1){
				CritError("In function main() during writing the file");
			}
			else{
				Info("Was written successfully!");
			}
		}	
	}
	else{
		Info("Opened successfully, starting writing!");
	}

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
			About();
			break;
		case 6:
			Exit();
		default:
			Warning("Bad option!");
		}
		printf(">> ");
		scanf("%u", &user_choice);
	}

	if(close(fd) == -1){
		CritError("In function main() during closing the file");
	}

	printf("it works\n");

	return 0;
}


