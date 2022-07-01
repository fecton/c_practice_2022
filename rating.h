#ifndef FUNCS
#define FUNCS

#include "structs.h"
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
void menu_of_actions(){
	char opname[] = "Menu";
	char menu[7][38] = {
		"  0. Menu", // +
		"  1. Show the table (without sorting)",
		"  2. Sort by a course",
		"  3. Sort by a group",
		"  4. Sort by surname",
		"  5. About", // +
		"  6. Exit"   // +
	};

	lineString(opname);
	for(int i=0;i<7;++i){
		printf("%s\n", menu[i]);
	}
	line(opname);	

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
	char about[3][40] = {
		"GitHub: https://github.com",
		"Telegram: https://t.me/fectosha",
		"Telegram channel: https://t.me/varlife",
	};
	for(int i=0;i<3;++i){
		printf("[+] %s\n", about[i]);
	}
	line(opname);

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

/*
 * 
 *
*/
void printStatus(){
	return;
}
#endif


