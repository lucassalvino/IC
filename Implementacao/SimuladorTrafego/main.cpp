#include <iostream>
#include <stdlib.h>
#include "Xdata.h"
#include "myLibraries/BasisForDeveloping/config.h"
using namespace BaseDeveloping;

int main(int argc, char *argv[])
{
    Config::setPatchFile("teste\n");
    printf("%s", Config::getPathFile().c_str());
    return 0;
}
