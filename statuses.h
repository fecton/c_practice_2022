/*
* @file statuses.h
* @author Литвиненко А.В., 515а
* @date 09 липня 2022
* @brief
* За умовою задачі потрібно створити програму, яка дозволить впорядковувати дані про оцінки здобувачів кафедри комп’ютерних систем, мереж і кібербезпеки сортуванням.
*/

#ifndef STATUSES
#define STATUSES

/*
 * This function prints string with format for INFO
 *
 * @param	string
*/
void Info(const char* string){
	printf("[INFO] %s\n", string);
}

/*
 * This function prints string with format for WARNING
 *
 * @param	string
*/
void Warning(const char* string){
	printf("[WARNING] %s\n", string);
}


/*
 * This function prints string with format for ERROR
 *
 * @param	string
*/
void Error(const char* string){
	printf("[ERROR] %s\n", string);
}


/*
 * This function raises CRITICAL ERROR
 *
 * @param	string
*/
void CritError(const char* string){
	printf("[CRITICAL ERROR] %s\n", string);
	exit(-1);
}

/*
 * malloc() with error check
 * size of allocating memory
*/
void *ec_malloc(unsigned int size){
	void *ptr;
	ptr = malloc(size);
	if(ptr == NULL){
		CritError("In function ec_malloc() during allocation memory");
	}
	return ptr;
}

#endif
