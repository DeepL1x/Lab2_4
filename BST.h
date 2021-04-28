//
// Created by Victor on 27.04.2021.
//

#ifndef LAB2_4_BST_H
#define LAB2_4_BST_H
#include <string>

struct Data{ /*Easter cake*/
    int totalMass;
    int daysToSpoilage;
    int countOfRaisins;
    Data();
    Data(int aTotalMass, int aDaysToSpoilage, int aCountOfRaisins);
    bool operator < (const Data &aSecond) const;
    bool operator > (const Data &aSecond) const;
    bool operator == (const Data &aSecond) const;
};

struct Node{
    Data data;
    Node *parent = nullptr;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(Data aData);
};

struct BST {
    Node *root = nullptr;
    int realsize = 0;
    void insert (Data aData);
    Node *insert (Node *aNode, Data aData);
    Data minimum (Node *aNode);
    void erase (Data aData);
    Node *erase (Node *root, Data aData);
    bool find (Data aData);
    Node *find (Node* aNode, Data aData);
    void print();
    void print(Node *aNode);
    int findInRange(Data aMin, Data aMax);
    void findInRange(Node *aNode, int &counter, Data aMin, Data aMax);
    int height();
    int height(Node* aNode);
    int size();
};

#endif //LAB2_4_BST_H
