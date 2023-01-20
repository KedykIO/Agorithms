#include <iostream>
#include <vector>

void Merge(std::vector<int>& base_vector, int left, int right) {
    std::vector<int> tmp;
    int left_index = left;
    int right_index = (left + right) / 2 + 1;
    while (left_index <= (left + right) / 2  && right_index <= right) {
        if (base_vector[left_index] < base_vector[right_index]) {
            tmp.push_back(base_vector[left_index]);
            left_index++;
        }
        else {
            tmp.push_back(base_vector[right_index]);
            right_index++;
        }
    }
    while (left_index <= (left + right) / 2) {
        tmp.push_back(base_vector[left_index]);
        left_index++;
    }
    while (right_index <= right) {
        tmp.push_back(base_vector[right_index]);
        right_index++;;
    }
    for (int i = left; i <= right; i++) {
        base_vector[i] = tmp[i - left];
    }
}

void MergeSort(std::vector<int>& base_vector, int left, int right) {
    if (right - left <= 0) {
        return;
    }
    if (right - left == 1) {
        if (base_vector[left] > base_vector[right]) {
            std::swap(base_vector[left], base_vector[right]);
        }
        return;
    }
    MergeSort(base_vector, left, (left + right) / 2);
    MergeSort(base_vector, (left + right) / 2 + 1, right);
    Merge(base_vector, left, right);
}


int main() {
    int vec_size;
    std::cin >> vec_size;
    std::vector<int> vec;
    vec.resize(vec_size);
    for (int i = 0; i < vec.size(); i++) {
        std::cin >> vec[i];
    }
    MergeSort(vec, 0, vec.size() - 1);
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
}
