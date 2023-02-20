#include "gtest/gtest.h"
#include "Trie.h"
#include <vector>

TEST(TrieTests, TestTest) {
    ASSERT_TRUE(true);
}

TEST(TrieTests, AddWord) {
    Trie* t = new Trie();

    t->addAWord("yeehaw");
    ASSERT_TRUE(t->isAWord("yeehaw"));
}


TEST(TrieTests, Add2Words) {
    Trie* t = new Trie();

    t->addAWord("yee");
    t->addAWord("haw");
    ASSERT_TRUE(t->isAWord("yee"));
    ASSERT_TRUE(t->isAWord("haw"));
}

TEST(TrieTests, AddWordExtension) {
    Trie* t = new Trie();

    t->addAWord("yee");
    t->addAWord("yeehaw");
    ASSERT_TRUE(t->isAWord("yee"));
    ASSERT_TRUE(t->isAWord("yeehaw"));
}

TEST(TrieTests, NotaWord) {
    Trie* t = new Trie();

    t->addAWord("yeehaw");
    ASSERT_FALSE(t->isAWord("yee"));
    ASSERT_FALSE(t->isAWord("haw"));
}

TEST(TrieTests, AddWordTwice) {
    Trie* t = new Trie();

    t->addAWord("yeehaw");
    t->addAWord("yeehaw");
    ASSERT_TRUE(t->isAWord("yeehaw"));
}

TEST(TrieTest, AddEmptyString) {
    Trie* t = new Trie();

    t->addAWord("");
    ASSERT_FALSE(t->isAWord(""));
    ASSERT_FALSE(t->isAWord("yeehaw"));
}

TEST(TrieTest, GetWordsWithPrefix) {
    Trie* t = new Trie();

    t->addAWord("yeehaw");
    t->addAWord("yeejaw");
    t->addAWord("yeecaw");
    t->addAWord("perforated");
    t->addAWord("defenestration");
    t->addAWord("yellow");

    std::vector<std::string> words = t->allWordsBeginningWithPrefix("yee");

    ASSERT_TRUE(std::find(words.begin(), words.end(), "yeehaw") != words.end());
    ASSERT_TRUE(std::find(words.begin(), words.end(), "yeejaw") != words.end());
    ASSERT_TRUE(std::find(words.begin(), words.end(), "yeecaw") != words.end());
}

TEST(TrieTest, GetWordsWithPrefixIncludePrefix) {
    Trie* t = new Trie();

    t->addAWord("ye");
    t->addAWord("yee");
    t->addAWord("yellow");

    std::vector<std::string> words = t->allWordsBeginningWithPrefix("ye");

    ASSERT_TRUE(std::find(words.begin(), words.end(), "ye") != words.end());
    ASSERT_TRUE(std::find(words.begin(), words.end(), "yee") != words.end());
    ASSERT_TRUE(std::find(words.begin(), words.end(), "yellow") != words.end());
}

TEST(TrieTest, CopyConstructor) {
    Trie* t = new Trie();

    t->addAWord("yee");
    
    Trie* r = new Trie(*t);

    r->addAWord("haw");

    ASSERT_TRUE(t->isAWord("yee"));
    ASSERT_FALSE(t->isAWord("haw"));
    ASSERT_TRUE(r->isAWord("yee"));
    ASSERT_TRUE(r->isAWord("haw"));
}

TEST(TrieTest, EqualOperator) {
    Trie* t = new Trie();
    Trie* r = new Trie();

    t->addAWord("yee");
    t->addAWord("haw");

    *r = *t;

    ASSERT_TRUE(r->isAWord("yee"));
    ASSERT_TRUE(r->isAWord("haw"));
}