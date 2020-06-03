all: child orphan zombie
child: child.c 1.h
	gcc -o child child.c
orphan: orphan.c 1.h
	gcc -o orphan orphan.c
zombie: zombie.c 1.h
	gcc -o zombie zombie.c
clean:
	rm child orphan zombie -f
