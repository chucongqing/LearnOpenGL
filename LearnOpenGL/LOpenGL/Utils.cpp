#include "utils.h"
#include <filesystem>
#include <iostream>
#include <fstream>

using namespace std;

std::string Utils::ReadFile(const char* fileFullPath) {
	filesystem::path p(fileFullPath);
	if (!exists(p)) {
		throw string("file not exists");
	}
	ifstream ifs(fileFullPath);

	ifs.close();
}
