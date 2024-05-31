#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <map>
#include <set>
#include <regex>

// Declare the maps globally so they can be used in main.cpp
extern std::map<std::string, std::pair<int, std::set<int>>> word_map;
extern std::map<std::string, std::pair<int, std::set<int>>> url_map;

std::string Filter(const std::string &word);
bool isURL(const std::string &word);
void Words();

#endif // FUNCTIONS_H
