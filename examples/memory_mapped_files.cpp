//
// Created by asuka on 26.05.2023.
//

#include <boost/interprocess/file_mapping.hpp>
#include <boost/interprocess/mapped_region.hpp>

#include <iostream>

int main() {
    auto mode = boost::interprocess::read_only;
    boost::interprocess::file_mapping mapping("./data/Skyrim.esm", mode);
    boost::interprocess::mapped_region region(mapping, mode);
    auto data = reinterpret_cast<const char*>(region.get_address());
    int index = 0;
    while (index < region.get_size()) {
        for (int i = 0; i < 4; ++i) {
            std::cout << data[index + i] << ' ';
        }
        std::cout << '\n';
        index += 4;
    }
    return 0;
}