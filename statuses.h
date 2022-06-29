#ifndef STATUSES
#define STATUSES

/*
 * This function prints string with format for warning
 *
 * @param	string
 * @returns	None
*/
void Warning(const char* string){
	printf("[WARNING] %s\n", string);
}


/*
 * This function prints string with format for error
 *
 * @param	string
 * @returns	None
*/
void Error(const char* string){
	printf("[ERROR] %s\n", string);
}


/*
 * This function raises critical error
 *
 * @param	string
 * @returns	None
*/
void CritError(const char* string){
	printf("[CRITICAL ERROR] %s\n", string);
	exit(-1);
}

#endif