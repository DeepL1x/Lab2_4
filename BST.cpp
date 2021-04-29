//
// Created by Victor on 27.04.2021.
//

#include "BST.h"
#include <iostream>
Data::Data() {
    totalMass = 1 + rand() % 10000;
    daysToSpoilage = 1 + rand() % 365;
    countOfRaisins = rand() % 7048;
}

Data::Data(int aTotalMass, int aDaysToSpoilage, int aCountOfRaisins) {
    totalMass = aTotalMass;
    daysToSpoilage = aDaysToSpoilage;
    countOfRaisins = aCountOfRaisins;
}

SplittedBST::SplittedBST() {
    left = nullptr;
    right = nullptr;
}

SplittedBST::SplittedBST(Node *aLeft, Node *aRight) {
    left = aLeft;
    right = aRight;
}
bool Data::operator < (const Data &aSecond) const {
    if (daysToSpoilage != aSecond.daysToSpoilage)
        return daysToSpoilage < aSecond.daysToSpoilage;
    if (totalMass != aSecond.totalMass)
        return totalMass < aSecond.totalMass;
    return countOfRaisins < aSecond.countOfRaisins;
}

bool Data::operator > (const Data &aSecond) const {
    if (daysToSpoilage != aSecond.daysToSpoilage)
        return daysToSpoilage > aSecond.daysToSpoilage;
    if (totalMass != aSecond.totalMass)
        return totalMass > aSecond.totalMass;
    return countOfRaisins > aSecond.countOfRaisins;
}

bool Data::operator == (const Data &aSecond) const {
    return (daysToSpoilage == aSecond.daysToSpoilage && totalMass == aSecond.totalMass && countOfRaisins == aSecond.countOfRaisins);
}
//bool Data::operator < (const Data &aSecond) const {
//    return (3 * daysToSpoilage + 2 * totalMass + countOfRaisins) <
//        (3 * aSecond.daysToSpoilage + 2 * aSecond.totalMass + aSecond.countOfRaisins);
//}
//
//bool Data::operator > (const Data &aSecond) const {
//    return (3 * daysToSpoilage + 2 * totalMass + countOfRaisins) >
//        (3 * aSecond.daysToSpoilage + 2 * aSecond.totalMass + aSecond.countOfRaisins);
//}
//
//bool Data::operator == (const Data &aSecond) const {
//    return (3 * daysToSpoilage + 2 * totalMass + countOfRaisins) ==
//        (3 * aSecond.daysToSpoilage + 2 * aSecond.totalMass + aSecond.countOfRaisins);
//}

Node::Node(Data aKey) {
    data = aKey;
}

void BST::insert(const Data& aKey) {
    root = insert(root, aKey);
}

Node* BST::insert(Node *aNode, const Data& aKey) {
    if (aNode == nullptr) {
        realsize++;
        return new Node(aKey);
    }
    else if (aNode->data > aKey)
        aNode->left = insert(aNode->left, aKey);
    else if (aNode->data < aKey)
        aNode->right = insert(aNode->right, aKey);
    else if (aNode->data == aKey)
        aNode->data = aKey;
    return aNode;
}

Node *BST::minimum(Node *aNode) {
    if (aNode->left == nullptr)
        return aNode;
    return minimum(aNode->left);
}

void BST::erase(const Data& aKey) {
    root = erase(root, aKey);
}

Node* BST::erase(Node *aNode, const Data& aKey) {
    if (aNode == nullptr)
        return aNode;

    if (aKey < aNode->data)
        aNode->left = erase(aNode->left, aKey);
    else if (aKey > aNode->data)
        aNode->right = erase(aNode->right, aKey);
    else if (aNode->left != nullptr && aNode->right != nullptr) {
        aNode->data = minimum(aNode->right)->data;
        aNode->right = erase(aNode->right, aNode->data);
    }
    else {
        if (aNode->left != nullptr) {
            Node *temp = aNode->left;
            delete aNode;
            aNode = temp;
        }
        else if (aNode->right != nullptr) {
            Node *temp = aNode->right;
            delete aNode;
            aNode = temp;
        }
        else {
            delete aNode;
            aNode = nullptr;
        }
        realsize--;
        return aNode;
    }
}
bool BST::find(const Data& aKey) {
    Node *temp = find(root, aKey);
    if (temp == nullptr)
        return 0;
    return 1;
}
Node *BST::find(Node *aNode, const Data& aKey) {
    if (aNode == nullptr || aKey  == aNode->data)
        return aNode;
    if (aKey < aNode->data)
        return find(aNode->left, aKey);
    return find(aNode->right, aKey);
}

