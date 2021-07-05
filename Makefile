CFLAGS= -Wall -Wextra -O3 -Os -fno-exceptions -ffunction-sections -fdata-sections

BFI: main.o
	$(CXX) $^ -o $@
	rm -rf *.o

main.o: main.cc
	$(CXX) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf BFI *.o
