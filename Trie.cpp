/**
 * A Trie is a general tree structure that have 26 sub-trees. 
 * It is helpful for retrieving dictionary words. 
 * 
 * @reference: CS3505 FA2021, School of Computing, University of Utah
 * @author Albert Liu
 * This is owned by Albert Liu
 */

#include "Trie.h"

#include <iostream>

const int ASCII_OFFSET = 97;
const int ARRAY_SIZE = 26;

    /**
     * the constructor
     * initialzes isWord to false, 
     * iterate through the next array and point them all to nullptr. 
     */
    Trie::Trie()
    {
        this->isWord = false;
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            next[i] = nullptr; 
        }
    }

    /**
     * Copy constructor
     * makes a deep copy of the other.  
     * 
     */
    Trie::Trie(Trie &other)
    {
        this->isWord = other.isWord;
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            Trie* tmp = other.next[i];
            if (tmp == nullptr)
            {
                this->next[i] = nullptr;
            }
            else
            {
                this->next[i] = new Trie(*tmp);
            }
        }
    }

    /**
     * Destructor: 
     * iterate through the next array. 
     * free the memory on the heap. 
     * 
     * it doesn't free itself because it is 
     * assumed to be allocated on the stack. 
     */
    Trie::~Trie()
    {
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            if (next[i] != nullptr) delete next[i];
        }
    }

    /**
     * overloading the assignment operator
     * 
     * Using the copy-and-swap technique to assign 
     * the right hand side to the left hand side. 
     * 
     */
    Trie& Trie::operator=(Trie rhs)
    {
        std::swap(this->isWord, rhs.isWord);
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            std::swap(this->next[i], rhs.next[i]);
        }
        return *this;
    }

    /**
     * add a word to the Trie
     * 
     * duplicate adds should not change the Trie.
     * assumes the word is made up of lower-case characters from a-z
     * 
     */
    void Trie::addAWord(std::string word)
    {   
        if (word.size() == 0) // ignore empty strings
        {
            return;
        }

        char c = word.at(0);
        int idx = (int)c - ASCII_OFFSET; // looking at the first character. 
        if (this->next[idx] == nullptr) // initialize that node if haven't. 
        {
            this->next[idx] = new Trie(); // initialize the pointer
        }  

        // base case
        // if it is the last character
        if (word.size() == 1) 
        {
            this->next[idx]->isWord = true;
        }
        else // for word size greater than 1
        {   // recursively adding all characters of words until it reaches the end. 
            (this->next[idx])->addAWord(word.substr(1, word.size()-1)); 
        }
    }

    /**
     * check if a "word" exists
     * If the "word" is found in the Trie, 
     * the method should return true, 
     * otherwise return false. 
     * 
     * return false if "word" is empty string
     */
    bool Trie::isAWord(std::string word)
    {
        int word_size = word.size();
        int i = 0;
        Trie *current_node = this;

        // iterate until the end of the word is reached. 
        // continue going to current_node.next until word size
        while (i < word_size) 
        {
            int charIdx = (int)(word.at(i)) - ASCII_OFFSET;
            current_node = (current_node->next)[charIdx]; // current node is at charIdx

            if (current_node == nullptr) // return false if word is not word anymore. 
                return false;
            i++;
        }

        if (current_node->isWord)
            return true;
        else
            return false;
    }


    /**
     * selects all words in the Trie starting with the "prefix", 
     * and return them in a vector
     * 
     * return an empty vector if there is no matching words
     * with the "prefix". 
     * 
     * the vector will not contain any words that are contained inside of prefix
     * for example: 
     *      pen is not inside of allWordsStartingWithPrefix("pencil");
     */
    std::vector<std::string> Trie::allWordsStartingWithPrefix(const std::string prefix)
    {
        int prefix_size = prefix.size();
        int i = 0;
        Trie *current_node = this;

        // iterate until the end prefix is reached. 
        // continue going to current_node.next until 
        // prefix_size 
        while (i < prefix_size) 
        {
            int charIdx = (int)(prefix.at(i)) - ASCII_OFFSET;
            current_node = (current_node->next)[charIdx]; // current node is at charIdx
            if (current_node == nullptr)
            {
                return {};
            }
            i++;
        }
        
        return current_node->allWordsUnderneath(prefix);
    }

    /**
     * helper for allWordsStartingWithPrefix. 
     */
    std::vector<std::string> Trie::allWordsUnderneath(std::string current_word)
    {
        std::vector<std::string> words;
        if (this->isWord)
        {
            words.push_back(current_word);
        }
        
        for (int i = 0; i < ARRAY_SIZE; i++) 
        {
            if (this->next[i] != nullptr) {  
                // std::cout << this->next[i]->data << std::endl;   
                std::string new_word = current_word + char(i + ASCII_OFFSET);   
                std::vector<std::string> temp = this->next[i]->allWordsUnderneath(new_word);   
                words.insert(words.end(), temp.begin(), temp.end());    
            }   
        }   
        return words;   
    }
