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
	time_t toGo;
	struct tm currdate;
	
	for(int i = 0 ; i < count; ++i){
		toGo = timeUntil(dates[i] , t);
		if(toGo >= 0){
			toGo = toGo / (60 * 60 * 24);
			printf("%ld days to go until %s\n" , toGo , dates[i].tr_name);
		} else {
			printf("%s has already happened, %ld days ago\n" , dates[i].tr_name , toGo);
		}
	}

	fclose(fd);
	free(dates);
	
	return 0;
}

