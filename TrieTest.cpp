/**
 * The main function for testing the Trie data structure
 * 
 * A Trie is a general tree structure that have 26 sub-trees. 
 * It is helpful for retrieving dictionary words. 
 * 
 * @reference: CS3505 FA2021, School of Computing, University of Utah
 * @author Albert Liu
 * This is owned by Albert Liu
 */

#include "Trie.h"

#include <iostream>
#include <fstream>

/******
 * 
 * testing allWordsStartingWithPrefix and isAWord
 * 
 */
int testSearch(std::string filename, Trie &dictionary)
{
    // std::cout << "testing searching: " << std::endl;

    std::ifstream testFile(filename);

    if (testFile.is_open())
    {
        std::string test; 
        while ( getline (testFile,test) )
        {
            bool isword = dictionary.isAWord(test);
            if (isword)
            {
                std::cout << test << " is found" << std::endl;
            }
            else 
            {
                std::vector<std::string> alternatives = dictionary.allWordsStartingWithPrefix(test);
                std::cout << test << " is not found, did you mean:" << std::endl;
                if (alternatives.size() > 0)
                {
                    for (int i = 0; i < alternatives.size(); i++)
                    {
                        std::cout << "   " << alternatives.at(i) << std::endl;
                    }
                }
                else
                {
                    std::cout << "   " << "no alternatives found" << std::endl;
                }
            }
        }
    }
    else
    {
        std::cout << "ERROR: TEST FILE NOT FOUND" << filename << std::endl;
        return 1;
    }
    return 0;
}

int testInsert(std::string filename, Trie &dictionary)
{
    // std::cout << "testing inserting: " << std::endl;
    std::ifstream inputFile(filename);

    if (inputFile.is_open())
    {
        std::string word;
        while ( getline (inputFile,word) )
        {
            // std::cout << "word: " <<  word << std::endl;
            dictionary.addAWord(word); // test add a word
        }
    }
    else
    {
        std::cout << "ERROR: INPUT FILE NOT FOUND" << filename << std::endl;
        return 1;
    }
    return 0;
}

int testCopyConstructor(std::string inputfile, std::string testfile, Trie &dictionary)
{
    // std::cout << "testing copy constructor: " << std::endl;
    Trie dictionaryCopy(dictionary);
    int value_search = testSearch(testfile, dictionary);
    if (value_search) 
        return 1;
    return 0;
}

int testEqualOperator(std::string inputfile, std::string testfile, Trie &dictionary)
{
    // std::cout << "testing equal operator: " << std::endl;
    Trie dictionaryCopy = dictionary;
    int value_search = testSearch(testfile, dictionary);
    if (value_search) 
        return 1;
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3)
    {
        std::cout << "ERROR: only TWO parameter is allowed. Currently: " << (argc-1) << std::endl;
        return 1;
    }

    // testing constructor
    Trie dictionary;
    
    int value_insert = testInsert(argv[1], dictionary);
    if (value_insert) return value_insert;
    // std::cout << "testing insertion complete " << std::endl << std::endl;
    
    int value_search = testSearch(argv[2], dictionary);
    if (value_search) return value_search;

    // std::cout << "testing search complete " << std::endl << std::endl;
    int value_constructor = testCopyConstructor(argv[1], argv[2], dictionary);
    if (value_constructor) return value_constructor;
    // std::cout << "testing copy constructor complete " << std::endl << std::endl;

    int value_equal_operator = testEqualOperator(argv[1], argv[2], dictionary);
    if (value_equal_operator) return value_equal_operator;
    // std::cout << "testing equal operator complete " << std::endl << std::endl;
}

