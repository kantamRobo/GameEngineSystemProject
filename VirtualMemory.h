#pragma once
#include <Windows.h>
class VirtualMemory
{
	auto MapFileView();
	void UnmapFileView(LPVOID Data);
};

