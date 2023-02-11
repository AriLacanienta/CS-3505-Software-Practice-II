CC = g++ -g -Wall -fdiagnostics-color=always -fsanitize=undefined -fsanitize=address

TrieTest: TrieTest.o Trie.o Node.o
	$(CC) -o TrieTest TrieTest.o Trie.o Node.o

TrieTest.o: TrieTest.cpp
	$(CC) -c TrieTest.cpp

Trie.o: Trie.cpp Node.o
	$(CC) -c Trie.cpp

Node.o: Node.cpp
	$(CC) -c Node.cpp

clean:
	rm ./TrieTest ./*.o

test: TrieTest
	./TrieTest test_dict.txt test_queries.txt

alttest: TrieTest
	./TrieTest alt_dict.txt alt_queries.txt
