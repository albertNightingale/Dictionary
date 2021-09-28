/**
 * A Trie is a general tree structure that have 26 sub-trees. 
 * It is helpful for retrieving dictionary words. 
 * 
 * @reference: CS3505 FA2021, School of Computing, University of Utah
 * @author Albert Liu
 * This is owned by Albert Liu
 */

#ifndef TRIE_H
#define TRIE_H

#include <vector>
#include <string>

class Trie {
private: 
    Trie *next[26];
    bool isWord;
    std::vector<std::string> allWordsUnderneath(std::string current_word);
public:
    Trie();
    Trie(Trie &other);
    ~Trie();
    Trie& operator=(Trie rhs);
    void addAWord(std::string word);
    bool isAWord(std::string word);
    std::vector<std::string> allWordsStartingWithPrefix(const std::string prefix);
};

#endif