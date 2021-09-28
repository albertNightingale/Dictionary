# Trie (A dictionary)

## Credit
This project is implemented by Albert Liu. 

## Project Description
This project is built in C++
Trie is a generalized tree data structure holding characters ranging from a-z lowercase. 
Each tree node holds 26 sub-children, represented by Trie pointer. 
Other than the root node, which have the option to initialize on the stack or on the heap. All sub-nodes are on the heap. 
The only data Trie holds is a boolean variable indicating whether this Trie marks the end of a word. 

## Documentation: 
COMING SOON!!!

## Files
Trie.h: header file of Trie class. 
Trie.cpp: cpp file of the Trie class, contains Trie implementations. 
TrieTest.cpp: testing file of the Trie class. 
Makefile: used for the assembly and execution of make file

## Performance
COMING SOON!!!

## Example
adding the word "cat": 
You have a root node (N1) with N1.isword = false. 
N1.next[c] is pointing to N2. N2.isword = false. 
N2.next[a] is pointing to N3. N3.isword = false.  
N3.next[t] is pointing to N4. N4.isword = true. 
N4 is not pointing to anything, marking the end of the word. 

## Application

## Reference: 
Tutorials on Trie Data Structure
https://www.geeksforgeeks.org/trie-insert-and-search/
https://www.youtube.com/watch?v=-urNrIAQnNo