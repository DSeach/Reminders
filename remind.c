#include <stdio.h>
#include <stdlib.h>

#include "./Dates/ReminderSystem.h"


int main(int argc , char* argv[]){
	const char* filename = "dates";
	struct timeRecord* dates;

	FILE* fd = fopen(filename , "r+");

	int count = FillRecords(dates , fd); 
	fclose(fd);
	free(dates);
	return 0;
}

