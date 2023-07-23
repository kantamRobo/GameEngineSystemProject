#pragma once
#include <istream>
#include <fstream>
#include <string>
#include <map>

struct FileInstance {
	std::ifstream file;

	std::string path;
};
class FilePool {
public:

	LinearAllocator<FileInstance> pool;

	void Reserve(std::vector<FileInstance>& fileinstances)
	{
		for (auto& instance : fileinstances)
		{
			pool.allocate(instance);
		}

	}

	bool Open(const std::string& in_path)
	{
		//todo �񕪒T���ɂ���
		for (int i = 0; i < pool.allocator.size(); i++)
		{
			if (pool.allocator[i].path == in_path)
			{
				pool.allocator[i].file.open(in_path);
				break;
			}
			else {
				throw std::runtime_error("�t�@�C����ǂݎ��܂���");
			}

		}


		return true;
	}

	bool Close(const std::string& in_path)
	{
		{
			auto find = std::lower_bound(pool.allocator.begin(), pool.allocator.end(), in_path);
				
			auto file = std::distance(pool.allocator.begin(), find);

			}
		}
		return true;
	}
	bool CreateDirectory(const LPCWSTR dirpath)
	{
		bool result = CreateDirectory(dirpath, NULL);

		if (!result)
		{
			MessageBox(NULL, errorMessage, L"�f�B���N�g���̍쐬�Ɏ��s���܂����B", MB_ICONERROR | MB_OK);
			return result;
		}
		return result;
	}


	bool  RemoveDirectory(const LPCWSTR dirpath)
	{
		// �f�B���N�g�����폜����
		bool result = RemoveDirectory(dirpath);
		if (!result)
		{
			// �f�B���N�g���̍폜�Ɏ��s�����ꍇ�̏���
			// �G���[���b�Z�[�W�̕\���Ȃ�
			return result;
		}

		return result;
	}
};

