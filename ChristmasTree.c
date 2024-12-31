#include <stdio.h>
#include "ChristmasTree.h"

//TODO 
// * Add days until ( finish printMessage )
// * replace hardcoded width
// * Replace hardcoded top and bottom lines in main
// * Odd?
int main(int argc , char* argv[]){
	printf(" ");
	for(int width = 0; width < 16 + 4; ++width){printf("_");}
	printf(" \n| ");
	for(int width = 0; width < 16 / 2; ++width){printf(" ");} printf("/\\\n");
	for(int i = 0 ; i < 3; ++i){
		PrintChristmas(16);
	}
	printf("|");
	for(int width = 0; width < 16 + 4; ++width){printf("_");}
	printf("|\n");

	printMessage();
	return 0;
}

void PrintChristmas(int width){
	//even
	if((width % 2) == 0){
		int evenCount = 2;
		for(int height = width / 2;height != 0 ; --height){
			printf("| ");
			//if width is eight, should be four lines
			//spaces before
			for(int spaces = 0; spaces < height; ++spaces){ printf(" "); }
			
			//*'s
			for(int stars = 0; stars < evenCount; ++stars){ printf("*"); }
			evenCount += 2;

			//spaces after
			for(int spaces = 0; spaces < height; ++spaces){ printf(" "); }
			printf(" |\n");
		}	
	}
}
//to print how many days until christmas, than say "Merry Christmas!" 
void printMessage(){
	printf("Merry Christmas!!\n");
}
