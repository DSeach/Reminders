#include <stdio.h>
#include "ChristmasTree.h"

//TODO 
// * Add days until ( finish printMessage ) --Moved to Dates program/folder
// * replace hardcoded width --DONE--
// * Replace hardcoded top and bottom lines in main --DONE--
// * Odd?

int main(int argc , char* argv[]){

	const int treeWidth = 16;

	printf(" ");
	PrintChar(treeWidth + 4, '_');
	printf(" \n| ");

	PrintChar(treeWidth / 2, ' '); printf("/\\");
	PrintChar(treeWidth / 2, ' '); printf(" |\n");

	for(int i = 0 ; i < 3; ++i){
		PrintChristmas(treeWidth);
	}

	printf("|");
	PrintChar(treeWidth + 4, '_');
	printf("|\n");

	PrintMessage();
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
void PrintMessage(){
	printf("Merry Christmas!!\n");
}

//To control the printing of x amount of character y
void PrintChar(int width , char item){
	for(int i = 0; i < width; ++i){printf("%c" , item);}
}
