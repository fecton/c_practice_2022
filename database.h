/*
 * Shows all records from the file
 *
 * @param fd	file descriptor
 * @returns 	None
*/
void Show_table(int fd) {
	fd = open("records.txt", O_RDONLY);

	char* rec = (char*)calloc(1, 1024);
	char* srecord = rec;
	char tmp = '0';

	record object;

	int flag = 1;

	char* massive_of_pointers[2] = {
		object.group, object.surname
	};

	while (flag) {
		for(int i=0;i<2;++i){
			while(tmp != '\n'){
				read(fd, &tmp, 1);
			}
			read(fd, &tmp, 1);
		}

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
			printf("%u\t%s\t%s\t(%2d %2d %2d %2d)\n", object.course, object.group, object.surname, object.rating[0], object.rating[1], object.rating[2], object.rating[3]);
		}

	}
	close(fd);
}


/*
 * Writes record in "records.txt" file
 *
 * @param fd 	file descriptor
 * @param ex 	record structure
 * @returns 	None
*/
void DB_write(int fd, record ex) {
	char *maker =  (char*) calloc(1,4096);

	fd = open("records.txt", O_WRONLY|O_APPEND|O_CREAT, S_IRUSR|S_IWUSR);

	sprintf(maker, "%u#%s#%s#%u#%u#%u#%u\n", ex.course, ex.group, ex.surname, ex.rating[0], ex.rating[1], ex.rating[2], ex.rating[3]);

	write(fd, maker, strlen(maker));
	close(fd);
}

