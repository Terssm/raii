#pragma once
#include <fstream>
#include <string>
#include <stdexcept>

class FileRAII {
public:
    FileRAII(const std::string& filename, std::ios::openmode mode);
    ~FileRAII();

    std::string readLine();
    void writeLine(const std::string& line);
    bool eof() const;

private:
    std::fstream file_;
};
