#include <vector>

class Engine {
	public:
		int w;
		int h;
		std::vector<int> arr;
		Engine(int w, int h);
		void start();
};