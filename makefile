casinoSimulator: VPHeader.h blackjackHeader.h projectHeader.h videoPoker.o VPFunctions.o misc.o UI.o checkWinCondition.o main.o blackjack.o cardFunctions.o dealerAction.o hashFunction.o BasicStrategy.o 
	gcc videoPoker.o VPFunctions.o misc.o UI.o checkWinCondition.o main.o blackjack.o cardFunctions.o dealerAction.o hashFunction.o BasicStrategy.o -o casinoSimulator -lm

videoPoker.o: VPHeader.h videoPoker.c
	gcc -c videoPoker.c

VPFunctions.o: VPHeader.h VPFunctions.c
	gcc -c VPFunctions.c

misc.o: VPHeader.h blackjackHeader.h projectHeader.h misc.c
	gcc -c misc.c

UI.o: VPHeader.h blackjackHeader.h projectHeader.h UI.c
	gcc -c UI.c

checkWinCondition.o: VPHeader.h checkWinCondition.c
	gcc -c checkWinCondition.c

main.o: projectHeader.h VPHeader.h blackjackHeader.h main.c
	gcc -c main.c

blackjack.o: blackjackHeader.h blackjack.c
	gcc -c blackjack.c

cardFunctions.o: blackjackHeader.h cardFunctions.c
	gcc -c cardFunctions.c

dealerAction.o: blackjackHeader.h dealerAction.c
	gcc -c dealerAction.c

hashFunction.o: blackjackHeader.h hashFunction.c
	gcc -c hashFunction.c

BasicStrategy.o: blackjackHeader.h BasicStrategy.c
	gcc -c BasicStrategy.c

clean: 
	-rm *.o
