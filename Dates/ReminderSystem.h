#ifndef REMINDERSYSTEM_H
#define REMINDERSYSTEM_H

#include <time.h>

struct timeRecord {
	int day,month;
	char* tr_name;
	char tr_rep;
};

//function to malloc count amount of timeRecords and return the pointer
//WARNING the timeRecords are uninitialised.
struct timeRecord* allocTime(int count);

//self explanitory
void printDates(struct timeRecord* records, int count);

//initialises the data in each time record from the file, fd. data must be organised such as:
//day,month,tr_rep,tr_name

int FillRecords(struct timeRecord* records , FILE* fd);

//counts the amount of lines in the file to detirmine how many timeRecords to have.
//uses rewind() to put the pointer back at the begining.
int GetLinesFile(FILE* fp);

#endif
