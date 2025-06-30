#include "FileRAII.hpp"

FileRAII::FileRAII(const std::string& filename, std::ios::openmode mode) {
    file_.open(filename, mode);
    if (!file_.is_open()) {
        throw std::runtime_error("�� ������� ������� ����: " + filename);
    }
}

FileRAII::~FileRAII() {
    if (file_.is_open()) {
        file_.close();
    }
}

std::string FileRAII::readLine() {
    if (!file_.is_open()) {
        throw std::runtime_error("���� �� ������ ��� ������.");
    }

    std::string line;
    if (std::getline(file_, line)) {
        return line;
    }

    if (file_.eof()) {
        return "";  // ��������� ���������� � ����� �����
    }
    else {
        throw std::runtime_error("������ ��� ������ �� �����.");
    }
}

void FileRAII::writeLine(const std::string& line) {
    if (!(file_ << line << '\n')) {
        throw std::runtime_error("������ ��� ������ ������");
    }
}

bool FileRAII::eof() const {
    return file_.eof();
}
