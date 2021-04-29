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

struct SplittedBST{
    Node* left;
    Node* right;
    SplittedBST();
    SplittedBST(Node *aLeft, Node *aRight);
};

struct BST {
    Node *root = nullptr;
    int realsize = 0;

    void insert (const Data& aKey);
    Node *insert (Node *aNode, const Data& aKey);

    Data minimum (Node *aNode);

    void erase (const Data& aData);
    Node *erase (Node *root, const Data& aKey);

    bool find (const Data& aData);
    Node *find (Node* aNode, const Data& aKey);

    void print();
    void print(Node *aNode);

    int findInRange(const Data& aMin, const Data& aMax);
    void findInRange(Node *aNode, int &counter, const Data& aMin, const Data& aMax);


    int height();
    int height(Node* aNode);

    SplittedBST split(Node* aNode, const Data& aKey);
    Node *merge(Node *aLeft, Node *aRight);

    int size();
};

#endif //LAB2_4_BST_H
