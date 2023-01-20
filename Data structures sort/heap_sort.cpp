#include <iostream>
#include <vector>

void SiftDown(std::vector<int>& base_vector, int index, int length) {
	if (index * 2 + 1 >= length) {
		return;
	}
	if (index * 2 + 2 == length) {
		if (base_vector[index] < base_vector[index * 2 + 1]) {
			std::swap(base_vector[index], base_vector[index * 2 + 1]);
		}
		return;
	}
	if (base_vector[index * 2 + 1] > base_vector[index * 2 + 2]) {
		if (base_vector[index] >= base_vector[index * 2 + 1]) {
			return;
		}
		std::swap(base_vector[index], base_vector[index * 2 + 1]);
		SiftDown(base_vector, index * 2 + 1, length);
		return;
	}
	if (base_vector[index] >= base_vector[index * 2 + 2]) {
		return;
	}
	std::swap(base_vector[index], base_vector[index * 2 + 2]);
	SiftDown(base_vector, index * 2 + 2, length);
}

void MakeHeap(std::vector<int>& base_vector) {
	for (int i = base_vector.size() / 2 - 1; i >= 0; i--) {
		SiftDown(base_vector, i, base_vector.size());
	}
}

void HeapSort(std::vector<int>& base_vector) {
	MakeHeap(base_vector);
	for (int i = base_vector.size() - 1; i > 0; i--) {
		std::swap(base_vector[0], base_vector[i]);
		SiftDown(base_vector, 0, i);
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
	HeapSort(vec);
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
}