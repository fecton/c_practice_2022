FILE* DB_open(unsigned int openType) {
	FILE* db;
	if (openType == 2) {
		db = fopen(config.path, "wb+");
	}
	else if (!(db = fopen(config.path, "rb+"))) {
		printf("[+] The file '%s' didn't exist and it was created!\n", config.path);
		db = fopen(config.path, "wb+");
	}
	return db;
}


void DB_show() {
	FILE* db = DB_open(config, 4);

	char* record = (char*)calloc(1, 1024);
	char* srecord = record;
	char tmp;
	record object;

	char* massive_of_pointers[2] = {
		object.group, object.surname
	};

	while (!feof(db)) {
		fscanf(db, "%c", &tmp);
		if (tmp == '\0') {
			printf("[-] The file is empty\n");
			return;
		}

		while (tmp != '\n') {
			// course
			do
			{
				*record = tmp;
				record++;
				fscanf(db, "%c", &tmp);
			} while(tmp != '#' || feof(db));

			object.course = (unsigned int) atoi(srecord);
			memset(srecord, 0, 1024);
			record = srecord;

			for (int i = 0; i < 2; ++i) {
				do
				{
					*record = tmp;
					record++;
					fscanf(db, "%c", &tmp);
				} while ((tmp != '#' && tmp != '\n') || feof(db));
				fscanf(db, "%c", &tmp);
				strcpy(massive_of_pointers[i], srecord);
				memset(srecord, 0, 1024);
				record = srecord;
			}
			// rating[4]	
			for(int i=0; i < 4; ++i){
				do
				{
					*record = tmp;
					record++;
					fscanf(db, "%c", &tmp);
				} while(tmp != '#' || feof(db));
				fscanf(db, "%c", &tmp);
				object.rating[i] = (unsigned int) atoi(srecord);
				memset(srecord, 0, 1024);
				record = srecord;
			}
			printf("%u\t%s\t%s\t(%d %d %d %d)", object.course, object.group, object.surname, object.rating[0], object.rating[1], object.rating[2], object.rating[3]);
	}

	fclose(db);
}

void DB_write(record object) {
	// checking the corret time format

	FILE* db = DB_open(config, 4);

	char* record = (char*)calloc(1, 1024);
	char* srecord = record;
	char tmp;

	// opening the database file
	db = DB_open(config, 4);
	// go to the end
	fseek(db, 0, SEEK_END);
	// temp variable
	char maker[32] = { 0, };

	char* massive_of_pointers[2] = {
		object.group, object.surname
	};

	fwrite(object.course, sizeof(unsigned int), 1, db);
	fwrite("#", 1, 1, db);
	fwrite(object.group, strlen(group), 1, db);
	fwrite("#", 1, 1, db);
	fwrite(object.surname, strlen(surname), 1, db);
	fwrite("#", 1, 1, db);
	memset(maker, 0, 1024);	
	snprintf(maker, sizeof(maker), "%d#%d#%d#%d\n\0", object.rating[0],, object.rating[1], object.rating[2], object.rating[3]);
	fwrite(maker, strlen(maker), 1, db);
	fclose(db);
}


