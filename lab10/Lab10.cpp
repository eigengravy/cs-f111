#include <cp/cp.hpp>

/**
 * @brief Prompts the user till they input a valid cgpa and then returns that value. Valid cgpa is a real number between 0 and 10, both inclusive.
 * 
 */
double read_valid_cgpa() {
  double cgpa = cp::read_double();
  while (cp::or_op(cgpa < 0, cgpa > 10)) {
    cp::print("Invalid input; try again: ");
    cgpa = cp::read_double();
  }
  return cgpa;
}

/**
 * @brief Outputs the given name and the given cgpa as the highest scorer on the console.
 *  
 */
void report_highest(cp::string name, double cgpa) {
  cp::print("Highest cgpa is ");
  cp::println(name + " (" + cp::to_string(cgpa) + ")");
  // Make no changes to this function
}

int main() {
  char response = 'y';
  cp::string student_name;
  double student_cgpa;
  cp::string highest_student_name;
  double highest_student_cgpa;

  while (response == 'y') {
    cp::print("Enter student's name: ");
    student_name = cp::read_line();
    cp::print("Enter student cgpa: ");
    student_cgpa = read_valid_cgpa();

    if (student_cgpa > highest_student_cgpa) {
      highest_student_name = student_name;
      highest_student_cgpa = student_cgpa;
    }

    cp::print("Do you want to add another student? (y/n) ");
    response = cp::read_char();
  }
  report_highest(highest_student_name, highest_student_cgpa);
  
  return 0;
}
