// Speedunit.h
/*  Speedunit is a basic automated testing suite based on Minunit by
    Jera Design (jera.com). I lifted some of this code from Jera, some 
    from Zed Shaw (learncodethehardway.org), and some of the ideas from 
    seatest (seatest.googlecode.com).

    I made this because other minimalist testing suites are too wordy. 
    Speedunit is designed to be used in IDEs and editors. It allows the dev
    to be as minimalistic as possible.

    Speedunit is liscenced under the DWTFYW Liscence. Effectively, I don't care
    at all about what you do to this. Just be nice and say the above, kay?
*/
#define NDEBUG

#ifndef __SPEEDUNIT
#define __SPEEDUNIT

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "dbg.h"

int sp_tests_run;
int sp_assertions;
int sp_tests_failed;
int sp_status;

// \macro
// Define a safe block for making macros with multiple expressions.
#define safe_block(block) do {\
    block \
} while (0)

// \macro
// Make a standard signature for a test.
#define sp_test(testname) char *testname()
#define sp_suite(testname) char *testname()

// \macro 
// Print the fail message.
#define sp_failmsg(message) safe_block( \
    char* msg = malloc(255); \
    snprintf(msg, 255, "\nfail (%s:%d): %s, in %s", __FILE__, __LINE__, message, __FUNCTION__); \
    return msg; \
)

// Assertion macros.

/** Assert that the expression is true, if not, fail with the message.
 *
 * \param a The expression to be evaluated.
 * \param message The message to display. 
 */ 
#define sp_assert(a, message) safe_block( \
    sp_assertions++; \
    if (!(a)) \
        sp_failmsg(message); \
    else printf("."); \
)

// \macro
// Assert that two strings are equal. If not, fail with the message.
#define sp_streql(str, ing, message) sp_assert(strcmp(str, ing) == 0, message)

// \macro
// Run a test.
#define sp_run_test(test) safe_block( \
    debug("Running test %s...", #test ); \
    char* message = test(); \
    sp_tests_run++; \
    if (message) { \
        return message; \
    } \
)

// \macro
// Run a group of tests.
#define sp_run_suite(suite) safe_block( char* msg = suite(); if(msg){ printf("%s\n", msg); free(msg); } )
#define sp_report() printf("Tests run: %d\n", sp_tests_run)

#endif

