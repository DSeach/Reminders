remind: Dates/ReminderSystem.o remind.o
	gcc Dates/ReminderSystem.o remind.o -o remind

remind.o: remind.c
	gcc -c remind.c

Dates/ReminderSystem.o: Dates/ReminderSystem.c Dates/ReminderSystem.h
	gcc -c Dates/ReminderSystem.c -o Dates/ReminderSystem.o
	
clean: 
	rm *.o remind Dates/*.o
