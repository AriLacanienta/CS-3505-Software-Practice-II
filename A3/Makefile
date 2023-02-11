CC = g++ -g -Wall -fdiagnostics-color=always -fsanitize=undefined -fsanitize=address

TrieTest: TrieTest.o Trie.o TrieNode.o
	$(CC) -o TrieTest TrieTest.o Trie.o TrieNode.o

TrieTest.o: TrieTest.cpp
	$(CC) -c TrieTest.cpp

Trie.o: Trie.cpp TrieNode.o
	$(CC) -c Trie.cpp

Node.o: TrieNode.cpp
	$(CC) -c Node.cpp

clean:
	rm ./TrieTest ./*.o

test: TrieTest
	./TrieTest test_dict.txt test_queries.txt

alttest: TrieTest
	./TrieTest alt_dict.txt alt_queries.txt
