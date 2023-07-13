#include "VirtualMemory.h"

#define MAPPED_FILE_NAME "Test File Mapping Object"
#define MUTEX_NAME "Test Mutex Object"

typedef struct {
	LONG cnt;
} SHARED_DATA;


auto VirtualMemory::MapFileView()
{
	BOOL bAlreadyExists; /* ���Ƀt�@�C���}�b�s���O�I�u�W�F�N�g���쐬����Ă��邩�ǂ�����\���^�U�l */
	auto hMap = CreateFileMapping(
		(HANDLE)0xffffffff,
		NULL,
		PAGE_READWRITE | SEC_COMMIT,
		0, sizeof(SHARED_DATA),
		MAPPED_FILE_NAME);
	/* ���ɍ쐬����Ă���? */
	bAlreadyExists = (GetLastError() == ERROR_ALREADY_EXISTS);

	auto pdata = MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(SHARED_DATA));

	return pdata;
}

void VirtualMemory::UnmapFileView(LPVOID Data)
{

	UnmapViewOfFile(Data);
}


