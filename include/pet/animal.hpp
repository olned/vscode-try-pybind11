#pragma once
#include <string>

class Animal {
public:
    virtual ~Animal() { }
    virtual std::string go(int n_times) = 0;
};

std::string call_go(Animal *animal);
