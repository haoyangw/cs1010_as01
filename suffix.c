/**
 * CS1010 Semester 1 AY21/22
 * Assignment 1: Suffix
 *
 * Read in a number and prints out the number with the appropriate suffix.
 *
 * @file: suffix.c
 * @author: Wang Haoyang (Group C08)
 */
#include "cs1010.h"

// Function declaration - see their definitions after main()
void print_with_suffix(long num);

int main() {
  long num = cs1010_read_long(); // Obtain a number from user
  print_with_suffix(num); // Print the given number with appropriate
                          //   suffix to user's screen
}

/** 
 *  Adds the appropriate suffix to the end of a given number when
 *    printing to user's screen
 *  Input: Given number "num"
 *  Output: Not necessary, we are printing directly to user's screen
 **/
void print_with_suffix(long num) {
  /** Print the number to user's screen first - the suffix comes later
   *  Note: no newline printed at the end, so on user's screen suffix
   *    is attached to the end of given number as expected
   **/
  cs1010_print_long(num);
  if (num < 10) { // Don't do division(expensive) unnecessarily
    if (num == 1) {
      cs1010_println_string("st");
    } else if (num == 2) {
      cs1010_println_string("nd");
    } else if (num == 3) {
      cs1010_println_string("rd");
    } else {
      // 4, 5, 6, 7, 8, 9 all have the same suffix
      cs1010_println_string("th");
    }
  } else { // Here comes the divisions to get the ending digits
    long last_digit = num % 10;
    long second_last_digit = (num / 10) % 10;
    if ((last_digit < 4 && last_digit > 0) && // last_digit is 1, 2, 3
        (second_last_digit != 1)) {
      // Last two digits of num is not 11, 12 or 13
      if (last_digit == 1) {
        cs1010_println_string("st");
      } else if (last_digit == 2) {
        cs1010_println_string("nd");
      } else if (last_digit == 3) {
        cs1010_println_string("rd");
      } else {
        // Last digit is 0, 4, 5, 6, 7, 8, 9
        cs1010_println_string("th");
      }
    } else { // last_digit is 0, 4, 5, 6, 7, 8, 9 OR last two digits
             //   are 11, 12, or 13
      // Everything else has suffix "th"
      cs1010_println_string("th");
    }
  }
}
