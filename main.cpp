#include "functions.h"

int main() {
    std::cout << "Programa pradeda darba!" << std::endl;

    // Start timer
    auto TimerStart = std::chrono::high_resolution_clock::now();

    std::ofstream OutputFile("output.txt"); // Open output file for words
    std::ofstream OutputUrl("url.txt"); // Open output file for URLs

    Words();

    // Print repetitive words, their count, and references to the lines they appear on
    OutputFile << "Words:\n";
    for (const auto &entry : word_map) {
        if (entry.second.first > 1) { // Only consider words that appear more than once
            OutputFile << entry.first << ": " << entry.second.first << " [lines: ";
            for (const int &ln : entry.second.second) {
                OutputFile << ln << " "; // Print line numbers
            }
            OutputFile << "]" << std::endl;
        }
    }

    // Print the URLs and their count to url.txt
    OutputUrl << "\nURLs:\n";
    for (const auto &entry : url_map) {
        OutputUrl << entry.first << std::endl; // Print URL
    }

    OutputUrl.close(); // Close the URL output file
    OutputFile.close(); // Close the words output file

    std::cout << "Programa baige darba!" << std::endl;
    std::cout << "Pasikartojantys zodziai - text.txt faile" << std::endl;
    std::cout << "URLs - url.txt faile" << std::endl;

    // End timer and calculate elapsed time
    auto TimerEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> TimerElapsed = TimerEnd - TimerStart;
    std::cout << "Programa dirbo: " << TimerElapsed.count() << " s" << std::endl; // Print elapsed time

    return 0;
}
