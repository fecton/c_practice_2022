/*
* @file structs.h
* @author Литвиненко А.В., 515а
* @date 09 липня 2022
* @brief
* За умовою задачі потрібно створити програму, яка дозволить впорядковувати дані про оцінки здобувачів кафедри комп’ютерних систем, мереж і кібербезпеки сортуванням.
*/

#ifndef STRUCTS
#define STRUCTS

// Struct `record` represents necessary structure
typedef struct{
	unsigned int course;	// 		4  bytes
	char group[6];		// 		+6  bytes
	char surname[25];	// 		+25 bytes
	unsigned int rating[4]; // 		+4  bytes
} record;			// Totally: 	=39 bytes

#endif
