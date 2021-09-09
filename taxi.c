/**
 * CS1010 Semester 1 AY21/22
 * Assignment 1: Taxi
 *
 * Read in four positive integer corresponding to the day of the week,
 * the hour and minute of boarding, and the distance travelled.  Print
 * to the standard output, the taxi fare for the trip.
 *
 * @file: taxi.c
 * @author: Wang Haoyang (Group C08)
 */

#include "cs1010.h"
#include <stdbool.h>

// Function declaration - find their definitions below main()
double get_basic_fare(long distance);
double get_surcharge(long day, long hour, long min);
bool is_week_day(long day);
bool is_morning_peak(long hour, long min);
bool is_evening_peak(long hour);
bool is_midnight_peak(long hour);

int main() {
  long day = cs1010_read_long();      // Day of week
  long hour = cs1010_read_long();     // Hour of day
  long min = cs1010_read_long();      // Minute
  long distance = cs1010_read_long(); // Distance travelled
  cs1010_println_double(get_basic_fare(distance) *
                          get_surcharge(day, hour, min));
}

/** Returns basic fare given a distance travelled
 *  Input: Distance travelled in metres
 **/
double get_basic_fare(long distance) {
  if (distance <= 1000) { // First 1km
    return 3.70;
  }
  // More than 1km travelled
  if (distance <= 10000) { // First 10km
    long num_of_400m = (distance - 1000) / 400;
    if (((distance - 1000) % 400) != 0) {
      // Account for the last less-than-400m distance, if it exists
      num_of_400m += 1;
    }
    // (First 1km) + ((Every 400m thereafter) * 0.22)     
    return (3.70 + (num_of_400m * 0.22));
  }
  // At this point, distance is definitely more than 10km
  //     (First 1km) + (next 9km) + ((Every 350m thereafter) * 0.22)
  long num_of_350m = (distance - 10000) / 350;
  if (((distance - 10000) % 350) != 0) {
    // Account for the last less-than-350m distance, if it exists
    num_of_350m += 1;
  }
  // (First 1km) + ((Every 400m thereafter) * 0.22) +
  //                           ((Every 350m thereafter) * 0.22)
  return (3.70 + (23 * 0.22) + (num_of_350m * 0.22));
} 

/** Returns the appropriate multiplier value to apply surcharge
 *    according to respective peak hour rates given day of week,
 *    hour of day(24h), and minute
 *  Input: Day of week "day", hour of day "hour", minute "min"
 *  Output: Surcharge multiplier
 **/
double get_surcharge(long day, long hour, long min) {
  if (is_evening_peak(hour)) { // 18:00 to 23:59
    return 1.25; // Add 25% surcharge for evening peak hour
  } 
  if (is_midnight_peak(hour)) { // 0:00 (midnight) to 5:59
    return 1.5; // Add 50% surcharge for midnight peak hour
  }
  if (is_week_day(day) && is_morning_peak(hour, min)) {
    // Monday to Friday 6:00 to 9:29
    return 1.25; // Add 25% surcharge for morning peak hour on weekdays
  }  
  return 1.0; // No surcharge otherwise - meaning a multiplier of 1.0
} 

/** Is it a weekday? Give me the day of week in integers and find out
 *  Input: Day of week(integer form) "day"
 *  Ouptut: bool true (it's weekday) || false (it's not weekday)
 **/
bool is_week_day(long day) {
  if (day == 6 || day == 7) { // It's Sat, Sun
    return false; // Obviously not a weekday
  }
  // It's Mon, Tues, Wed, Thurs, Fri
  return true; // It's a weekday :(
} 

/** Is it the morning peak hour? Give me the hour of day and min
 *  Input: Hour of day "hour", minute "min"
 *  Ouptut: bool true (morning peak) || false (not morning peak)
 **/
bool is_morning_peak(long hour, long min) {
  if ((hour >= 6 && hour <= 8) || (hour == 9 && min < 30)) {
  // (It's between 6-8 am)     || (it's between 9-9:29am)
    return true; // It's peak hour
  }
  return false; // It's outside peak hour
}

/** Is it the evening peak hour? Just give me the hour of day -
 *    I can do magic
 *  Input: hour of day "hour"
 *  Output: bool true (evening peak hour) || false (not evening peak)
 **/
bool is_evening_peak(long hour) {
  // Don't need day of week - evening peak applies every day
  // Don't need minute to check if it's evening peak
  if (hour >= 18 && hour <= 23) { // Between 18:00-23:59
    // Without checking min, min can be 0-59, and that's ok. Both 
    // lower bound and upper bound includes all min values 0-59
    return true; // It's evening peak
  }  
  return false;
}

/** Just give me the hour of day! I'll let you know if it's the
 *    witching hour - WAIT - no the midnight peak(ghosts don't take
 *    taxis! phew)
 *  Input: hour of day "hour"
 *  Output: bool true (midnight peak) || false (not midnight peak)
 **/
bool is_midnight_peak(long hour) {
  /** Catch the pattern yet? Like evening peak hour, midnight peak
   *    applies every day
   *    => day of week doesn't matter
   **/
  if (hour >= 0 && hour <= 5) { // It's 0:00-05:59
    // Don't need to check min. Why? Both lower bound and upper bound
    // includes all min values 0-59, and min can only be [0, 59]
    return true; // It's midnight peak
  }
  return false;
}
