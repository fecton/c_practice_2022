/*
* @file rating.c
* @author Литвиненко А.В., 515а
* @date 09 липня 2022
* @brief
* За умовою задачі потрібно створити програму, яка дозволить впорядковувати дані про оцінки здобувачів кафедри комп’ютерних систем, мереж і кібербезпеки сортуванням.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <iso646.h>

#include "structs.h"
#include "statuses.h"
#include "rating.h"
#include "sorting.h"
#include "database.h"

int main(int argc, const char* argv[]){
	lineString("Welcome to \"Rating Cheker\"");

	int fd, fd_tmp;
	int size = 0;
	char *datafile, *buffer;

	datafile = (char*) ec_malloc(1024);
	buffer	 = (char*) ec_malloc(1024);

	memset(datafile, 0, 1024);
	memset(buffer,   0, 1024);

	strcpy(datafile, "records.txt");

	record records[1024], sorted[1024];

	if((fd = open(datafile, O_RDONLY)) == -1){
		Info("File didn't exists! Creating new one...");
		if((fd = open(datafile, O_WRONLY|O_APPEND|O_CREAT, S_IRUSR|S_IWUSR)) == -1){
			CritError("In function main() during creating a new file");	
		}
	}
	else{
		Info("Opened successfully, starting reading!");

		Read_records(fd, records);
		size = Records_count(records);
		if(close(fd) == -1){
			CritError("In function main() during closing the file");
		}
	}

	for(int i=0;i<1024;++i){
		if(records[i].course == 0) break;
		sorted[i] = records[i];
	}

	unsigned int user_choice = 0;
	char* input = (char*) ec_malloc(128);
	while(1){
		switch(user_choice){
		case 0:
			Menu_of_actions();
			break;
		case 1:
			Show_table(records, size);
			break;
		case 2:
			record ex;
			printf(">>>><<<<\n");
			
			while(not(ex.course > 0 and ex.course <= 5)){
				printf("Course: ");
				scanf("%u", &ex.course);
			}

			do{
				printf("Group (6 symbols): ");
				scanf("%s", ex.group);
			}while(strlen(ex.group) > 6);

			
			do{
				printf("Surname (25 symbols): ");
				scanf("%s", ex.surname);
			}while(strlen(ex.surname) > 25);

			printf("Rating (5 4 3 2): ");
			scanf("%u%u%u%u", &ex.rating[0], &ex.rating[1], &ex.rating[2], &ex.rating[3]);

			printf(">>>><<<<\n");
			
			Add_record(ex, records, &size);
			break;
		case 3:

			
			Sort_by_course(sorted, size);
			
			Show_table(sorted, size);
			Info("Sorted successfully!");
			printf("Would you like to export it? (y/N): ");
			scanf("%s", input);
			if(not(strcmp(input, "y")) || not(strcmp(input, "Y"))){
				printf("Good! Enter filename: ");
				scanf("%s", input);
				fd_tmp = open(input, O_CREAT|O_WRONLY|O_TRUNC, S_IRUSR|S_IWUSR);
				Write_records(fd_tmp, sorted, size, input);
			}
			memset(input, 0, 128);
			break;
		case 4:
			Sort_by_group(sorted, size);
			Show_table(sorted, size);
			Info("Sorted successfully!");
			printf("Would you like to export it? (y/N): ");
			scanf("%s", input);
			if(not(strcmp(input, "y")) || not(strcmp(input, "Y"))){
				printf("Good! Enter filename: ");
				scanf("%s", input);
				fd_tmp = open(input, O_CREAT|O_WRONLY|O_TRUNC, S_IRUSR|S_IWUSR);
				Write_records(fd_tmp, sorted, size, input);
			}
			memset(input, 0, 128);
			break;
		case 5:
			Sort_by_surname(sorted, size);
			Show_table(sorted, size);
			Info("Sorted successfully!");
			printf("Would you like to export it? (y/N): ");
			scanf("%s", input);
			if(not(strcmp(input, "y")) || not(strcmp(input, "Y"))){
				printf("Good! Enter filename: ");
				scanf("%s", input);
				fd_tmp = open(input, O_CREAT|O_WRONLY|O_TRUNC, S_IRUSR|S_IWUSR);
				Write_records(fd_tmp, sorted, size, input);
			}
			memset(input, 0, 128);
			break;
		case 6:
			About();
			break;
		case 7:
			fd_tmp = open("records.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRUSR|S_IWUSR);

			Write_records(fd_tmp, records, size, "records.txt");
			close(fd_tmp);
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


	return 0;
}


