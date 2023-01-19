#include <iostream>
#include<vector>


bool Bubble(std::vector<int>& base_vector, int iteration) {
    bool flag = false;
    for (int j = 0; j < base_vector.size() - 1 - iteration; j++) {
        if (base_vector[j] > base_vector[j + 1]) {
            std::swap(base_vector[j], base_vector[j + 1]);
            flag = true;
        }
    }
    return flag;
}

void BubbleSort(std::vector<int>& base_vector) {
    bool flag = true;
    int i = 0;
    while (flag == true && i<base_vector.size()) {
        flag = Bubble(base_vector, i);
        i++;
    }
}


int main() {
    int vec_size;
    std::cin >> vec_size;
    std::vector<int> vec;
    vec.resize(vec_size);
    for (int i = 0; i < vec.size(); i++) {
        std::cin >> vec[i];
    }
    BubbleSort(vec);
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
}