#makefile to compile all the files

all: cricket

cricket: main.o loginscreen.o scoreWrite.o scoreMaker.o scoreCardPrint.o display.o editableLL.o
	gcc main.o loginscreen.o scoreWrite.o scoreMaker.o scoreCardPrint.o display.o editableLL.o -o cricket
	
main.o: main.c
	gcc -c main.c
	
loginscreen.o: loginscreen.c
	gcc -c loginscreen.c

scoreWrite.o: scoreWrite.c
	gcc -c scoreWrite.c
	
scoreMaker.o: scoreMaker.c
	gcc -c scoreMaker.c

scoreCardPrint.o: scoreCardPrint.c
	gcc -c scoreCardPrint.c
	
display.o: display.c
	gcc -c display.c
	
editableLL.o: editableLL.c
	gcc -c editableLL.c
	
clean:
	rm -rf *o cricket
