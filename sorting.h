/*
 * Compares two string and returns bigger
 *
 * @param	string1
 * @param	string2
 * @returns
 * 	* 0	string1 == string2
 * 	* 1	string1  > string2
 * 	* 2	string1  < string2
*/
int Compare_strings(const char* string1, const char* string2){
	int length = 0;
	int numlength = 0;
	if(strlen(string1) > strlen(string2)){
		length = strlen(string2);
	}
	else{
		length = strlen(string1);
	}

	for(int i=0;i<length;++i){
		if(numlength == 2){
			if(strlen(string1) == 3 and strlen(string2) != 3){
				return 2;
			}
			if(strlen(string1) != 3 and strlen(string2) == 3){
				return 1;
			}
		}
		// string1 and string2 starts with upper or lower case
		// A-Z or a-z
		if(
			(
			 (string1[i] >= 0x41 and string1[i] <= 0x5A)
				and
			 (string2[i] >= 0x41 and string2[i] <= 0x5A)
			)
			or
			(
			 (string1[i] >= 0x61 and string1[i] <= 0x7A)
				and
			 (string2[i] >= 0x61 and string2[i] <= 0x7A)
			)
		)
		{
			if(string1[i] > string2[i]){
				return 2;
			}
			else{
				return 1;
			}
		}
		else{
			// 0-9
			if(
				(string1[i] >= 0x30 and string1[i] <= 0x39)
				and	
				(string2[i] >= 0x30 and string2[i] <= 0x39)
			  ){
				if(string1[i] > string2[i]){
					return 1;
				}
				else if(string1[i] < string2[i]){
					return 2;
				}
			}
			else{
				// string1 and string2 has different cases 
				if(string1[i] > string2[i]){
					return 2;
				}
				else if(string1[i] < string2[i]){
					return 1;
				}
			}
			numlength++;
		}
	}
	return 0;
}

/*
 * Choise sorting by course
 *
 * @param array
 * @param size
 * @returns sorted array
*/
void Sort_by_course(record* array, int size){
	int minPos;
	record tmp;
	for(int i=0;i<size;i++){
		minPos = i;
		for(int j=i+1;j<size;j++){
			if(array[minPos].course > array[j].course)
				minPos = j;
		}
		tmp = array[minPos];
		array[minPos] = array[i];
		array[i] = tmp;
	}
}



/*
 * Choise sorting by group
 *
 * @param array
 * @param size
 * @returns sorted array
*/
void Sort_by_group(record* array, int size){
	int minPos;
	record tmp;
	for(int i=0;i<size;i++){
		minPos = i;
		for(int j=i+1;j<size;j++){
			if(Compare_strings(array[minPos].group, array[j].group) == 1)
				minPos = j;
		}
		tmp = array[minPos];
		array[minPos] = array[i];
		array[i] = tmp;
	}
}



/*
 * Choise sorting by username 
 *
 * @param array
 * @param size
 * @returns sorted array
*/
void Sort_by_surname(record* array, int size){
	int minPos;
	record tmp;
	for(int i=0;i<size;i++){
		minPos = i;
		for(int j=i+1;j<size;j++){
			if(Compare_strings(array[minPos].surname, array[j].surname) == 2)
				minPos = j;
		}
		tmp = array[minPos];
		array[minPos] = array[i];
		array[i] = tmp;
	}
}


