#include "FileRAII.hpp"

FileRAII::FileRAII(const std::string& filename, std::ios::openmode mode) {
    file_.open(filename, mode);
    if (!file_.is_open()) {
        throw std::runtime_error("Не удалось открыть файл: " + filename);
    }
}

FileRAII::~FileRAII() {
    if (file_.is_open()) {
        file_.close();
    }
}

std::string FileRAII::readLine() {
    if (!file_.is_open()) {
        throw std::runtime_error("Файл не открыт для чтения.");
    }

    std::string line;
    if (std::getline(file_, line)) {
        return line;
    }

    if (file_.eof()) {
        return "";  // Спокойное завершение — конец файла
    }
    else {
        throw std::runtime_error("Ошибка при чтении из файла.");
    }
}

void FileRAII::writeLine(const std::string& line) {
    if (!(file_ << line << '\n')) {
        throw std::runtime_error("Ошибка при записи строки");
    }
}

bool FileRAII::eof() const {
    return file_.eof();
}
