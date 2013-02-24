image.out :	image.o driver.o
	g++  -o gaussian pgmImage.o driver.o `pkg-config --cflags --libs opencv`

image.o :	pgmImage.cpp pgmImage.h
	g++ -c pgmImage.cpp

driver.o :	driver.cpp pgmImage.cpp pgmImage.h
	g++ -c driver.cpp

clean :
	rm *.o 