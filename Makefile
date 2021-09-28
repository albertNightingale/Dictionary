
EXE = TrieTest
CFLAGS = -std=c++11 -Wall


TrieTest: Trie.o TrieTest.o
	g++ $(CFLAGS) -o TrieTest Trie.o TrieTest.o

TrieTest.o:	Trie.h
	g++ $(CFLAGS) -c TrieTest.cpp 

Trie.o: Trie.h
	g++ $(CFLAGS) -c Trie.cpp
	
clean: 
	rm -f *.o
	rm -f TrieTest
