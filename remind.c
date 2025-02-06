#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "./Dates/ReminderSystem.h"

void normalFunc(struct timeRecord** dates, FILE* fd);


int main(int argc , char* argv[]){

	const char* filename = "dates";
	struct timeRecord* dates = NULL;
	FILE* fd = fopen(filename , "a+");

	if(fd == NULL){
		perror("fopen fail\n");
		exit(-1);
	}
	
	if(argc == 1){
		normalFunc(&dates , fd);
	}

	if(argc == 2){
		if(strcmp(argv[1] , "-a") == 0){
			printf("-a usage: remind -a <date>\n");
		} else{
			printf("Unknown parameter - %s\n" , argv[1]);
		}
	}

	if(argc == 3){
		if(strcmp(argv[1] , "-a") != 0){
			printf("Unknown parameter - %s \n" , argv[1]);
		}else{
		printf("Preparing to add - %s\n" , argv[2]);
		AddDate(fd , argv[2]);
		}
	}

	fclose(fd);
	return 0;
}

void normalFunc(struct timeRecord** dates, FILE* fd){
	int count = FillRecords(&(*dates) , fd); 
	time_t t = time(NULL);
	int daysToGo = 0;
	//printf("Count = %d\n" , count);	
	
	for(int i = 0 ; i < count; ++i){
		daysToGo = DaysUntil((*dates)[i] , t);
		if(daysToGo > 0){printf("%d days to go until \033[31m%s\n\033[0m" , daysToGo , (*dates)[i].tr_name);} 
		if(daysToGo == 0){ printf("%s is today!\n" , (*dates)[i].tr_name);}
		if(daysToGo < 0){printf("%s happened %d days ago\n" , (*dates)[i].tr_name , abs(daysToGo));}
		free((*dates)[i].tr_name);
	}
	free(*dates);
}
