#include "functions.h"

// Define the global maps
std::map<std::string, std::pair<int, std::set<int>>> word_map; // Map to store words, their counts, and the line numbers where they appear
std::map<std::string, std::pair<int, std::set<int>>> url_map;  // Map to store URLs, their counts, and the line numbers where they appear

// Function to filter punctuation from a word, except for '.', '/', and ':'
std::string Filter(const std::string &word) {
    std::string filtered_word;
    for (char ch : word) {
        if (!std::ispunct(ch) || ch == '.' || ch == '/' || ch == ':') {
            filtered_word += ch; // Append character if it's not punctuation or if it's '.', '/', or ':'
        }
    }
    return filtered_word; // Return the filtered word
}

// Function to check if a word is a URL using a regular expression
bool isURL(const std::string &word) {
    const std::regex url_pattern(R"((http://|https://|www\.|[a-zA-Z0-9.-]+\.(com|org|net|edu|gov|io|co|lt)))"); // Regular expression for URLs
    return std::regex_search(word, url_pattern); // Return true if the word matches the URL pattern
}

// Function to read words from a file and categorize them into word_map and url_map
void Words() {
    std::ifstream InputFile("text.txt");
    if (!InputFile) {
        std::cerr << "Unable to open file" << std::endl; // Print error message if file can't be opened
        exit(EXIT_FAILURE); // Exit the program
    }

    std::string line;
    int line_number = 0; // Initialize line number

    // Read the file line by line
    while (std::getline(InputFile, line)) {
        ++line_number; // Increment line number
        std::istringstream iss(line); // Create a string stream from the line
        std::string word;

        // Read each word in the line
        while (iss >> word) {
            std::string filtered_word = Filter(word); // Filter the word
            if (!filtered_word.empty()) { // Check if the filtered word is not empty
                if (isURL(filtered_word)) { // Check if the word is a URL
                    url_map[filtered_word].first++; // Increment the URL count
                    url_map[filtered_word].second.insert(line_number); // Add the line number to the set
                } else {
                    word_map[filtered_word].first++; // Increment the word count
                    word_map[filtered_word].second.insert(line_number); // Add the line number to the set
                }
            }
        }
    }
    InputFile.close(); 
}
