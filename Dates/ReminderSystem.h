#ifndef REMINDERSYSTEM_H
#define REMINDERSYSTEM_H

#include <time.h>

struct timeRecord {
	struct tm* tr_tm;
	char* tr_name;
	char* tr_rep;
};

void FillRecords(struct timeRecord** records , FILE* fd);

#endif
