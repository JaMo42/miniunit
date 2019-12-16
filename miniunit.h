/* Based on MinUnit: http://www.jera.com/techinfo/jtns/jtn002.html */
#ifndef MINUNIT_H
#define MINUNIT_H
#ifdef _WIN32
#include <stdlib.h>
#endif
#include <stdio.h>

#define mu_assert(message, test)\
  do { if (!(test)) return message; } while (0)

// Modified for more interesting output
#define mu_run_test(test)\
  do {\
    const char *message = test();\
    printf("-- %s%s\x1b[0m\n", message ? "\x1b[31m" : "\x1b[32m", #test);\
    ++tests_run;\
    if (message) return message;\
  } while (0)

// Defines a test function
#define TEST(name) const char * name()

#ifdef __cplusplus
extern "C" {
#endif

// Number of tests that ran
int tests_run;

// Function executing tests
const char *all_tests();

int main() {
#ifdef _WIN32
  // Required on (atleast my) Windows to get terminal colors to work.
  system("");
#endif
  puts("RUNNING TESTS");
  const char *result = all_tests();
  if (result != 0) {
    printf("%s\nABORT\n", result);
  }
  else {
    puts("ALL TESTS PASSED");
  }
  printf("Tests run: %d\n", tests_run);
  return result != 0;
}

#ifdef __cplusplus
}
#endif

#endif /* !MINUNIT_H */
