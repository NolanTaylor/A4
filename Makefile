GOOGLETEST ?= ../../googletest

TrieTests: Trie.o TrieTests.cpp
	g++ -Wall TrieTests.cpp Trie.o -o TrieTests -L$(GOOGLETEST)/lib -I$(GOOGLETEST)/googletest/include -lgtest -lgtest_main -lpthread

Trie.o: Trie.h Trie.cpp
	g++ -Wall -c -I. Trie.cpp -g

clean:
	rm *.o
	rm TrieTests

test:
	./TrieTests