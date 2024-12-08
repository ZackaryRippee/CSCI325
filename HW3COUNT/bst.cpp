#include "bst.h"

BST::BST() : root(nullptr) {}

BST::~BST() {
    deleteTree(root);
}

BST::Node* BST::insert(Node* node, const std::string& key, int data) {
    if (node == nullptr) {
        return new Node(key, data);
    }
    if (key < node->key) {
        node->left = insert(node->left, key, data);
    } else if (key > node->key) {
        node->right = insert(node->right, key, data);
    } else {
        node->data = data;  // Overwrite the value if key already exists
    }
    return node;
}

void BST::set(const std::string& key, int data) {
    root = insert(root, key, data);
}

BST::Node* BST::find(Node* node, const std::string& key) {
    if (node == nullptr || node->key == key) {
        return node;
    }
    if (key < node->key) {
        return find(node->left, key);
    }
    return find(node->right, key);
}

int BST::find(const std::string& key) {
    Node* result = find(root, key);
    if (result) {
        return result->data;
    }
    return -1;  // Key not found
}

BST::Node* BST::findMin(Node* node) {
    while (node && node->left != nullptr) {
        node = node->left;
    }
    return node;
}

BST::Node* BST::findMax(Node* node) {
    while (node && node->right != nullptr) {
        node = node->right;
    }
    return node;
}

void BST::min() {
    Node* result = findMin(root);
    if (result) {
        std::cout << "Min: (" << result->key << ", " << result->data << ")" << std::endl;
    } else {
        std::cout << "Tree is empty." << std::endl;
    }
}

void BST::max() {
    Node* result = findMax(root);
    if (result) {
        std::cout << "Max: (" << result->key << ", " << result->data << ")" << std::endl;
    } else {
        std::cout << "Tree is empty." << std::endl;
    }
}

void BST::printInOrder(Node* node) {
    if (node == nullptr) return;
    printInOrder(node->left);
    std::cout << "(" << node->key << ", " << node->data << ")" << std::endl;
    printInOrder(node->right);
}

void BST::print() {
    printInOrder(root);
}

BST::Node* BST::deleteNode(Node* node, const std::string& key) {
    if (node == nullptr) return node;
    if (key < node->key) {
        node->left = deleteNode(node->left, key);
    } else if (key > node->key) {
        node->right = deleteNode(node->right, key);
    } else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = findMin(node->right);
        node->key = temp->key;
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->key);
    }
    return node;
}

void BST::deleteKey(const std::string& key) {
    root = deleteNode(root, key);
}

void BST::saveFile(Node* node, std::ofstream& outFile) {
    if (node == nullptr) return;
    saveFile(node->left, outFile);
    outFile << node->key << " " << node->data << std::endl;
    saveFile(node->right, outFile);
}

void BST::saveFile(const std::string& filename) {
    std::ofstream outFile(filename);
    saveFile(root, outFile);
    outFile.close();
}

void BST::deleteTree(Node* node) {
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

int& BST::operator[](const std::string& key) {
    Node* result = find(root, key);
    if (!result) {
        set(key, 0);
        result = find(root, key);
    }
    return result->data;
}
