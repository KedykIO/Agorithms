#include<iostream>
#include<vector>

int* MinNumber(std::vector<int>& base_vector, int start_index) {
	int min = base_vector[start_index];
	int min_index = start_index;
	for (int i = start_index; i < base_vector.size(); i++) {
		if (base_vector[i] < min) {
			min = base_vector[i];
			min_index = i;
		}
	}
	return &base_vector[min_index];
}

void MinSort(std::vector<int>& base_vector) {
	for (int i = 0; i < base_vector.size(); i++) {
		std::swap(base_vector[i], *MinNumber(base_vector, i));
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
	MinSort(vec);
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
}