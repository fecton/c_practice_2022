#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <iso646.h>

#include "rating.h"
#include "statuses.h"
#include "sorting.h"

int main(int argc, const char* argv[]){
	lineString("Welcome to \"Rating Cheker\"");

	int fd;
	char *datafile, *buffer;

	datafile = (char*) ec_malloc(1024);
	buffer	 = (char*) ec_malloc(1024);

	memset(datafile, 0, 1024);
	memset(buffer,   0, 1024);

	strcpy(datafile, "records.txt");

	record records[1024];

	if((fd = open(datafile, O_RDONLY)) == -1){
		Info("File didn't exists! Creating new one...");
		if((fd = open(datafile, O_WRONLY|O_APPEND|O_CREAT, S_IRUSR|S_IWUSR)) == -1){
			CritError("In function main() during creating new file");	
		}
		else{
			long int ltime = time(0);
			char* last_modified_time = asctime(localtime(&ltime));
			sprintf(buffer, "Last modified:\t%sCreated by:\t%s\n", last_modified_time, getenv("USER"));
			
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

	unsigned int user_choice = 0;
	while(1){
		switch(user_choice){
		case 0:
			Menu_of_actions();
			break;
		case 1:
			Show_table(fd);
			break;
		case 2:
			Sort_by_course(fd);
			break;
		case 3:
			Sort_by_group(fd);
			break;
		case 4:
			Sort_by_surname(fd);
			break;
		case 5:
			About();
			break;
		case 6:
			Exit();
		default:
			Warning("Bad option!");
			break;
		}
		line("Menu");
		printf(">> ");
		scanf("%u", &user_choice);
	}

	free(datafile);
	free(buffer);
	if(close(fd) == -1){
		CritError("In function main() during closing the file");
	}

	return 0;
}


