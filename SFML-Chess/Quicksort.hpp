#include <vector>

#include <SFML/Graphics.hpp>

class Quicksort 
{
	public:
		static std::vector<int> values;
		static int partition(std::vector<int>& values, int left, int right);
		static void sort(std::vector<int>& values, int left, int right, int& accesses);
};