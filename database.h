/*
 * Shows all records from the file
 *
 * @param fd	file descriptor
*/
void Show_table(record* array, int size) {
	for(int i=0;i<size;++i){
		printf("%1u\t%6s\t%25s\t(%2d %2d %2d %2d)\n", array[i].course, array[i].group, array[i].surname, array[i].rating[0], array[i].rating[1], array[i].rating[2], array[i].rating[3]);
	}
	printf("\nTotally %d students\n", size);
}


/*
 * Add a structure to array
 *
 * @param ex	record instance
 * @param array	array of records
 * @param size	array's size
*/
void Add_record(record ex, record* array, int* size){
	array[*size] = ex;
	(*size)++;
}


/*
 * Writes record in "records.txt" file
 *
 * @param fd 	file descriptor
 * @param array	array of records
 * @param size	array's size
*/
void Write_records(int fd, record* array, int size, char* filename) {
	for(int i=0;i<size;++i){
		char *maker =  (char*) calloc(1,4096);
		fd = open(filename, O_WRONLY|O_APPEND|O_CREAT, S_IRUSR|S_IWUSR);
		sprintf(maker, "%u#%s#%s#%u#%u#%u#%u\n", array[i].course, array[i].group, array[i].surname, array[i].rating[0], array[i].rating[1], array[i].rating[2], array[i].rating[3]);
		write(fd, maker, strlen(maker));
	}
}

/*
 * Reads record from "records.txt" file and fit it in array
 *
 * @param fd	file descriptor
 * @param array	array of records
*/
void Read_records(int fd, record* array){
	fd = open("records.txt", O_RDONLY);

	char* rec = (char*)calloc(1, 1024);
	char* srecord = rec;
	char tmp = '0';

	record object;

	int flag = 1, pos = 0;

	char* massive_of_pointers[2] = {
		object.group, object.surname
	};

	while (flag) {
		while (flag) {
			// course
			do
			{
				*rec = tmp;
				rec++;
				read(fd, &tmp, 1);
			} while(tmp != '#' && tmp != '\n');

			if(tmp == '\n'){
				flag = 0;
				break;
			}

			read(fd, &tmp, 1);

			if(tmp == ' '){
				flag = 0;
			}

			object.course = (unsigned int) atoi(srecord);
			memset(srecord, 0, 1024);
			rec = srecord;
			for (int i = 0; i < 2; ++i) {
				do
				{
					*rec = tmp;
					rec++;
					read(fd, &tmp, 1);
				} while ((tmp != '#' && tmp != '\n') );
				read(fd, &tmp, 1);
				strcpy(massive_of_pointers[i], srecord);
				memset(srecord, 0, 1024);
				rec = srecord;
			}
			
			// rating[4]	
			for(int i=0; i < 4; ++i){
				do
				{
					*rec = tmp;
					rec++;
					read(fd, &tmp, 1);
				} while(tmp != '#' && tmp != '\n'); 
				read(fd, &tmp, 1);
				object.rating[i] = (unsigned int) atoi(srecord);
				memset(srecord, 0, 1024);
				rec = srecord;
			}
			array[pos] = object;
			pos++;
		}

	}
	close(fd);
}

/*
 * Returns length of array of structures
 *
 * @param array
 * @returns i	length
*/
int Records_count(record* array){
	int i = 0;
	while(array[i].course){
		i++;
	}
	return i;
}

