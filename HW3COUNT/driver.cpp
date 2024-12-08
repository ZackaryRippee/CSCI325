#include <iostream>
#include <fstream>
#include <algorithm>
#include "bst.h"

using namespace std;

void processFile(BST& tree, const string& filename) {
    ifstream inFile(filename);
    string word;

    while (inFile >> word) {
        word.erase(remove_if(word.begin(), word.end(), [](char c) {
            return !isalnum(c) && c != '\'';
        }), word.end());
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        tree[word]++;
    }
}

void displayMenu() {
    cout << "1. Add or update a word\n";
    cout << "2. Find a word\n";
    cout << "3. Print tree\n";
    cout << "4. Find min\n";
    cout << "5. Find max\n";
    cout << "6. Save tree to file\n";
    cout << "7. Delete a word\n";
    cout << "8. Process file\n";
    cout << "9. Exit\n";
}

int main() {
    BST tree;
    string filename, word;
    int choice, value;

    while (true) {
        displayMenu();
        cin >> choice;

        if (choice == 1) {
            cout << "Enter word: ";
            cin >> word;
            cout << "Enter value: ";
            cin >> value;
            tree.set(word, value);
        } else if (choice == 2) {
            cout << "Enter word: ";
            cin >> word;
            cout << "Value: " << tree.find(word) << endl;
        } else if (choice == 3) {
            tree.print();
        } else if (choice == 4) {
            tree.min();
        } else if (choice == 5) {
            tree.max();
        } else if (choice == 6) {
            cout << "Enter filename: ";
            cin >> filename;
            tree.saveFile(filename);
        } else if (choice == 7) {
            cout << "Enter word to delete: ";
            cin >> word;
            tree.deleteKey(word);
        } else if (choice == 8) {
            cout << "Enter filename: ";
            cin >> filename;
            processFile(tree, filename);
        } else if (choice == 9) {
            break;
        } else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
