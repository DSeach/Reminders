#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "ReminderSystem.h"

	/**
	* @author David Seach
	* @date 31/12/2024
	* @brief
	* A program to read a file and calculate how many days it is until 
	* that date. 
	*
	* The Stuct I am using (stored in ReminderSystem.h) is called timeRecord
	* and it used a struct tm that is found in time.h, I want to fill out
	* the timeRecord->tm_mday and timeRecord->mon to calculate the total 
	* seconds using localtime() also found in time.h to see if the date has
	* passed and if it hasnt, how many days until it does. If the date has 
	* passed then the char in timeRecord (tr_rep) will either add a year 
	* for next year's date or remove the entry in the file.
	*
	* file name for data: dates
	*
	* TODO malloc timeRecord and in inner tm's
	**/

int main(int argc , char* argv[]){

	int count = 0;
	const char* fileName = "dates";
	struct timeRecord* dates;
	FILE* fp = fopen(fileName , "r+" );
	

	if(fp == NULL){
		perror("Error opening file\n");
		exit(-1);
	}
	
	//count the amount of line in file and then allocate that many timeRecords

	count = GetLinesFile(fp);
	dates = allocTime(count);
	FillRecords(dates , fp , count);
	printDates(dates , count);

	free(dates);
	fclose(fp);
	return 0;
}

int GetLinesFile(FILE* fp){
	int count = 0;
	char endline;
	
	//feels slow
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

void FillRecords(struct timeRecord* records , FILE* fd , int count){
	//timeRecord internal:
	//int day, month
	//char tr_rep
	//char* name
	//
	//file format
	//day,month,tr_rep,name
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

}



