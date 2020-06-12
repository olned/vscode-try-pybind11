#include "py_animal.hpp"
#include "py_dog.hpp"
#include <arithmetic.hpp>
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(example, m)
{
  m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------
        .. currentmodule:: try_pypind11_olned
        .. autosummary::
           :toctree: _generate
           add
           subtract
    )pbdoc";

  m.def("add", &add, R"pbdoc(
        Add two numbers
        Some other explanation about the add function.
    )pbdoc");

  m.def(
      "subtract", [](int i, int j) { return i - j; }, R"pbdoc(
        Subtract two numbers
        Some other explanation about the subtract function.
    )pbdoc");

  py::class_<Animal, PyAnimal<>> animal(m, "Animal");
  py::class_<Dog, PyDog<>, Animal> dog(m, "Dog");
  py::class_<Husky, PyDog<Husky>, Dog> husky(m, "Husky");

  animal.def(py::init<>())
      .def("go", &Animal::go)
      .def("name", &Animal::name);

  dog.def(py::init<>())
      .def("go", &Dog::go)
      .def("name", &Dog::name)
      .def("bark", &Dog::bark);

  husky.def(py::init<>())
      .def("go", &Husky::go)
      .def("name", &Husky::name)
      .def("bark", &Husky::bark);

  m.def("call_go", &call_go);
  m.def("get_name", &get_name);

#ifdef VERSION_INFO
  m.attr("__version__") = VERSION_INFO;
#else
  m.attr("__version__") = "dev";
#endif
}
