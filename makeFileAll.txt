


#==========part2=================
#link
base : base.o
	gcc -m32 -g -Wall -o base base.o

#compile base.c
base.o : base.c
	gcc -m32 -g -Wall -c -o base.o base.c

#==========part3=================
menu_map : menu_map.o
	gcc -m32 -g - Wall -o menu_map menu_map.o

menu_map.o : menu_map.c
	gcc -m32 -g -Wall -c -o menu_map.o menu_map.c
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
	rm -f *.o count-words addresses base menu_map
