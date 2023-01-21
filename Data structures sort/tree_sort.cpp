#include <iostream>
#include <vector>

struct Node {
    Node* left_child = nullptr;
    Node* right_child = nullptr;
    int key = 0;
};

struct Tree {
    Node* root = nullptr;

    Tree(std::vector<int>& base_vector) {
        for (int i = 0; i < base_vector.size(); i++) {
            AddElement(base_vector[i]);
        }
    }

    void AddElement(int x) {
        Node* new_node = new Node();
        new_node->key = x;
        if (root == nullptr) {
            root = new_node;
            return;
        }
        Node* current = root;
        while (true) {
            if (current->key > new_node->key) {
                if (current->left_child == nullptr) {
                    current->left_child = new_node;
                    return;
                }
                current = current->left_child;
                continue;
            }
            if (current->right_child == nullptr) {
                current->right_child = new_node;
                return;
            }
            current = current->right_child;

        }
    }

    void MinRound(Node* current) {
        if (current == nullptr) {
            return;
        }
        MinRound(current->left_child);
        std::cout << current->key << " ";
        MinRound(current->right_child);
    }

    void TreeSort() {
        MinRound(root);
    }
};

int main() {
    int vec_size;
    std::cin >> vec_size;
    std::vector<int> vec;
    vec.resize(vec_size);
    for (int i = 0; i < vec.size(); i++) {
        std::cin >> vec[i];
    }
    Tree t(vec);
    t.TreeSort();
}