CC = g++ -g -Wall -fdiagnostics-color=always -fsanitize=undefined -fsanitize=address

TrieTest: TrieTest.o Trie.o
	$(CC) -o TrieTest TrieTest.o Trie.o

TrieTest.o: TrieTest.cpp
	$(CC) -c TrieTest.cpp

Trie.o: Trie.cpp
	$(CC) -c Trie.cpp

clean:
	rm ./TrieTest ./*.o

test:
	echo 'not implemented'
