//
// Created by Victor on 30.04.2021.
//

#ifndef LAB2_4_TRIE_H
#define LAB2_4_TRIE_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct TrieNode{
    bool isEnd = false;
    unordered_map<char, TrieNode*>map;
    TrieNode();
};

struct Trie {
    TrieNode* root = nullptr;
    Trie();
    vector<string>setOfWords;
    void insert(string aWord);
    void insert(TrieNode* aNode, string aWord);
    void findByPrefix(string aWord);
    void findByPrefix(unordered_map<char, TrieNode*>&map, string aWord, string aPrefix);
    void print(vector<string>setOfWords);
};

#endif //LAB2_4_TRIE_H
