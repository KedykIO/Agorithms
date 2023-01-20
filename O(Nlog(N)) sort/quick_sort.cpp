#include <iostream>
#include <vector>

int SortIteration(std::vector<int>& base_vector, int left, int right) {
    int left_index = left;
    int right_index = right - 1;
    std::swap(base_vector[(right + left) / 2], base_vector[right]);
    while (true) {
        while (left_index < right && base_vector[left_index] <= base_vector[right]) {
            left_index++;
        }
        while (right_index >= left && base_vector[right_index] > base_vector[right]) {
            right_index--;
        }
        if (right_index <= left_index) {
            break;
        }
        std::swap(base_vector[left_index], base_vector[right_index]);
    }
    return left_index;
}

void QuickSort(std::vector<int>& base_vector, int left, int right) {
    if (right - left <= 0) {
        return;
    }
    if (right - left == 1) {
        if (base_vector[left] > base_vector[right]) {
            std::swap(base_vector[left], base_vector[right]);
        }
        return;
    }
    int new_base_element = SortIteration(base_vector, left, right);
    QuickSort(base_vector, left, new_base_element - 1);
    QuickSort(base_vector, new_base_element, right);
}

int main() {
    int vec_size;
    std::cin >> vec_size;
    std::vector<int> vec;
    vec.resize(vec_size);
    for (int i = 0; i < vec.size(); i++) {
        std::cin >> vec[i];
    }
    QuickSort(vec, 0, vec.size() - 1);
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
}