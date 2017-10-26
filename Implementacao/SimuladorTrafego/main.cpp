#include <iostream>
#include <stdlib.h>

#include <config.h> /*from https://github.com/lucassalvino/BasisForDeveloping */
#include "Xdata.h"

int main(int argc, char *argv[])
{
    Config::setPatchFile("teste\n");
    printf("%s", Config::getPathFile().c_str());
    return 0;
}
