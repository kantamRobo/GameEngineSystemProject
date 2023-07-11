#pragma once
#include <Windows.h>
class MemoryMap
{
	auto MapFileView();
	void UnmapFileView(LPVOID Data);
};

