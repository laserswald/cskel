/* file: minunit.h */
#include <stdlib.h>
#include <stdio.h>
#define mu_test(name) static char* name()
#define mu_suite(name) static char* name()
#define mu_failmsg(message) do { char* msg = malloc(255); snprintf(msg, 255, "fail (%s:%d): %s\n", __FILE__, __LINE__, message); return msg; } while (0)

#define mu_assert(test, message) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; \
                                if (message) return message; } while (0)
#define mu_report() printf("Tests run: %d\n", tests_run)
#define mu_run_suite(suite) do { \
    char* msg = suite();\
    if(msg) { printf("%s\n", msg); free(msg);} \
} while (0)
int tests_run;
