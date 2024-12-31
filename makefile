ChristmasTree: ChristmasTree.o
	gcc ChristmasTree.o -o ChristmasTree

ChristmasTree.o: ChristmasTree.c ChristmasTree.h
	gcc -c ChristmasTree.c -o ChristmasTree.o

clean: 
	rm *.o ChristmasTree
