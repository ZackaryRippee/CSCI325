#ifndef BST_H
#define BST_H

#include <string>
#include <iostream>
#include <fstream>

class BST {
private:
    struct Node {
        std::string key;
        int data;
        Node* left;
        Node* right;

        Node(std::string key, int data = 0)
            : key(key), data(data), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(Node* node, const std::string& key, int data);
    Node* find(Node* node, const std::string& key);
    Node* findMin(Node* node);
    Node* findMax(Node* node);
    Node* deleteNode(Node* node, const std::string& key);
    void printInOrder(Node* node);
    void saveFile(Node* node, std::ofstream& outFile);
    void deleteTree(Node* node);

public:
    BST();
    ~BST();

    void set(const std::string& key, int data);
    int find(const std::string& key);
    void print();
    void min();
    void max();
    void saveFile(const std::string& filename);
    void deleteKey(const std::string& key);

    int& operator[](const std::string& key);  // for bonus
};

#endif
