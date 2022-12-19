MPICC = mpicc

all : ping_pong.exe  ping_pong_2.exe

run : ping_pong_2.exe
	mpirun -np 10 ./$<

ping_pong.exe : ping_pong.c
	$(MPICC) -o $@ $<


ping_pong_2.exe : ping_pong_2.c
	$(MPICC) -o $@ $< -lm 

clean :
	rm -rf *.exe

