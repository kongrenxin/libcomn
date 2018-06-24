#include "utils.h"

int main(int argc, char **argv)
{
    comnlibs::timer tr(3000, true);
    tr.start(0, 0);
    return 0;
}