/**
 * Nolan Taylor
 * CS 3505 Assignment 03
 * A Trie and Rule-of-Three
 * 
 * The header class for Trie, structures
 * all the functions for Trie and Node
*/

#ifndef TRIE
#define TRIE

#include <iostream>
#include <vector>

class Trie {
private:
    class Node {
    private:
        Node *array[26];
        bool isWord;

    public:
        Node();

        void addBranch(char);

        Node* getBranch(char);

        void setWordFlag(bool);

        bool getWordFlag();

        void selfDestruct();

        void copyOnto(Node*);

        std::vector<std::string> getPrefixWords(std::vector<std::string>*, std::string, std::string);
    };

    Node* root;

public:
    Trie();

    Trie(const Trie&);

    ~Trie();

    Trie& operator=(Trie);

    void addAWord(std::string);

    bool isAWord(std::string);

    std::vector<std::string> allWordsBeginningWithPrefix(std::string);
};

#endif