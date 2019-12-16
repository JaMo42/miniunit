#include "miniunit.h"

int foo() {
  return 1;
}

/* Define a test
 * Instead of the TEST macro, the function can also
 * just be declared a `const char *test()`.
 */
TEST(my_test) {
  /* Assert an expression to be true */
  mu_assert("message", foo());
  /* Test cases must return 0 on success */
  return 0;
}

TEST(will_fail) {
  mu_assert("this test failed", 0);
  return 0;
}

TEST(wont_run) {
  mu_assert("message", 1);
  return 0;
}

/* This function must be defined and runs all of the tests */
const char * all_tests() {
  mu_run_test(my_test);
  mu_run_test(will_fail);
  mu_run_test(wont_run);
  return 0;
}