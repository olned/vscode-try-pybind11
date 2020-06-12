#pragma once
#include <pet/dog.hpp>
#include <pybind11/pybind11.h>

template <class DogBase = Dog> class PyDog : public PyAnimal<DogBase> {
public:
    using PyAnimal<DogBase>::PyAnimal; // Inherit constructors
    // Override PyAnimal's pure virtual go() with a non-pure one:
    
    std::string go(int n_times) override { PYBIND11_OVERLOAD(std::string, DogBase, go, n_times); }
    std::string bark() override { PYBIND11_OVERLOAD(std::string, DogBase, bark, ); }
};