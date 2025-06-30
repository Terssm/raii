#include <iostream>
#include <clocale>
#include <string>
#include "FileRAII.hpp"

int main() {
    std::setlocale(LC_ALL, "Russian_Russia.1251");

    try {
        std::string path;
        std::cout << "Введите полный путь к файлу: ";
        std::getline(std::cin, path);

        FileRAII file(path, std::ios::in);
        std::cout << "\nСодержимое файла:\n";

        while (true) {
            std::string line = file.readLine();

            if (line.empty()) {
                if (file.eof()) {
                    std::cout << "[Конец файла]\n";
                    break;
                }
            }
            else {
                std::cout << line << '\n';
            }
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << '\n';
    }

    return 0;
}
