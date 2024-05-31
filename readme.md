# Specs

    CPU: AMD Ryzen 5 5600U with Radeon Graphics 2.30 GHz
    RAM: 16.0 GB (15.3 GB usable)
    SSD: WDC PC SN530 512Gb
    GPU: Integrated with CPU
    OS: Windows 10 Pro 64-bit

## Project Description

This project is a simple word and URL frequency analyzer. It reads a text file (`text.txt`), filters out punctuation, identifies URLs, and counts the frequency of each word and URL. The results are then saved to two output files: `output.txt` for words and `url.txt` for URLs.

## Files

- `main.cpp`: The main file that initiates the program, calls the `Words` function, and handles the output of results.
- `functions.h`: Header file that declares functions and global maps used in the project.
- `functions.cpp`: Implementation file defines the functions and global maps.

## functions

### Filter

`std::string Filter(const std::string &word); `
Filters punctuation from a word, except for '.', '/', and ':'.

### isURL

`bool isURL(const std::string &word);` Checks if a word matches the URL pattern using a regular expression.

### Words

`Void Words();` Reads the input file `text.txt`, filters words, identifies URLs, and populates the global maps `word_map` and `url_map`.

## Global Variables

- `std::map<std::string, std::pair<int, std::set<int>>> word_map;` Stores words, their counts, and the line numbers where they appear.
- `std::map<std::string, std::pair<int, std::set<int>>> url_map;` Stores URLs, their counts, and the line numbers where they appear.
