#include <pybind11/pybind11.h>
#include <arithmetic.hpp>
#include "py_animal.hpp"
#include "py_dog.hpp"

namespace py = pybind11;

PYBIND11_MODULE(try_pybind11_olned, m)
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

    py::class_<Animal, PyAnimal /* <--- trampoline*/>(m, "Animal")
        .def(py::init<>())
        .def("go", &Animal::go)
        .def("name", &Animal::name);

    py::class_<Dog, PyDog, Animal>(m, "Dog")
        .def(py::init<>())
        .def("go", &Dog::go)
        .def("name", &Dog::name)
        .def("bark", &Dog::bark);

    m.def("call_go", &call_go);
    m.def("get_name", &get_name);

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
