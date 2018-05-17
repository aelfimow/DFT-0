#ifdef DFT_FILE_H
#error Already included
#else
#define DFT_FILE_H

class FileReader;

class DFT_File
{
    public:
        ~DFT_File();

    public:
        static void Create(FileReader *pFileReader);
        static void Destroy();

    private:
        static DFT_File *Inst;

        FileReader * const m_FileReader;

        explicit DFT_File(FileReader *pFileReader);

    public:
        DFT_File() = delete;
        DFT_File(const DFT_File &instance) = delete;
        DFT_File(const DFT_File &&instance) = delete;
        DFT_File &operator=(const DFT_File &instance) = delete;
        DFT_File &operator=(const DFT_File &&instance) = delete;
};

#endif
