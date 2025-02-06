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
	rewind(fp);	
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
		printf("%s is on the %02d/%02d rep = %c\n" , records[i].tr_name , records[i].day , records[i].month , records[i].tr_rep);
	}
}

int DaysUntil(struct timeRecord date , time_t now){
	struct tm currtime = *localtime(&now);
	struct tm target = {0}; 

	target.tm_mday = date.day;
	target.tm_mon = date.month -1;
	target.tm_year = currtime.tm_year;
	
	time_t targetTime = mktime(&target);
	if(targetTime < 1) { return -1;}

	double secondsDiff = difftime(targetTime , now);
	int daysDiff = (int)(secondsDiff / (60*60*24));

	if(secondsDiff < 0 && date.tr_rep != 'y'){
		return daysDiff; 
	}

	if(date.tr_rep == 'y' && daysDiff < 0){
		target.tm_year += 1;
		targetTime = mktime(&target);
		secondsDiff = difftime(targetTime , now);
		daysDiff = (int)(secondsDiff / (60*60*24));
	}

	return daysDiff;
}


//@return the length of the array
int FillRecords(struct timeRecord** records , FILE* fd){
	rewind(fd);
	int count = GetLinesFile(fd);
	*records = allocTime(count);
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
					(*records)[i].day = atoi(token);
					break;
				  case 1:
					(*records)[i].month = atoi(token);
					break;
				  case 2:
					(*records)[i].tr_rep = token[0];
					break;
				  case 3:
					int slen = 0;
					while(token[slen] != '\0'){slen++;}
					token[slen -1] = '\0';
					(*records)[i].tr_name = strdup(token);
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

void AddDate(FILE* fd, char* date){
	//I want the date to be passed in as a line such as :
	//"day,month,rep,name" then use strtok
	//TODO at this stage, I want another function to handle if the date is correct or not.
	if(ValidateTR(date) != 0){
		exit(-1);
	}

	fseek(fd , 0 ,SEEK_END);
	fprintf(fd ,"%s\n" , date);
	printf("Date - %s - Successfully added\n" , date);
}
//return 0 if valid, -1 if not
int ValidateTR(char* date){
	char* line = strdup(date);
	int day,month;
	char* tok = strtok(line, ",");
	int num = 0;
	while(tok != NULL){
		switch(num){
		  case 0:
			day = atoi(tok);
			if(day > 31 || day < 1){
					printf("invalid day %s\n" , tok);
					free(line);
					return -1;
				}
			break;
		  case 1:
			month = atoi(tok);
			if(month > 12 || month < 1){
					printf("Invalid month %s\n" , tok);
					free(line);
					return -1;
				}
			break;
		  case 2:
			int len = 0;
			while (tok[len] != '\0'){len++;}
			if(len != 1) {
				printf("Invalid rep char %s\n" , tok);
				free(line);
				return -1;
			}
			break;
		  case 3:
			break;
		  defailt:
			printf("Invalid additional text %s\n" , tok);
			free(line);
			return -1;
		}
		num++;
		tok = strtok(NULL , ",");
	}
	free(line);
	return 0;
}
