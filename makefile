main: main.o person.o teacher.o student.o
	g++ -o main main.o person.o teacher.o student.o

main.o: main.cpp person.h teacher.h student.h
	g++ -c main.cpp

person.o: person.h teacher.h student.h person.cpp
	g++ -c person.cpp

teacher.o: teacher.h student.cpp teacher.cpp
	g++ -c teacher.cpp

student.o: student.h student.cpp
	g++ -c student.cpp




https://drive.google.com/drive/u/2/shared-with-me
