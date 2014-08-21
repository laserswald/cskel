
#include "speedunit.h"

sp_test(passing_test){
    sp_assert(true == true, "Holy SHIT");
    return NULL;
}

sp_test(failing_test){
    sp_assert(true == false, "This test should be false.");
    return NULL;
}

sp_test(second_failing){
    sp_assert(true == false, "This is the second false test.");
    return NULL;
}

sp_suite(speedunit_demo){
    sp_run_test(passing_test);
    //sp_run_test(failing_test);
    //sp_run_test(second_failing);
    return NULL;
}

