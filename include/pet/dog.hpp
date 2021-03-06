#pragma once
#include "animal.hpp"

class Dog : public Animal
{
public:
    std::string go(int n_times) override;
    virtual std::string bark();
};

class Husky : public Dog
{
};