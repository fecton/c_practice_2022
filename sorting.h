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

	if(strlen(string1) > strlen(string2)){
		length = strlen(string2);
	}
	else{
		length = strlen(string1);
	}

	printf("string1[0] = %d (%c)\nstring2[0] = %d (%c)\n", string1[0], string1[0], string2[0], string2[0]);

	for(int i=0;i<length;++i){
		// string1 and string2 starts with upper or lower case
		if(
			((string1[i] >= 65 and string1[i] <= 90)
			and
			(string2[i] >= 65 and string2[i] <= 90))
		or
			((string1[i] >= 97 and string1[i] <= 122)
			and
			(string2[i] >= 97 and string2[i] <= 122))
		)
		{
			// some actions	
			if(string1[i] == string2[i]){
				continue;
			}
			else{
				if(string1[i] > string2[i]){
					return 2;
				}
				else{
					return 1;
				}
			}
		}
		else{
		// string1 and string2 has different cases 
		if(string1[i] > string2[i]){
			return 2;
		}
		else{
			return 1;
		}
		}
	}


	return 0;
}


/*
 * Default insertion sorting
 *
 * @param array
 * @param size
 * @returns sorted array
*/
void Insertion_sorting(int* array, int size){

	int tmp, i, j;


	for(i=0;i<size;++i){
		tmp = array[i];
		j = i - 1;

		while(j>=0 and tmp<=array[j].){
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = tmp;
	}
}


/*
 * Default insertion sorting
 *
 * @param array
 * @param size
 * @returns sorted array
*/
void Insertion_sorting_by_surname(record* array, int size){

	int tmp, i, j;


	for(i=0;i<size;++i){
		tmp = array[i];
		j = i - 1;

		while(j>=0 and Compare_strings(tmp.surname, array[j].surname)){
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = tmp;
	}
}


