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
	time_t myTime = time(NULL);
	struct timeRecord* records[10] = {0};
	const char* fileName = "dates";
	struct tm* currentTime = localtime(&myTime);
	
	struct tm christmas = {0};
	christmas.tm_mday = 25;
	christmas.tm_mon = 11;
	christmas.tm_year = (currentTime->tm_year);
	time_t chrissyTime = mktime(&christmas);


	if(myTime > chrissyTime){printf("Christmas has already happend!\n");}
	else{printf("Christmas is %d days away!\n" , (chrissyTime - myTime) / 60 / 60 / 24);}

	FILE* fp = fopen(fileName , "r+" );

	if(fp == NULL){
		perror("Error opening file\n");
		exit(-1);
	}

	//FillRecords(records , fp);

	fclose(fp);
	return 0;
}



void FillRecords(struct timeRecord** records , FILE* fd){
	//timeRecord internal:
	//int day, month
	//char tr_rep
	//char* name
	//
	//file format
	//day,month,tr_rep,name
	

	//TODO learn how to malloc

}


