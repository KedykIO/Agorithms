#include<iostream>
#include<vector>


void Insertion(std::vector<int>& base_vector, int ind) {
	int j = ind - 1;
    while ((j >= 0) && (base_vector[ind] < base_vector[j])) {
        j--;
    }
    if (j == -1) {
        base_vector.insert(base_vector.begin(), base_vector[ind]);
    }
    else {
        base_vector.insert(base_vector.begin() + j + 1, base_vector[ind]);
    }
    base_vector.erase(base_vector.begin() + ind + 1);
}

void InsertSort(std::vector<int>& base_vector) {
	for (int i = 1; i < base_vector.size(); i++) {
        Insertion(base_vector, i);
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
	InsertSort(vec);
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
}