#include "functions.h"

int main() {
    std::ofstream OutputFile("output.txt");
    std::ofstream OutputUrl("url.txt");

    Words();

    // Print repetitive words/count/reference to text.txt
    OutputFile << "Words:\n";
    for (const auto &entry : word_map) {
        if(entry.second.first > 1) {
            OutputFile << entry.first << ": " << entry.second.first << " [lines: ";
            for (const int &ln : entry.second.second) {
                OutputFile << ln << " ";
            }
            OutputFile << "]" << std::endl;
        }
    }

    // Print the URLs and their count to url.txt
    OutputUrl << "\nURLs:\n";
    for (const auto &entry : url_map) {
        OutputUrl << entry.first << std::endl;
    }

    OutputUrl.close();
    OutputFile.close();

    return 0;
}