void BST::print() {
    print(root);
}

void BST::print(Node *aNode) {
    if (aNode != nullptr) {
        print(aNode->left);
        std::cout << aNode->data.totalMass;
        print(aNode->right);
    }
}

int BST::size() {
    return realsize;
}

int BST::findInRange(const Data& aMin, const Data& aMax) {
    int counter = 0;
    findInRange(root, counter, aMin, aMax);
    return counter;
}

void BST::findInRange(Node *aNode, int &aCounter, const Data& aMin, const Data& aMax) {
    if (aNode == nullptr)
        return;
    if (aNode->data == aMin && aNode->data == aMax) {
        aCounter++;
        return;
    }
    if ((aMin < aNode->data && aNode->data < aMax) || aNode->data == aMax || aNode->data == aMin) {
        aCounter++;
        findInRange(aNode->left, aCounter, aMin, aMax);
        findInRange(aNode->right, aCounter, aMin, aMax);
    }
    else if (aNode->data < aMin)
        findInRange(aNode->right, aCounter, aMin, aMax);
    else findInRange(aNode->left,aCounter, aMin, aMax);
}

int BST::height() {
    return height(root);
}

int BST::height(Node* aNode) {
    if (!aNode)
        return 0;
    else {
        int left_height = height(aNode->left);
        int right_height = height(aNode->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}

SplittedBST BST::split(Node *aNode, const Data& aKey) {
    if (aNode == nullptr) {
        return SplittedBST();
    }
    else if (aKey > aNode->data) {
        SplittedBST temp = split(aNode->right, aKey);
        aNode->right = temp.left;
        return SplittedBST(aNode, temp.right);
    }
    else {
        SplittedBST temp = split(aNode->left, aKey);
        aNode->right = temp.right;
        return SplittedBST(temp.left, aNode);
    }
}

Node *BST::merge(Node *aLeft, Node *aRight) {
    if (aLeft == nullptr)
        return aRight;
    if (aRight == nullptr)
        return aLeft;
    else if (aLeft->data > aRight->data){
        aLeft->right = merge(aLeft->right, aRight);
        return aLeft;
    }
    else{
        aRight->left = merge(aLeft, aRight->left);
        return aRight;
    }
}
void BST::deteleTree(Node *aNode, Data aKey){
    if (aNode != nullptr){
        aNode = erase(aNode, aKey);
        deteleTree(aNode, minimum(aNode)->data);
    }
}
Node *BST::eraseRange(Node *aNode, const Data& aMin, const Data& aMax) {
    if (aNode == nullptr)
        return aNode;
    if (aNode->data < aMin) {
        SplittedBST temp1 = split(aNode, aMin);
        SplittedBST temp2 = split(temp1.right, aMax);
        aNode = merge(temp1.left, temp2.right);
        deteleTree(temp2.left, minimum(temp2.left)->data);
    }

}
void BST::eraseRange(const Data& aMin, const Data& aMax) {
    eraseRange(root, aMin, aMax);
}

void BST::eraseInRange(Node *aNode, const Data& aMin, const Data& aMax) {
    if (aNode == nullptr)
        return;
    if (aNode->data == aMin && aNode->data == aMax) {
        aNode = erase(aNode, aNode->data);
        return;
    }
    if ((aMin < aNode->data && aNode->data < aMax) || aNode->data == aMax || aNode->data == aMin) {
        aNode = erase(aNode, aNode->data);
        eraseInRange(aNode->left, aMin, aMax);
        eraseInRange(aNode->right, aMin, aMax);
    }
    else if (aNode->data < aMin)
        eraseInRange(aNode->right, aMin, aMax);
    else eraseInRange(aNode->left, aMin, aMax);
}

