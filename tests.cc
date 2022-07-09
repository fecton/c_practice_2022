#include <gtest/gtest.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <iso646.h>

#include "structs.h"
#include "statuses.h"
#include "rating.h"
#include "sorting.h"
#include "database.h"

record array[1024];
char t[] = "test";
int size = 0;

// void testes
TEST(InitTest, test1){

	array[0].course = 3;
	strcpy(array[0].group, "533i2");
	strcpy(array[0].surname, "Kostenko");
	array[0].rating[0] = 1;
	array[0].rating[1] = 1;
	array[0].rating[2] = 3;
	array[0].rating[3] = 5;

	array[1].course = 1;
	strcpy(array[1].group, "515");
	strcpy(array[1].surname, "Akyppa");
	array[1].rating[0] = 3;
	array[1].rating[1] = 2;
	array[1].rating[2] = 1;
	array[1].rating[3] = 0;

	array[2].course = 1;
	strcpy(array[2].group, "515a");
	strcpy(array[2].surname, "Kopiyka");
	array[2].rating[0] = 0;
	array[2].rating[1] = 2;
	array[2].rating[2] = 1;
	array[2].rating[3] = 3;

	array[3].course = 2;
	strcpy(array[3].group, "523i1");
	strcpy(array[3].surname, "Ivanov");
	array[3].rating[0] = 1;
	array[3].rating[1] = 5;
	array[3].rating[2] = 1;
	array[3].rating[3] = 3;
	size = 4;
}

TEST(StatusesTest, tests){
	Info(t);
	Warning(t);
	Error(t);
	/* CritError(t); */
}

TEST(RatingH, tests){
	lineString(t);
	line(t);
	Menu_of_actions();	
	About();
	/* Exit(); */
}

// =============================
TEST(Compare_strings, test1){
	char str1[] = "Litvinow";
	char str2[] = "Antonio";

	EXPECT_EQ(2, Compare_strings(str1, str2));
}

TEST(Compare_strings, test2){
	char str1[] = "534";
	char str2[] = "515";

	EXPECT_EQ(1, Compare_strings(str1, str2));
}

TEST(Compare_strings, test3){
	char str1[] = "515";
	char str2[] = "515a";

	EXPECT_EQ(2, Compare_strings(str1, str2));
}

TEST(Compare_strings, test4){
	char str1[] = "Zoichekj";
	char str2[] = "Yamdava";

	EXPECT_EQ(2, Compare_strings(str1, str2));
}

// =============================
TEST(Sortings, sort_by_course){
	record sorted[4];
	record tmp[4];
	sorted[0] = array[1];
	sorted[1] = array[2];
	sorted[2] = array[3];
	sorted[3] = array[0];
	for(int i=0;i<4;++i){
		tmp[i] = array[i];
	}	
	Sort_by_course(tmp, 4);
	for(int i=0;i<4;++i){
		EXPECT_EQ(sorted[i].course, tmp[i].course);
		EXPECT_STREQ(sorted[i].group, tmp[i].group);
		EXPECT_STREQ(sorted[i].surname, tmp[i].surname);
		for(int j=0;j<4;++j){
			EXPECT_EQ(sorted[i].rating[j], tmp[i].rating[j]);
		}
	}
}

TEST(Sortings, sort_by_group){
	record sorted[4];
	record tmp[4];
	
	sorted[0] = array[1];
	sorted[1] = array[2];
	sorted[2] = array[3];
	sorted[3] = array[0];

	for(int i=0;i<4;++i){
		tmp[i] = array[i];
	}	
	Sort_by_course(tmp, 4);
	for(int i=0;i<4;++i){
		EXPECT_EQ(sorted[i].course, tmp[i].course);
		EXPECT_STREQ(sorted[i].group, tmp[i].group);
		EXPECT_STREQ(sorted[i].surname, tmp[i].surname);
		for(int j=0;j<4;++j){
			EXPECT_EQ(sorted[i].rating[j], tmp[i].rating[j]);
		}
	}
}

TEST(Sortings, sort_by_surname){
	record sorted[1024];
	record tmp[1024];
	
	sorted[0] = array[1];
	sorted[1] = array[3];
	sorted[2] = array[2];
	sorted[3] = array[0];

	for(int i=0;i<size;++i){
		tmp[i] = array[i];
	}	
	Sort_by_course(tmp, 4);
	for(int i=0;i<size;++i){
		EXPECT_EQ(sorted[i].course, tmp[i].course);
		EXPECT_STREQ(sorted[i].group, tmp[i].group);
		EXPECT_STREQ(sorted[i].surname, tmp[i].surname);
		for(int j=0;j<4;++j){
			EXPECT_EQ(sorted[i].rating[j], tmp[i].rating[j]);
		}
	}
}

// =============================
TEST(Database, records_count){
	int count = Records_count(array);
	EXPECT_EQ(count, size);
}

TEST(Database, show_table){
	Show_table(array, size);
}

TEST(Database, add_record){
	record tmp[1024];
	int tmpsize = size;
	for(int i=0;i<size;++i){
		tmp[i] = array[i];
	}
	record ex;
	ex.course = 4;
	strcpy(ex.group, "444");
	strcpy(ex.surname, "Lucky444");
	ex.rating[0] = 5;
	ex.rating[1] = 3;
	ex.rating[2] = 2;
	ex.rating[3] = 1;

	Add_record(ex, tmp, &tmpsize);

	EXPECT_EQ(tmp[size].course, 4);
	EXPECT_STREQ(tmp[size].group, "444");
	EXPECT_STREQ(tmp[size].surname, "Lucky444");
	EXPECT_EQ(tmp[size].rating[0], 5);
	EXPECT_EQ(tmp[size].rating[1], 3);
	EXPECT_EQ(tmp[size].rating[2], 2);
	EXPECT_EQ(tmp[size].rating[3], 1);
	EXPECT_EQ(size+1, tmpsize);
}


