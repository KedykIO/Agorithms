#include <iostream>
#include <vector>

struct Node {
    Node* left_child = nullptr;
    Node* right_child = nullptr;
    int key = 0;
    int index = 0;
};

struct Tree {
    Node* root = nullptr;
    int current_index = 0;
    std::vector<int> unsorted_vector;
    std::vector<int> sorted_vector;

    Tree(std::vector<int>& base_vector) {
        unsorted_vector = base_vector;
        for (int i = 0; i < base_vector.size(); i++) {
            AddElement(base_vector[i]);
        }
        sorted_vector.resize(base_vector.size());
    }
    
    void AddElement(int x) {
        Node* new_node = new Node();
        new_node->key = x;
        if (root == nullptr) {
            root = new_node;
            new_node->index = 1;
            return;
        }
        Node* current = root;
        while (true) {
            if (current->key > new_node->key) {
                if (current->left_child == nullptr) {
                    current->left_child = new_node;
                    new_node->index = 1;
                    return;
                }
                current = current->left_child;
                continue;
            }
            if (current->key < new_node->key) {
                if (current->right_child == nullptr) {
                    current->right_child = new_node;
                    new_node->index = 1;
                    return;
                }
                current = current->right_child;
                continue;
            }
            current->index++;
            return;
        }
    }

    void MinRound(Node* current) {
        if (current == nullptr) {
            return;
        }
        MinRound(current->left_child);
        int tmp = current->index;
        current->index = current_index;
        current_index = current_index + tmp;
        MinRound(current->right_child);        
    }

    Node* Find(int x, Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->key > x) {
            return Find(x, root->left_child);
        }
        if (root->key < x) {
            return Find(x, root->right_child);
        }
        return root;
    }

    void TreeSort() {
        MinRound(root);
        for (int i = 0; i < unsorted_vector.size(); i++) {
            Node* tmp_node = Find(unsorted_vector[i], root);
            sorted_vector[tmp_node->index] = unsorted_vector[i];
            tmp_node->index++;
        }
    }

    void PrintSortedVector() {
        for (int i = 0; i < sorted_vector.size(); i++) {
            std::cout << sorted_vector[i] << " ";
        }
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
    t.PrintSortedVector();
}

