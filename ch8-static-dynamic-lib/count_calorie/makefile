all: elliptical

elliptical.o: elliptical.c
	gcc -c elliptical.c -Iincludes
hfcal.o: hfcal.c
	gcc -c -Iincludes hfcal.c -o hfcal.o
libhfcal.a: hfcal.o
	ar -rcs libs/libhfcal.a hfcal.o
elliptical: elliptical.o libhfcal.a
	gcc  elliptical.o -static -L./libs -lhfcal  -o elliptical
clean:
	rm *.o libs/* elliptical
#ddd
