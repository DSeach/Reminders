#ifndef REMINDERSYSTEM_H
#define REMINDERSYSTEM_H

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

int FillRecords(struct timeRecord** records , FILE* fd);

//counts the amount of lines in the file to detirmine how many timeRecords to have.
//uses rewind() to put the pointer back at the begining.
int GetLinesFile(FILE* fp);

int DaysUntil(struct timeRecord date, time_t now);

void AddDate(FILE* fd, char* date);

//function to validate the information of a string into a timeRecord
//@param line: the string that will be seperated, expected format being dd,mm,rep,name
//@return int : 0 if the string is valid, -1 if not.
int ValidateTR(char* date);

#endif
