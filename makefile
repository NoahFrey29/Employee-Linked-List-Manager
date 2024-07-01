proFile: mainA3.o helperA3.o recruitEmployee.o printAll.o printOne.o lookOnId.o lookOnFullName.o countEmployees.o sortEmployeesId.o fireOne.o fireAll.o
	gcc -std=c99 -g -Wall mainA3.o helperA3.o recruitEmployee.o printAll.o printOne.o lookOnId.o lookOnFullName.o countEmployees.o sortEmployeesId.o fireOne.o fireAll.o -o bin/proFile
mainA3.o: src/mainA3.c include/headerA3.h
	gcc -std=c99 -Wall -g -c src/mainA3.c
helperA3.o: src/helperA3.c include/headerA3.h
	gcc -std=c99 -Wall -g -c src/helperA3.c
recruitEmployee.o: src/recruitEmployee.c include/headerA3.h
	gcc -std=c99 -Wall -g -c src/recruitEmployee.c
printAll.o: src/printAll.c include/headerA3.h
	gcc -std=c99 -Wall -g -c src/printAll.c
printOne.o: src/printOne.c include/headerA3.h
	gcc -std=c99 -Wall -g -c src/printOne.c
lookOnId.o: src/lookOnId.c include/headerA3.h
	gcc -std=c99 -Wall -g -c src/lookOnId.c
lookOnFullName.o: src/lookOnFullName.c include/headerA3.h
	gcc -std=c99 -Wall -g -c src/lookOnFullName.c
countEmployees.o: src/countEmployees.c include/headerA3.h
	gcc -std=c99 -Wall -g -c src/countEmployees.c
sortEmployeesId.o: src/sortEmployeesId.c include/headerA3.h
	gcc -std=c99 -Wall -g -c src/sortEmployeesId.c
fireOne.o: src/fireOne.c include/headerA3.h
	gcc -std=c99 -Wall -g -c src/fireOne.c
fireAll.o: src/fireAll.c include/headerA3.h
	gcc -std=c99 -Wall -g -c src/fireAll.c
clean:
	rm *.o bin/proFile