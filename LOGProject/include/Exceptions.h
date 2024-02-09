#include<iostream>
namespace Exception {
	class Overflow : public std::runtime_error {
	public:
		Overflow() : std::runtime_error("") {}
		const char* what() const noexcept { return "OVERFLOW! Size provided is not valid.\n"; }

	};
	class IndexOutOfBounds : public std::runtime_error {
	public:
		IndexOutOfBounds() : std::runtime_error("") {}
		const char* what() const noexcept { return "Index Out Of Bounds! The index is either less than 0 or greater than the size.\n"; }
	};
}
