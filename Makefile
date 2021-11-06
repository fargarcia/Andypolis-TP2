CC = g++ -Wall -Werror -Wconversion
OBJS = main.o utils.o auxUtils.o materials.o buildings.o materialsList.o buildingsList.o

andypolis: $(OBJS)
	$(CC) -o andypolis $(OBJS)
	rm -f *.o *~ 

main.o: src/main.cpp
	$(CC) -o main.o -c src/main.cpp

utils.o: src/utils/utils.cpp src/utils/utils.h
	$(CC) -o utils.o -c src/utils/utils.cpp

auxUtils.o: src/utils/auxUtils.cpp src/utils/auxUtils.h
	$(CC) -o auxUtils.o -c src/utils/auxUtils.cpp

materials.o: src/materials/materials.cpp src/materials/materials.h
	$(CC) -o materials.o -c src/materials/materials.cpp

materialsList.o: src/materials/materialsList.cpp src/materials/materialsList.h
	$(CC) -o materialsList.o -c src/materials/materialsList.cpp

buildings.o: src/buildings/buildings.cpp src/buildings/buildings.h
	$(CC) -o buildings.o -c src/buildings/buildings.cpp

buildingsList.o: src/buildings/buildingsList.cpp src/buildings/buildingsList.h
	$(CC) -o buildingsList.o -c src/buildings/buildingsList.cpp

valgrind:
	valgrind --tool=memcheck --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./main

run: 
	./andypolis
