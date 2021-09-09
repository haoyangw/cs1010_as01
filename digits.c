/**
 * CS1010 Semester 1 AY21/22
 * Assignment 1: Digits
 *
 * Read in a positive integer from the standard input and print
 * the sum of its digits to the standard output.
 *
 * @file: digits.c
 * @author: Wang Haoyang (Group C08)
 */

#include "cs1010.h"

// Function declaration - see their definitions below main
long sum_of_digits(long num);

int main() {
  // Obtain non-negative integer from user input
  long num = cs1010_read_long();
  cs1010_println_long(sum_of_digits(num));
}

/**
 *  Returns the sum of the individual digits of given number
 *  Input: Number 'num'
 *  Output: Sum of individual digits of said number
 **/
long sum_of_digits(long num) {
  if (num < 10) { // Reached the last digit of the initial number
    // No need to perform calculations - last_digit == remaining_digits
    return num;
  } 
  // At this point, num still has at least 2 digits - recurse some more
  long last_digit = num % 10;
  // Remove the last digit from 'num'
  long remaining_digits = num / 10;
  // Repeatedly calls itself to add each digit from right to left
  return last_digit + sum_of_digits(remaining_digits);
}
