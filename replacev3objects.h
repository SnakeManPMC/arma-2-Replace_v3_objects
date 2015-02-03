#ifndef REPLACEV3OBJECTS_H
#define REPLACEV3OBJECTS_H
#include <QFile>

class replaceV3Objects
{
public:
    replaceV3Objects(int argc, char *argv[]);
    void DoTime();
    void Open_Files(int argc, char *argv[]);
    void Read_Lines();
    void Close_Files();

private:
    QFile file;
    QFile file2;
};

#endif // REPLACEV3OBJECTS_H
