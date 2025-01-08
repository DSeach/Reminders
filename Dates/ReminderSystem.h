#ifndef REMINDERSYSTEM_H
#define REMINDERSYSTEM_H

#include <time.h>

struct timeRecord {
	int day,month;
	char* tr_name;
	char tr_rep;
};

void FillRecords(struct timeRecord** records , FILE* fd);

#endif
