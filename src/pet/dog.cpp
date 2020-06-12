#include <pet/dog.hpp>

std::string Dog::go(int n_times)
{
    std::string result;
    for (int i = 0; i < n_times; ++i)
        result += "woof! ";
    return result;
}
