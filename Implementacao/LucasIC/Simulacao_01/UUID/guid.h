#ifndef GUID_H
#define GUID_H
#include <uuid/uuid.h> //apt-get install uuid-dev
/*
-> instalar biblioteca para guid (linux)  apt-get install uuid-dev
-> adicionar flag LIBS += -luuid ao .PRO do projeto (qtCreator)
-> informações em: http://graemehill.ca/minimalist-cross-platform-uuid-guid-generation-in-c++/
*/
#include <iostream>
using namespace std;
class Guid{
public:
    static string newGuid(){
        uuid_t id;
        uuid_generate(id);
        char *str = new char[37];
        uuid_unparse(id, str);
        for(int i=0;str[i];i++)
            str[i] = toupper(str[i]);
        return string(str);
    }
};
#endif // GUID_H
