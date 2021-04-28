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

//bool Data::operator < (const Data &aSecond) const {
//    if (daysToSpoilage < aSecond.daysToSpoilage)
//        return daysToSpoilage < aSecond.daysToSpoilage;
//    if (totalMass < aSecond.totalMass)
//        return totalMass < aSecond.totalMass;
//    return countOfRaisins < aSecond.countOfRaisins;
//}
//
//bool Data::operator > (const Data &aSecond) const {
//    if (daysToSpoilage > aSecond.daysToSpoilage)
//        return daysToSpoilage > aSecond.daysToSpoilage;
//    if (totalMass > aSecond.totalMass)
//        return totalMass > aSecond.totalMass;
//    return countOfRaisins > aSecond.countOfRaisins;
//}
//
//bool Data::operator == (const Data &aSecond) const {
//    return (daysToSpoilage == aSecond.daysToSpoilage && totalMass == aSecond.totalMass && countOfRaisins == aSecond.countOfRaisins);
//}
bool Data::operator < (const Data &aSecond) const {
    return (3 * daysToSpoilage + 2 * totalMass + countOfRaisins) <
        (3 * aSecond.daysToSpoilage + 2 * aSecond.totalMass + aSecond.countOfRaisins);
}

bool Data::operator > (const Data &aSecond) const {
    return (3 * daysToSpoilage + 2 * totalMass + countOfRaisins) >
        (3 * aSecond.daysToSpoilage + 2 * aSecond.totalMass + aSecond.countOfRaisins);
}

bool Data::operator == (const Data &aSecond) const {
    return (3 * daysToSpoilage + 2 * totalMass + countOfRaisins) ==
        (3 * aSecond.daysToSpoilage + 2 * aSecond.totalMass + aSecond.countOfRaisins);
}

Node::Node(Data aData) {
    data = aData;
}

void BST::insert(Data aData) {
    root = insert(root, aData);
}

Node* BST::insert(Node *aNode, Data aData) {
    if (aNode == nullptr) {
        realsize++;
        Node *temp = new Node(aData);
        return temp;
    }
    else if (aNode->data > aData)
        aNode->left = insert(aNode->left, aData);
    else if (aNode->data < aData)
        aNode->right = insert(aNode->right, aData);
    else if (aNode->data == aData)
        aNode->data = aData;
    return aNode;
}

Data BST::minimum(Node *aNode) {
    if (aNode->left == nullptr)
        return aNode->data;
    return minimum(aNode->left);
}

void BST::erase(Data aData) {
    root = erase(root, aData);
}

Node* BST::erase(Node *aNode, Data aData) {
    if (aNode == nullptr)
        return aNode;

    if (aData < aNode->data)
        aNode->left = erase(aNode->left, aData);
    else if (aData > aNode->data)
        aNode->right = erase(aNode->right, aData);
    else if (aNode->left != nullptr && aNode->right != nullptr) {
        aNode->data = minimum(aNode->right);
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
bool BST::find(Data aData) {
    Node *temp = find(root, aData);
    if (temp == nullptr)
        return 0;
    return 1;
}
Node *BST::find(Node *aNode, Data aData) {
    if (aNode == nullptr || aData  == aNode->data)
        return aNode;
    if (aData < aNode->data)
        return find(aNode->left, aData);
    return find(aNode->right, aData);
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

int BST::findInRange(Data aMin, Data aMax) {
    int counter = 0;
    findInRange(root, counter, aMin, aMax);
    return counter;
}

void BST::findInRange(Node *aNode, int &aCounter, Data aMin, Data aMax) {
    if (aNode != nullptr) {
        findInRange(aNode->left, aCounter, aMin, aMax);
//        if (aMax < aNode->data)
//            return;
        if ((aMin < aNode->data && aNode->data < aMax) || aNode->data == aMax || aNode->data == aMin)
            aCounter++;
        findInRange(aNode->right,aCounter, aMin, aMax);
    }
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




