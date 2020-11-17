#pragma once

#include <string>

typedef unsigned int uint;
typedef unsigned short ushort;
typedef char byte;
typedef unsigned char uchar;
typedef unsigned long ulong;

class Utils
{
public:
	std::string ReadFile(const char* fileFullPath);
};
