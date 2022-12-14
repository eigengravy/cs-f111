#include <cp/cp.hpp>

/**
 * @brief Represents the seven days of the week, starting with Monday.
 * 
 */
enum struct day {
  mon = 1,
  tue,
  wed,
  thu,
  fri,
  sat,
  sun
};

/**
 * @brief String representation of the given day `d`.
 * 
 * @retval "Monday" to_string(day::mon)
 * @retval "Sunday" to_string(day::sun)
 * 
 */
cp::string to_string(day d) {
  cp::string s="Monday";
  if (d==day::tue){
    s="Tuesday";
  } else if (d==day::wed){
    s="Wednesday";
  } else if (d==day::thu){
    s="Thursday";
  } else if (d==day::fri){
    s="Friday";
  } else if (d==day::sat){
    s="Saturday";
  } else if (d==day::sun){
    s="Sunday";
  } 
  return s;
}

/**
 * @brief Returns the k-th day of the week for the given integer k between 1 and 7 inclusive.
 * 
 * @retval day::mon kth_day(1)
 * @retval day::sun kth_day(7)
 * 
 */
day kth_day(int k) {
  return day(k);
}

/**
 * @brief Reports the day after the given day.
 * 
 * @retval day::tue next(day::mon)
 * @retval day::mon next(day::sun)
 * 
 */
day next(day d) {
  return day((int(d) % 7) + 1 ); 
}

/**
 * @brief Returns the day before the given day.
 * 
 * @retval day::mon prev(day::tue)
 * @retval day::sun prev(day::mon)
 * 
 */
day prev(day d) {
  if(d == day::mon){
    return day::sun;
  } else {
    return day(int(d)-1);
  }
}

/**
 * @brief Returns the day that appears after `n` days from the given day `d`. `n` must be a non-negative number.
 * 
 * @retval day::mon n_days_from(day::sun, 1)
 * @retval day::sun n_days_from(day::sun, 14)
 * 
 */
day n_days_from(day d, int n) {
  return day(((int(d)+n-1)%7)+1);
}

int main() {
  cp::expect("Monday" == to_string(day::mon), "Monday");
  cp::expect("Sunday" == to_string(day::sun), "Sunday");
  cp::expect("Wednesday" == to_string(day::wed), "Wednesday");

  cp::expect(day::wed == kth_day(3), "Wed is the third day");
  cp::expect(day::fri == kth_day(5), "Fri is the fith day");
  cp::expect(day::sun == kth_day(7), "Sun is the seventh day");

  cp::expect(day::tue == next(day::mon), "Mon's next is Tue");
  cp::expect(day::mon == next(day::sun), "Sun's next is Mon");
  cp::expect(day::wed == next(day::tue), "Tue's next is Wed");

  cp::expect(day::sun == prev(day::mon), "Mon's prev is Sun");
  cp::expect(day::tue == prev(day::wed), "Wed's prev is Tue");
  cp::expect(day::fri == prev(day::sat), "Sat's prev is Fri");

  cp::expect(day::sun == n_days_from(day::sun, 14), "14 days from Sun is Sun");
  cp::expect(day::mon == n_days_from(day::sun, 8), "8 days from Sun is Mon");
  cp::expect(day::wed == n_days_from(day::mon, 2), "1 days from Mon is Tue");

  return 0;
}
