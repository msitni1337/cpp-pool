#pragma once
#include <fstream>
#include <iostream>


char* read_file(std::ifstream& input);
void file_replace(std::string content, std::ofstream& output, std::string& find, std::string& replace);