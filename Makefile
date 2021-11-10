CC = g++ -Wall -Werror -Wconversion
OBJS = main.o utils.o materials.o materialsList.o buildings.o buildingType.o template.o map.o city.o cityUtils.o tile.o

andypolis: $(OBJS)
	$(CC) -o andypolis $(OBJS)
	rm -f *.o *~ 

main.o: src/main.cpp
	$(CC) -o main.o -c src/main.cpp

utils.o: src/utils/utils.cpp src/utils/utils.h
	$(CC) -o utils.o -c src/utils/utils.cpp

materials.o: src/materials/materials.cpp src/materials/materials.h
	$(CC) -o materials.o -c src/materials/materials.cpp

materialsList.o: src/materials/materialsList.cpp src/materials/materialsList.h
	$(CC) -o materialsList.o -c src/materials/materialsList.cpp

buildings.o: src/buildings/buildings.cpp src/buildings/buildings.h
	$(CC) -o buildings.o -c src/buildings/buildings.cpp

buildingType.o: src/buildings/buildingType.cpp src/buildings/buildingType.h
	$(CC) -o buildingType.o -c src/buildings/buildingType.cpp

template.o: src/buildings/template.cpp src/buildings/template.h
	$(CC) -o template.o -c src/buildings/template.cpp

city.o: src/city/city.cpp src/city/city.h
	$(CC) -o city.o -c src/city/city.cpp

cityUtils.o: src/city/utils/utils.cpp src/city/utils/utils.h
	$(CC) -o cityUtils.o -c src/city/utils/utils.cpp

map.o: src/map/map.cpp src/map/map.h
	$(CC) -o map.o -c src/map/map.cpp	

tile.o: src/map/tile/tile.cpp src/map/tile/tile.h
	$(CC) -o tile.o -c src/map/tile/tile.cpp	

valgrind:
	valgrind --tool=memcheck --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./andypolis

run: 
	./andypolis
