#include "functions.h"

// Define the global maps
std::map<std::string, std::pair<int, std::set<int>>> word_map;
std::map<std::string, std::pair<int, std::set<int>>> url_map;

std::string Filter(const std::string &word) {
    std::string filtered_word;
    for (char ch : word) {
        if (!std::ispunct(ch) || ch == '.' || ch == '/' || ch == ':') {
            filtered_word += ch;
        }
    }
    return filtered_word;
}

bool isURL(const std::string &word) {
    const std::regex url_pattern(R"((http://|https://|www\.|[a-zA-Z0-9.-]+\.(com|org|net|edu|gov|io|co|lt)))");
    return std::regex_search(word, url_pattern);
}

void Words()
{
    std::ifstream InputFile("text.txt");
    if (!InputFile) {
        std::cerr << "Unable to open file" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string line;
    int line_number = 0;

    while (std::getline(InputFile, line)) {
        ++line_number;
        std::istringstream iss(line);
        std::string word;

        while (iss >> word) {
            std::string filtered_word = Filter(word);
            if (!filtered_word.empty()) {
                if (isURL(filtered_word)) {
                    url_map[filtered_word].first++;
                    url_map[filtered_word].second.insert(line_number);
                } else {
                    word_map[filtered_word].first++;
                    word_map[filtered_word].second.insert(line_number);
                }
            }
        }
    }
    InputFile.close();
}
