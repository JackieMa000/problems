#include <dsa/lib/utils/memory.h>
#include <check.h>
#include <stdlib.h>

START_TEST(test_memset) {
    ck_assert_int_eq(2, plus(1, 1));
}
END_TEST

Suite *memset_suite() {
    TCase *tc = tcase_create("Core");
    tcase_add_test(tc, test_memset);

    Suite *s = suite_create("memset");
    suite_add_tcase(s, tc);

    return s;
}

int main(void) {
    Suite *s = memset_suite();
    SRunner *sr = srunner_create(s);

    // No fork mode for debugging and working with Address Sanitizer.
    srunner_set_fork_status(sr, CK_NOFORK);

    srunner_run_all(sr, CK_NORMAL);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
