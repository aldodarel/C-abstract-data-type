#include <stdio.h>
#include <string.h>
#include "opname.h"

int main() {
    OPNAME opname;

    BacaOPNAME(&opname);
    TulisOPNAME(&opname);

    return 0;

}