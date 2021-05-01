#include <iostream>
#include "TestBST.h"
#include "Trie.h"
#include <cstdio>
#include <fstream>
#include <string>
int main() {
//    BST t;
//    t.insert(Data(1,1,1));
//    t.insert(Data(1,1,9));
//    t.insert(Data(1,6,1));
//    t.insert(Data(1,8,3));
//    t.insert(Data(15,5,1));
//    t.insert(Data(11,11,10));
//    t.insert(Data(11,10,11));
//    t.insert(Data(22,22,22));
//    cout << t.size() << endl;
//    t.eraseRange(Data(1,1,1), Data(22,22,22));
//    cout << t.size() << endl;
//    testBinarySearchTree();
    Trie tr;
    ifstream file("C:\\Users\\Victor\\Documents\\ADS\\Lab2_4\\words_alpha.txt");
    string str;
    while(getline(file,str, '\n'))
    {
        tr.insert(str);
    }
    file.close();
    tr.findByPrefix("abobra");
    return 0;
}
