#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "ReminderSystem.h"

	/**
	* @author David Seach
	* @date 31/12/2024
	* @brief
	* A collection of functions to allow the storing of date information into a timeRecord struct ( stored in the header )
	* file name for data: dates
	* format: day,month,tr_rep,tr_name
	**/

int GetLinesFile(FILE* fp){
	int count = 0;
	char endline;
	
	for(endline = getc(fp); endline != EOF; endline = getc(fp)){
		if(endline == '\n'){
			count++;
		}
	}
	rewind(fp);
	return count;
}

//WARNING unitialised!
struct timeRecord* allocTime(int count){
	struct timeRecord* arr= malloc(sizeof(struct timeRecord) * count );
	return arr;
}

void printDates(struct timeRecord* records , int count){
	for(int i = 0; i < count; ++i){
		printf("%s is on the %d/%d -rep = %c-\n" , records[i].tr_name , records[i].day , records[i].month , records[i].tr_rep);
	}
}


//@return the length of the array
int FillRecords(struct timeRecord* records , FILE* fd){
	int count = GetLinesFile(fd);
	records = allocTime(count);
	char* line =NULL;
	size_t len = 0;

	for(int i = 0; i < count; i++)
	{
		if(getline(&line , &len , fd) != -1){
			char* token = strtok(line , ",");
			int num = 0;

			while(token != NULL){
				switch(num){
				  case 0:
					records[i].day = atoi(token);
					break;
				  case 1:
					records[i].month = atoi(token);
					break;
				  case 2:
					records[i].tr_rep = token[0];
					break;
				  case 3:
					records[i].tr_name = strdup(token);
					break;
				}
				token = strtok(NULL, ",");
				num++;
			}
		} else {
			perror("getline failure\n");
			exit(-1);
		}
	}
	free(line);
	return count;
}



