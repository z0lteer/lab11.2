#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

void capitalizeAfterDot(std::string& s) {
    size_t pos = 0;

    while ((pos = s.find('.', pos)) != std::string::npos) {
        pos++;
        while (pos < s.length() && isspace(s[pos])) {
            pos++;
        }
        if (pos < s.length() && isalpha(s[pos])) {
            s[pos] = toupper(s[pos]);
        }
    }
}

std::string readFile(const std::string& fileName) {
    std::ifstream inputFileStream(fileName);

    std::string content((std::istreambuf_iterator<char>(inputFileStream)),
        std::istreambuf_iterator<char>());
    return content;
}

void writeFile(const std::string& fileName, const std::string& content) {
    std::ofstream outputFileStream(fileName, std::ios::out);

    outputFileStream << content;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const std::string inputFileName = "t1.txt";
    const std::string outputFileName = "t2.txt";

    std::string fileContent = readFile(inputFileName);

    std::cout << "Оригінальний текст:\n" << fileContent << "\n";

    capitalizeAfterDot(fileContent);

    writeFile(outputFileName, fileContent);

    std::cout << "Текст оброблено та записано у файл: " << outputFileName << "\n";

    return 0;
}