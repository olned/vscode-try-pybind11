#pragma once
#include <pet/animal.hpp>
#include <pybind11/pybind11.h>

class PyAnimal : public Animal {
public:
  /* Inherit the constructors */
  using Animal::Animal;

  /* Trampoline (need one for each virtual function) */
  std::string go(int n_times) override
  {
    PYBIND11_OVERLOAD_PURE(
        std::string, /* Return type */
        Animal,      /* Parent class */
        go,          /* Name of function in C++ (must match Python name) */
        n_times      /* Argument(s) */
    );
  }

  std::string name() override
  {
    PYBIND11_OVERLOAD(std::string, Animal, name, );
  }
};
