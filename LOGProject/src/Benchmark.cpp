#include<string>
#include<iostream>
#include<chrono>
class Timer {
public:
	Timer() :m_startTimePoint{ std::chrono::high_resolution_clock::now() } {

	}
	~Timer() {
		auto m_endTimePoint{ std::chrono::high_resolution_clock::now() };
		auto start = std::chrono::time_point_cast<std::chrono::milliseconds>(m_startTimePoint).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::milliseconds>(m_endTimePoint).time_since_epoch().count();
		auto duration = end - start;
		//auto mi = duration * .001;
		std::cout << duration << "Milliseconds(" << duration << "Millisecond)\n";
	}
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_startTimePoint;

};
int main() {
	Timer t;
	auto value{ 0 };

	{
		for (auto i{ 0 }; i < 1000000; ++i) {
			value += 1;
		}
	}
	std::cout << value << std::endl;
}