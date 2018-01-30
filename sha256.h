#pragma once

#include <string>

using namespace std;

string sha256(const string& s);
const char* hex_char_to_bin(char c);
std::string hex_str_to_bin_str(const std::string& hex);
