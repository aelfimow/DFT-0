#ifdef FILE_READER_H
#error Already included
#else
#define FILE_READER_H

class FileReader
{
    public:
        FileReader(const TCHAR *pName);
        ~FileReader();

    private:
        const HANDLE m_hFile;

    public:
        FileReader() = delete;
        FileReader(const FileReader &instance) = delete;
        FileReader(const FileReader &&instance) = delete;
        FileReader &operator=(const FileReader &instance) = delete;
        FileReader &operator=(const FileReader &&instance) = delete;
};

#endif
