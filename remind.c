#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./Dates/ReminderSystem.h"




int main(int argc , char* argv[]){
	const char* filename = "dates";
	struct timeRecord* dates = NULL;

	FILE* fd = fopen(filename , "r+");
	
	if(fd == NULL){
		perror("fopen fail\n");
		exit(-1);
	}
	int count = FillRecords(&dates , fd); 
	time_t t = time(NULL);
	int daysToGo = 0;
	
	
	for(int i = 0 ; i < count; ++i){
		daysToGo = DaysUntil(dates[i] , t);
		if(daysToGo > 0){printf("%d days to go until %s\n" , daysToGo , dates[i].tr_name);} 
		if(daysToGo == 0){ printf("%s is today!\n" , dates[i].tr_name);}
		if(daysToGo < 0){printf("%s happened %d days ago\n" , dates[i].tr_name , daysToGo);}
	}

	free(dates);
	fclose(fd);
	return 0;
}

