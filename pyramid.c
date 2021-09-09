/**
 * CS1010 Semester 1 AY21/22
 * Assignment 1: Pyramid
 *
 * Read in three positive integer corresponding to the width,
 * length, and height of a pyramid from the standard input, and
 * print the total surface area to the standard output.
 *
 * @file: pyramid.c
 * @author: Wang Haoyang (Group C08)
 */

#include "cs1010.h"
#include <math.h>

// Function declarations - see their definitions after main
double hypotenuse_of(double leg1, double leg2);
long area_of_rectangle(long width, long length);
double area_of_triangle(double side1, double side2, double side3);

int main() {
  // Obtain the width, length and height from user input
  long width = cs1010_read_long();
  long length = cs1010_read_long();
  long height = cs1010_read_long();
  // Compute half of a diagonals of the rectangular base
  double half_diag = hypotenuse_of((double)width, (double)length) / 2;
  // Compute the isosceles side of the triangular faces
  double isosceles_side = hypotenuse_of(half_diag, (double)height);
  // Compute the sum of the triangular sides
  double sum_of_triag_sides = \
           (2 * (area_of_triangle( \
                   (double)width, isosceles_side, isosceles_side))) + \
           (2 * (area_of_triangle( \
                   (double)length, isosceles_side, isosceles_side)));
  // Compute area of rectangular base
  long base_area = area_of_rectangle(width, length);
  double surface_area =  sum_of_triag_sides + base_area;
  cs1010_println_double(surface_area);
}

/** Computes the hypotenuse of a right angled triangle given 
 *    its legs
 *  Input: leg1, leg2 are the lengths of sides adjacent to the 
 *    right angle
 *  Output: Hypotenuse of the right angled triangle
 **/
double hypotenuse_of(double leg1, double leg2) {
  double hypotenuse_squared = (leg1 * leg1) + (leg2 * leg2);
  return sqrt(hypotenuse_squared);
}  

/** Computes the area of a rectangle with given width and length
 *  Input: width, length of said rectangle
 *  Output: Area of said rectangle
 **/
long area_of_rectangle(long width, long length) {
  return width * length; 
}  

/** Computes the area of a triangle given the length of its 3 sides
 *  Input: side1, side2, side3 the sides of said triangle
 *  Output: Area of said triangle
 **/ 
double area_of_triangle(double side1, double side2, double side3) {
  // First we compute half of the perimeter, half_perim
  double half_perim = (side1 + side2 + side3) / 2.0;
  // Heron's formula
  double area = \
           sqrt(half_perim * (half_perim - side1) * \
               (half_perim - side2) * (half_perim - side3));
  return area;
}    
