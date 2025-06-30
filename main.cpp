#include <iostream>
#include <clocale>
#include <string>
#include "FileRAII.hpp"

int main() {
    std::setlocale(LC_ALL, "Russian_Russia.1251");

    try {
        std::string path;
        std::cout << "������� ������ ���� � �����: ";
        std::getline(std::cin, path);

        FileRAII file(path, std::ios::in);
        std::cout << "\n���������� �����:\n";

        while (true) {
            std::string line = file.readLine();

            if (line.empty()) {
                if (file.eof()) {
                    std::cout << "[����� �����]\n";
                    break;
                }
            }
            else {
                std::cout << line << '\n';
            }
        }

    }
    catch (const std::exception& e) {
        std::cerr << "������: " << e.what() << '\n';
    }

    return 0;
}
