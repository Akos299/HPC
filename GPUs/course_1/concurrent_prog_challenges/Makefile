CXXFLAG = gcc
LXXFLAG = -lpthread -lm

all: ph_din.exe

ph_din.exe : main.o ph_din.o
	$(CXXFLAG) -o $@ $^ $(LXXFLAG)

main.o : ./ph_din/src/main.c
	$(CXXFLAG) -o $@ -c $^ 

ph_din.o : ./ph_din/src/dining.c 
	$(CXXFLAG) -o $@ -c $^ 

.PHONY: clean

clean:
	rm -rf *.exe *.o

