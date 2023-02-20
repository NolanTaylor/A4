/**
 * Nolan Taylor
 * CS 3505 Assignment 04
 * Refactoring and Testing
 * 
 * The implementation class for Trie, a graph that
 * connects nodes for the 26 lower case letters of
 * the alphabet. Can add words, find words, and find
 * all words with a given prefix.
*/

#include "Trie.h"

/**
 * Constructor for a Node object in the Trie.
*/
Trie::Node::Node() {
    isWord = false;
}

/**
 * This function adds a branch to the Node
 * at the given character a-z.
*/
void Trie::Node::addBranch(char ch) {
    Trie::Node node;
    map.emplace(ch, node);
}

/**
 * Getter function to find the branch at the
 * given character a-z.
*/
Trie::Node* Trie::Node::getBranch(char ch) {
    return &map[ch];
}

bool Trie::Node::hasBranch(char ch) {
    return map.count(ch);
}

/**
 * Setter function for the isWord variable.
*/
void Trie::Node::setWordFlag(bool flag) {
    isWord = flag;
}

/**
 * Getter function for the isWord variable.
*/
bool Trie::Node::getWordFlag() {
    return isWord;
}

/**
 * The node destroys itself and any dependent
 * nodes as well.
*/
void Trie::Node::selfDestruct() {
    for (auto const& [key, val] : map) {
        map[key].selfDestruct();

        delete &map[key];
    }
}

/**
 * Copies this node (and all dependents) onto
 * the given node.
*/
void Trie::Node::copyOnto(Node* copy) {
    for (auto const& [key, val] : map) {
        Trie::Node node;
        copy->map.emplace(key, node);
        copy->map[key].isWord = map[key].isWord;
        map[key].copyOnto(&copy->map[key]);
    }
}

/**
 * Get all the words from the node starting with
 * a prefix string.
*/
std::vector<std::string> Trie::Node::getPrefixWords(std::vector<std::string>* wordsStartingWithPrefixList, std::string paredPrefix, std::string prefixPlusBranches) {
    if (paredPrefix.length() == 0) {
        // when the prefix has been pared down, loop through
        // the rest of the nodes and get all the possible
        // words from there
        for (auto const& [key, val] : map) {
            std::string word = prefixPlusBranches + key;

            if (map[key].getWordFlag()) {
                wordsStartingWithPrefixList->push_back(word);
            }

            map[key].getPrefixWords(wordsStartingWithPrefixList, paredPrefix, prefixPlusBranches);
        }
    }
    else {
        // if the array has the first character of prefix, then
        // call the function again without the first character
        if (map.count(paredPrefix[0])) {
            map[paredPrefix[0]].getPrefixWords(wordsStartingWithPrefixList, paredPrefix.substr(1), prefixPlusBranches);
        }
    }

    return *wordsStartingWithPrefixList;
}

/**
 * Constructor for the Trie.
*/
Trie::Trie() {
    root = new Node;
}

/**
 * Copy constructor for Trie.
*/
Trie::Trie(const Trie& input) {
    root = new Node;

    input.root->copyOnto(this -> root);
}

/**
 * Destructor for Trie.
*/
Trie::~Trie() {
    root->selfDestruct();

    delete root;
}

/**
 * Equals overload operator for Trie. Copies
 * the right hand side onto the current Trie.
*/
Trie& Trie::operator=(Trie rhs) {
    root = new Node;

    rhs.root->copyOnto(this->root);

    return *this;
}

/**
 * Add a word to the Trie. Doesn't do
 * anything if the word already exists.
*/
void Trie::addAWord(std::string string) {
    Node* current = root;

    // loop through all the letters, adding a branch
    // if they don't exist
    for(int i = 0; i < string.length(); i++) {
        if (!current->hasBranch(string[i])) {
            current->addBranch(string[i]);
        }

        current = current->getBranch(string[i]);
    }

    current->setWordFlag(true);
}

/**
 * Returns true if the Trie contains the
 * word and false if otherwise.
*/
bool Trie::isAWord(std::string string) {
    if (string.length() == 0) {
        return false;
    }

    Node* current = root;

    // loop through all the letters to make sure the branches exist
    for (int i = 0; i < string.length(); i++) {
        if (!current->hasBranch(string[i])) {
            return false;
        }
        else {
            current = current->getBranch(string[i]);
        }
    }

    return current->getWordFlag();
}

/**
 * Returns a vector of all words in the Trie
 * beginning with the given prefix string.
*/
std::vector<std::string> Trie::allWordsBeginningWithPrefix(std::string prefix) {
    std::vector<std::string> words;

    root->getPrefixWords(&words, prefix, prefix);

    if (isAWord(prefix)) {
        words.push_back(prefix);
    }

    return words;
}