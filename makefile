





#==========part1=================
#link
addresses : addresses.o
	gcc -m32 -g -Wall -o addresses addresses.o

#compile count-words.c
addresses.o : addresses.c
	gcc -m32 -g -Wall -c -o addresses.o addresses.c

#===========part0=======================
#link
count-words : count-words.o
	gcc -m32 -g -Wall -o count-words count-words.o

#compile count-words.c
count-words.o : count-words.c
	gcc -m32 -g -Wall -c -o count-words.o count-words.c

#clean
clean :
	rm -f *.o count-words addresses