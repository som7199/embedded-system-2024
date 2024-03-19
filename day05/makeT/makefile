queue: main.o queue.o
  gcc -o queue main.c queue.c

main.o: main.c
  gcc -c main.c queue.h

queue.o: queue.c
  gcc -c queue.c queue.h
