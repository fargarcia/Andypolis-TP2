CC = g++ -Wall -Werror -Wconversion
OBJS = main.o utils.o materials.o buildings.o materialsList.o buildingsList.o

andypolis: $(OBJS)
	$(CC) -o andypolis $(OBJS)
	rm -f *.o *~ 

main.o: src/main.cpp
	$(CC) -o main.o -c src/main.cpp

utils.o: utils/utils.cpp utils/utils.h
	$(CC) -o utils.o -c utils/utils.cpp

materials.o: materials/materials.cpp materials/materials.h
	$(CC) -o materials.o -c materials/materials.cpp

materialsList.o: materials/materialsList.cpp materials/materialsList.h
	$(CC) -o materialsList.o -c materials/materialsList.cpp

buildings.o: buildings/buildings.cpp ./buildings/buildings.h
	$(CC) -o buildings.o -c ./buildings/buildings.cpp

buildingsList.o: buildings/buildingsList.cpp ./buildings/buildingsList.h
	$(CC) -o buildingsList.o -c ./buildings/buildingsList.cpp

valgrind:
	valgrind --tool=memcheck --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./main

run: 
	./andypolis
