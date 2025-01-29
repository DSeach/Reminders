#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./Dates/ReminderSystem.h"

void normalFunc(struct timeRecord** dates, FILE* fd);


int main(int argc , char* argv[]){

	const char* filename = "dates";
	struct timeRecord* dates = NULL;
	FILE* fd = fopen(filename , "r+");
	
	if(fd == NULL){
		perror("fopen fail\n");
		exit(-1);
	}
	
	if(argc == 1){
		normalFunc(&dates , fd);
	}
	
	free(dates);
	fclose(fd);
	return 0;
}

void normalFunc(struct timeRecord** dates, FILE* fd){
	int count = FillRecords(&(*dates) , fd); 
	time_t t = time(NULL);
	int daysToGo = 0;
	printf("Count = %d\n" , count);	
	
	for(int i = 0 ; i < count; ++i){
		daysToGo = DaysUntil((*dates)[i] , t);
		if(daysToGo > 0){printf("%d days to go until \033[31m%s\n\033[0m" , daysToGo , (*dates)[i].tr_name);} 
		if(daysToGo == 0){ printf("%s is today!\n" , (*dates)[i].tr_name);}
		if(daysToGo < 0){printf("%s happened %d days ago\n" , (*dates)[i].tr_name , abs(daysToGo));}
	}
	
}
