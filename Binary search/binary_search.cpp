#include <iostream>
#include <vector>

int LeftBinarySearch(std::vector<int>& base_vector, int x) {
	if (base_vector.size() == 0) {
		return -1;
	}
	int left = -1;
	int right = base_vector.size();
	while (right - left > 1) {
		if (base_vector[(left + right) / 2] < x) {
			left = (left + right) / 2;
		}
		else {
			right = (left + right) / 2;
		}
	}
	if (base_vector[right] == x) {
		return right;
	}
	return -1;
}

int RightBinarySearch(std::vector<int>& base_vector, int x) {
	if (base_vector.size() == 0) {
		return -1;
	}
	int left = -1;
	int right = base_vector.size();
	while (right - left > 1) {
		if (base_vector[(left + right) / 2] > x) {
			right = (left + right) / 2;
		}
		else {
			left = (left + right) / 2;
		}
	}
	if (base_vector[left] == x) {
		return left;
	}
	return -1;
}

int main() {
	int vec_size;
	int x;
	std::cin >> vec_size;
	std::vector<int> vec;
	vec.resize(vec_size);
	for (int i = 0; i < vec.size(); i++) {
		std::cin >> vec[i];
	}
	std::cin >> x;
	std::cout << LeftBinarySearch(vec, x) << "\n";
	std::cout << RightBinarySearch(vec, x);
	
}