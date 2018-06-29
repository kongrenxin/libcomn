#define MODULE "MAIN"
#include "utils.h"

int main(int argc, char **argv)
{
    comnlibs::GlobalInit();
    comnlibs::timer tr(2000, true);
    tr.start2(0, 0);
    return 0;
}