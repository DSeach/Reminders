#include <stdio.h>
#include <time.h>

int main(int argc , char* argv[]){
	time_t myTime = time(NULL);

	struct tm* currentTime = localtime(&myTime);
	
	struct tm christmas = {0};
	christmas.tm_mday = 25;
	christmas.tm_mon = 11;
	christmas.tm_year = (currentTime->tm_year + 1);
	time_t chrissyTime = mktime(&christmas);

	if(myTime > chrissyTime){printf("Christmas has already happend!\n");}
	else{printf("Christmas is %d days away!\n" , (chrissyTime - myTime) / 60 / 60 / 24);}

	//printf("%s\n" , timeToPrint);
	return 0;
}
