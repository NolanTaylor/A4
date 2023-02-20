/**
 * Nolan Taylor
 * CS 3505 Assignment 04
 * Refactoring and Testing
 * 
 * The header class for Trie, structures
 * all the functions for Trie and Node
*/

#ifndef TRIE
#define TRIE

#include <iostream>
#include <vector>
#include <map>

class Trie {
private:
    class Node {
    private:
        std::map<char, Node> map;
        bool isWord;

    public:
        Node();

        void addBranch(char);

        Node* getBranch(char);

        bool hasBranch(char);

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