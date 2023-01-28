#include <stdlib.h>
#include <check.h>
#include "../src/layout.h"
#include "../src/corpus.h"

START_TEST(test_pos_finger) {
  ck_assert(pos_finger(0) == LP);
  ck_assert(pos_finger(1) == LR);
  ck_assert(pos_finger(10) == LP);
} END_TEST

START_TEST(test_pos_x) {
  ck_assert(pos_x(0) == 0);
  ck_assert(pos_x(1) == 1);
  ck_assert(pos_x(10) == 0);
  ck_assert(pos_x(20) == 0);
  ck_assert(pos_x(29) == 9);
} END_TEST

START_TEST(test_pos_y) {
  ck_assert(pos_y(0) == 0);
  ck_assert(pos_y(1) == 0);
  ck_assert(pos_y(10) == 1);
  ck_assert(pos_y(20) == 2);
  ck_assert(pos_y(29) == 2);
} END_TEST

START_TEST (test_x_distance) {
  ck_assert(x_distance(0, 1) == 1);
  ck_assert(x_distance(1, 0) == 1);
  ck_assert(x_distance(1, 1) == 0);
  ck_assert(x_distance(0, 10) == 0);
  ck_assert(x_distance(0, 13) == 3);
} END_TEST

START_TEST (test_y_distance) {
  ck_assert(y_distance(0, 1) == 0);
  ck_assert(y_distance(0, 10) == 1);
  ck_assert(y_distance(10, 0) == 1);
  ck_assert(y_distance(10, 5) == 1);
  ck_assert(y_distance(20, 5) == 2);
} END_TEST

START_TEST (test_distance) {
  ck_assert(distance(0, 0) == 0);
  ck_assert(distance(0, 1) == 1);
  ck_assert(distance(0, 2) == 2);
  ck_assert(distance(10, 0) == 1);
  ck_assert(distance(20, 0) == 2);
} END_TEST

START_TEST(test_char_to_index) {
  ck_assert(char_to_index('@') == -1);
  ck_assert(char_to_index('a') == 0);
  ck_assert(char_to_index('A') == 0);
  ck_assert(char_to_index('h') == 7);
  ck_assert(char_to_index('H') == 7);
} END_TEST

START_TEST(test_bigram_to_index) {
  ck_assert(bigram_to_index('@', '4') == -1);
  ck_assert(bigram_to_index('@', 'h') == -1);
  ck_assert(bigram_to_index('e', '2') == -1);
  ck_assert(bigram_to_index('a', 'A') == 0);
  ck_assert(bigram_to_index('a', 'b') == 1);
  ck_assert(bigram_to_index('t', 'h') == 596);
} END_TEST

START_TEST(test_trigram_to_index) {
  ck_assert(trigram_to_index('@', 'a', 'a') == -1);
  ck_assert(trigram_to_index('a', 'a', '@') == -1);
  ck_assert(trigram_to_index('a', 'a', 'a') == 0);
  ck_assert(trigram_to_index('a', 'a', 'b') == 1);
  ck_assert(trigram_to_index('a', 'b', 'a') == 31);
  ck_assert(trigram_to_index('b', 'a', 'a') == 961);
} END_TEST

Suite * woagcat_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Woagcat");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_pos_finger);
  tcase_add_test(tc_core, test_pos_x);
  tcase_add_test(tc_core, test_pos_y);
  tcase_add_test(tc_core, test_x_distance);
  tcase_add_test(tc_core, test_y_distance);
  tcase_add_test(tc_core, test_distance);
  tcase_add_test(tc_core, test_char_to_index);
  tcase_add_test(tc_core, test_bigram_to_index);
  tcase_add_test(tc_core, test_trigram_to_index);
  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = woagcat_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
