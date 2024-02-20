#include<iostream>
#include<string>
#include<vector>
#include<array>
#include "../include/Log.h"
class Entity {
public:
	Entity(int a = 2, float b = 8.83f, std::string c = "hello") :i{ a }, f{ b }, s{ c } {
		logger.Info("Default Constructor");
	};
	Entity(const Entity& e) {
		logger.Warn("Copy Constructor");
		i = e.i;
		f = e.f;
		s = e.s;
	}
	Entity(Entity&& e) noexcept{
		logger.Error("Move Constructor");
		(*this) = std::move(e);
	}
	Entity& operator=(const Entity& e) {
		logger.Warn("Copy Assignment");
		i = e.i;
		f = e.f;
		s = e.s;
		return *this;
	}
	Entity& operator=(Entity&& e) noexcept{
		logger.Error("Move Assignment");
		i = e.i;
		f = e.f;
		s = e.s;
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& stream, const Entity& e);
private:
	int i;
	float f;
	std::string s;
	Lognspace::Log logger;
};

std::ostream& operator<<(std::ostream& stream, const Entity& e) {
	stream << e.i << " " << e.f << " " << e.s << "\n";
	return stream;
}
//int main() {
//	std::vector<Entity> v;
//	v.push_back(Entity{23,45.87f, "hello" });
//	Entity e1 = {3, 56.74, "hell yeas"};
//	Entity e2{ e1 };
//	std::cout << e2;
//}