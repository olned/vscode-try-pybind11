#pragma once
#include <pet/animal.hpp>
#include <pybind11/pybind11.h>

template <class AnimalBase = Animal>
class PyAnimal : public AnimalBase {
public:
  using AnimalBase::AnimalBase; // Inherit constructors
  std::string go(int n_times) override { PYBIND11_OVERLOAD_PURE(std::string, AnimalBase, go, n_times); }
  std::string name() override { PYBIND11_OVERLOAD(std::string, AnimalBase, name, ); }
};
