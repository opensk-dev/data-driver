# include <opensk/data/driver.hpp>
# include <iostream>

int main() {
    std::cout << "opensk data version: " << sk_data_version_string() << '\n';
    return 0;
}