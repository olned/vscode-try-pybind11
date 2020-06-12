#pragma once
#include <pet/dog.hpp>
#include <pybind11/pybind11.h>

class PyDog : public Dog {
public:
  using Dog::Dog; // Inherit the constructors

  std::string go(int n_times) override { PYBIND11_OVERLOAD(std::string, Dog, go, n_times); }
  std::string name() override { PYBIND11_OVERLOAD(std::string, Dog, name, ); }
  std::string bark() override { PYBIND11_OVERLOAD(std::string, Dog, bark, ); }
};

class PyHusky : public Husky {
public:
  using Husky::Husky; // Inherit constructors
  
  std::string go(int n_times) override { PYBIND11_OVERLOAD_PURE(std::string, Husky, go, n_times); }
  std::string name() override { PYBIND11_OVERLOAD(std::string, Husky, name, ); }
  std::string bark() override { PYBIND11_OVERLOAD(std::string, Husky, bark, ); }
};