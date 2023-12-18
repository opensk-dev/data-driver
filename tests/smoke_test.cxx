#include <iostream>
#include <opensk/data/driver.hpp>

int main() {
    std::cout << "sk data version: " << sk::data::version_string() << '\n';
    return 0;
}