build: lab3

lab3: main.o graph.o bheap.o list.o queue.o
	gcc -o lab3 main.o graph.o bheap.o list.o queue.o

main.o: main.c
	gcc -g -c -std=c99 main.c

graph.o: graph.c
	gcc -g -c -std=c99 graph.c
    
bheap.o: bheap.c
	gcc -g -c -std=c99 bheap.c

list.o: list.c
	gcc -g -c -std=c99 list.c

queue.o: queue.c
	gcc -g -c -std=c99 queue.c
    
clean:
	rm -rf *.o lab3
