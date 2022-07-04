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
