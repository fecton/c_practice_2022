#ifndef FUNCS
#define FUNCS

/*
 * This function prints argument with some symbols on sides
 *
 * @param	string
 * @returns	None
*/
void lineString(const char* string){
	printf("-=-=-=-=-= [");
	printf(" %s ", string);
	printf("] =-=-=-=-=-\n");
}


/*
 * Prints the menu of actions for user 
 *
 * @param	None
 * @returns	None
*/
void menu_of_actions(){
	char menu[7][38] = {
		"  0. Menu", // +
		"  1. Show the table (without sorting)",
		"  2. Sort by a course",
		"  3. Sort by a group",
		"  4. Sort by surname",
		"  5. About", // +
		"  6. Exit"   // +
	};

	lineString("Menu");
	for(int i=0;i<7;++i){
		printf("%s\n", menu[i]);
	}
	
	for(int i=0;i<(12+12+2+4)/2;++i){
		printf("-=");
	}
	printf("\n");

}

/*
 * 
 *
*/
void printStatus(){
	return;
}
#endif


