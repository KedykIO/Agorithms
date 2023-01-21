#include <iostream>
#include <vector>

int FindMinimum(std::vector<int>& base_vector) {
	int min = INT_MAX;
	for (int i = 0; i < base_vector.size(); i++) {
		if (base_vector[i] < min) {
			min = base_vector[i];
		}
	}
	return min;
}

int FindMaximum(std::vector<int>& base_vector) {
	int max = INT_MIN;
	for (int i = 0; i < base_vector.size(); i++) {
		if (base_vector[i] > max) {
			max = base_vector[i];
		}
	}
	return max;
}

void CountingSort(std::vector<int>& base_vector) {
	if (base_vector.size() < 1) {
		return;
	}
	std::vector<int> sorted_vector;
	sorted_vector.resize(base_vector.size());

	int padding = FindMinimum(base_vector);
	int max = FindMaximum(base_vector);

	std::vector<int> count_vector;
	count_vector.resize(max - padding + 1);
	for (int i = 0; i < base_vector.size(); i++) {
		count_vector[base_vector[i] - padding]++;
	}
	int index = 0;
	for (int i = 0; i < count_vector.size(); i++) {
		int tmp = count_vector[i];
		count_vector[i] = index;
		index = count_vector[i] + tmp;
	}
	for (int i = 0; i < sorted_vector.size(); i++) {
		sorted_vector[count_vector[base_vector[i] - padding]] = base_vector[i];
		count_vector[base_vector[i] - padding]++;
	}
	base_vector = sorted_vector;
}


int main() {
	int vec_size;
	std::cin >> vec_size;
	std::vector<int> vec;
	vec.resize(vec_size);
	for (int i = 0; i < vec.size(); i++) {
		std::cin >> vec[i];
	}
	CountingSort(vec);
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
}