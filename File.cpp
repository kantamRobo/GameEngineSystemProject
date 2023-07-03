#include "File.h"
#include <fstream>
#include <istream>
#include <stdexcept>
bool Open(const char* filepath)
{
	std::ifstream ifs(filepath);

	if (ifs)
	{
		ifs.open(filepath);
		return true;
	}
	else
	{
		throw std::runtime_error("�t�@�C����ǂݎ��܂���");
		return false;
	}
	return true;
}

bool Close(const char* filepath)
{
	std::ifstream ifs(filepath);

	if (ifs)
	{
		ifs.close();
		return true;
	}
	else
	{
		throw std::runtime_error("�t�@�C����ǂݎ��܂���");
		return false;
	}
	return true;
}
