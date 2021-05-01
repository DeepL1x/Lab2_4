//
// Created by Victor on 30.04.2021.
//

#include "Trie.h"

void Trie::insert (string aWord) {
    if (aWord != "") {
        if (root == nullptr)
            root = new TrieNode();
        insert(root, aWord);
    }
}
//void Trie::insert(TrieNode* aNode, string aWord) {
//    if (aWord.length() == 0){
//        return;
//    }
////    unordered_map<char, TrieNode *>::iterator it;
////    it->second = aNode->map[aWord[0]];
//    while (aNode->map.find(aWord[0]) != aNode->map.end()) {
//        insert(aNode->map[aWord[0]], aWord.erase(0));
//    }
//    if (aNode->map.find(aWord[0]) == aNode->map.end()) {
//        aNode->map[aWord[0]] = new TrieNode();
//        if (aWord[1] == '\0') {
//            aNode->map[aWord[0]]->isEnd = 1;
//            return;
//        }
//        insert(aNode->map[aWord[0]], aWord.erase(0));
//    }
//}
void Trie::insert(TrieNode* aNode, string aWord) {
    if (aNode == nullptr){
        aNode = new TrieNode();
    }
    TrieNode* temp = aNode;
    char x;
    for (int i = 0; i < aWord.length(); ++i) {
        x = aWord[i];
        if (temp->map.find(x) == temp->map.end()){
            temp->map[x] = new TrieNode;
        }
        temp = temp->map[x];
    }
    temp->isEnd = true;
}

Trie::Trie() {
    root = new TrieNode();
}

void Trie::findByPrefix(string aWord) {
    if (aWord != "" && root != nullptr) {
        setOfWords.clear();
        findByPrefix(root->map, aWord, aWord);
        print(setOfWords);
    }
}

void Trie::findByPrefix(unordered_map<char, TrieNode*>&map, string aWord, string aPrefix) {
    unordered_map<char, TrieNode*>::iterator it = map.begin();
    if (aWord != "" && it != map.end() && it->second != nullptr) {
        for (; it != map.end(); it++) {
            if (it->first == aWord[0]) {
                if (it->second->isEnd == 1 && aWord.length() == 1)
                    setOfWords.push_back(aPrefix);
                findByPrefix(it->second->map, aWord.erase(0, 1), aPrefix);
            }
        }
    }
    else {
        for (; it != map.end(); it++) {
            if (it->second->isEnd == 1) {
                setOfWords.push_back(aPrefix + it->first);
            }
            findByPrefix(it->second->map, aWord, aPrefix + it->first);
        }
    }
}

void Trie::print(vector<string> setOfWords) {
    vector<string>::iterator it;
    for (it = setOfWords.begin(); it != setOfWords.end(); ++it) {
        cout << *it << " ";
    }
}

TrieNode::TrieNode() {
    isEnd = false;
}
