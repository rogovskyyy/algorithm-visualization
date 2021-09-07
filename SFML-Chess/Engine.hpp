#include <vector>

class Engine {
	public:
		int w, h, a, i, t;
		std::vector<int> arr;
		Engine(int width, int height, int algorithm, int items, int inputType);
		void start();
};
