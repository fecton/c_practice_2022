#ifndef FUNCS
#define FUNCS

/*
 * Prints argument with some symbols on sides
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
 * Prints line like "-="
 * A length of this string is:
 * "-="(12) + "strlen(string)" + " "(2) + "-="(12)
 * Or: 26 + strlen(string)
 *
 * @param string
 * @retuns None
*/
void line(const char* string){
	for(int i=0;i<(strlen(string)+12+12+2)/2;++i){
		printf("-=");
	}
	printf("\n");
}


/*
 * Prints the menu of actions for user 
 *
 * @param	None
 * @returns	None
*/
void Menu_of_actions(){
	char opname[] = "Menu";
	char menu[8][25] = {
		"  0. Menu", // +
		"  1. Show the table", // +
		"  2. Add a record", // +
		"  3. Sort by a course",
		"  4. Sort by a group",
		"  5. Sort by surname",
		"  6. About", // +
		"  7. Exit"   // +
	};

	lineString(opname);
	for(int i=0;i<8;++i){
		printf("%s\n", menu[i]);
	}
}

/*
 * Prints information about author
 *
 * @param 	None
 * @returns 	None
*/
void About(){
	char opname[] = "About";
	lineString(opname);
	char about[2][40] = {
		"GitHub: https://github.com",
		"Telegram: https://t.me/fectosha",
	};
	for(int i=0;i<2;++i){
		printf("[+] %s\n", about[i]);
	}
}


/*
 * Exit the program
 *
 * @param	None
 * @returns	None
*/
void Exit(){
	char opname[] = "Exit";
	lineString(opname);
	printf("Goodbye!\n");
	line(opname);
	exit(0);
}

#endif


