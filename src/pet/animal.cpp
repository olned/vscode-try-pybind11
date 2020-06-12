#include <pet/animal.hpp>


std::string call_go(Animal *animal) {
    return animal->go(3);
}
