#include<iostream>
#include<string>
#include<vector>
#include<array>
#include "../include/log.h";
class Entity {

public:
    // Entity(){
    //     std::cout << "Empty Constructor\n";
    // };
    Entity(std::string st = "Hello there", int it = 9, float ft = 45.23f) :s{ st }, i{ it }, f{ ft } {
        logger.Info("Parameterized Constructor");
    }
    Entity(const Entity& e) {
        logger.Info("Copy Constructor\n");
        s = e.s;
        i = e.i;
        f = e.f;
    }
    Entity(Entity&& e) {
        std::cout << "Move Constructor\n";
        s = e.s;
        i = e.i;
        f = e.f;
    }
    Entity& operator=(const Entity& e) {
        logger.Info("Copy Assignment\n");
        s = e.s;
        i = e.i;
        f = e.f;
        return *this;

    }
    Entity& operator=(Entity&& e) {
        logger.Info("Move Assignment\n");
        s = e.s;
        i = e.i;
        f = e.f;
        return *this;
    }
    ~Entity() {
        logger.Info("Copy Assignment\n");
    }
    friend std::ostream& operator<<(std::ostream& stream, const Entity& e);
private:
    std::string s;
    int i;
    float f;
    Lognspace::Log logger;
};
std::ostream& operator<<(std::ostream& stream, const Entity& e) {
    // std::cout << "hell here";
    stream << e.s << " " << e.i << " " << e.f << "\n";
    return stream;
}