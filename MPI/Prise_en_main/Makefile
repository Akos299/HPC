MPICC = mpicc

all : hello.exe

run : hello.exe
	mpirun -np 10 ./$<

hello.exe : hello.c
	$(MPICC) -o $@ $<

clean :
	rm -rf *.exe

