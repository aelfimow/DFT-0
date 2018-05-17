#ifdef FILE_READER_H
#error Already included
#else
#define FILE_READER_H

class FileReader
{
    public:
        explicit FileReader(const TCHAR *pName);
        ~FileReader();

        std::vector<uint8_t> read(size_t maxBytes);

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
