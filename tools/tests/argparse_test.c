#include <stdlib.h>
#include "tools/argparse.h"
#include "util/minunit.h"

mu_test(no_args){
    int argc = 0;
    char **argv = NULL;

    ArgList* al = ArgList_make(argc, argv);
    mu_assert(al, "Something is wrong with making an arglist");
    mu_assert(al->length == 0, "Arglist aquired something.");  
    return NULL;
}

mu_suite(argparse_suite){
    mu_run_test(no_args);
    return NULL;
}
