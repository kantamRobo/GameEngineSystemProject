#include <stdexcept>
#include "File.h"
#include "Memory.h"
#include <fstream>
#include <istream>

bool File::Open(const char* filepath)
{
	std::ifstream ifs(filepath);

	if (ifs)
	{
		ifs.open(filepath);
		return true;
	}
	else
	{
		throw std::runtime_error("ファイルを読み取れません");
		return false;
	}
	return true;
}

bool File::Close(const char* file)
{
	std::ifstream ifs(file);

	if (ifs)
	{
		ifs.close();
		return true;
	}
	else
	{
		throw std::runtime_error("ファイルを読み取れません");
		return false;
	}
	return true;
}
