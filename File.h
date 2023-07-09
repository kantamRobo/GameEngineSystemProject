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
			throw std::runtime_error("ファイルを読み取れません");
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
				throw std::runtime_error("ファイルを読み取れません");
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
			MessageBox(NULL, errorMessage, L"ディレクトリの作成に失敗しました。", MB_ICONERROR | MB_OK);
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
		// ディレクトリを削除する
		bool result = RemoveDirectory(dirName);
		if (!result)
		{
			// ディレクトリの削除に失敗した場合の処理
			// エラーメッセージの表示など
			return result;
		}

		return result;
	}
};
