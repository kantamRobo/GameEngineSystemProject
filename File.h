#pragma once
template <class T>
class File {
public:

	LinearAllocator<T> fileallocator;
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
		{
			std::ifstream ifs(file);

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

	void ReserveFileBuffer(const char* file)
	{
		std::ifstream instance(file);
		fileallocator<std::ifstream>.allocate(instance);
	}

	bool  RemoveDirectory(const LPCWSTR dirpath)
	{
		// �f�B���N�g�����폜����
		bool result = RemoveDirectory(dirName);
		if (!result)
		{
			// �f�B���N�g���̍폜�Ɏ��s�����ꍇ�̏���
			// �G���[���b�Z�[�W�̕\���Ȃ�
			return result;
		}

		return result;
	}
};
