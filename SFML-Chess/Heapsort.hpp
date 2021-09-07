#include <vector>

class Heapsort {
public:
	static void max_heapify(std::vector<int>& arr, int i, int size_, int& accesses);
	static void build_max_heap(std::vector<int>& arr, int& accesses);
	static void sort(std::vector<int>& arr, int& accesses);
};