//
// Created by asuka on 15.05.2023.
//

# include <filesystem>
# include <fstream>
# include <iostream>

int main() {
    std::filesystem::path filepath = "./data/Skyrim.esm";
    auto file = std::ifstream(filepath, std::ios::binary);
    unsigned int k = 0, value;
    char* bytes = reinterpret_cast<char*>(&value);
    while (file && k < 1000) {
        file.read(bytes, 4);
        std::cout << value << " | ";
        for (int i = 0; i < 4; ++i) {
            std::cout << static_cast<unsigned int>(bytes[i]) << ' ';
        }
        std::cout << "| ";
        for (int i = 0; i < 4; ++i) {
            std::cout << bytes[i];
        }
        std::cout << '\n';
        ++k;
    }
    std::cout << "total rows count: " << k << '\n';
    std::cout << "total bytes count: " << k * 4 << '\n';
    return 0;
}