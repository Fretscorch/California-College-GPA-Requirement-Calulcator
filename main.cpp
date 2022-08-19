//This program is intended for currently enrolled high school students. Its purpose is to inform them what GPA they will need to meet the minimum requirements for enrollment in a college of their choice. Then they can enter a select number of grades to see what the resulting GPA is, giving them an idea of how well they should be doing in their classes in order to get into a university they're interested in. The list provides the most popular colleges in California for the purposes of demonstrating the functions of the program.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

double CalcGradePointAverage(double gradeValue, int numClasses) {
  double gradePointAverage;

  gradePointAverage = gradeValue / numClasses;

  return gradePointAverage;
  }

int main() {
  int numClasses, i;
  string collegeName;
  char finalGrade;
  double gradeValue = 0.0;
  const double uclaGPA = 3.0;
  const double csunGPA = 2.5;
  const double citGPA = 3.8;

  cout << "University of California, Los Angeles (UCLA)" << endl;
  cout << "California State University (CSU)" << endl;
  cout << "California Insititute of Technology (CIT)" << endl;
  cout << endl;
  cout << "Select a university from this list that you're interested in enrolling to, entering the acronyms in the parantheses: ";
  cin >> collegeName;

  while ((collegeName != "UCLA") && (collegeName != "CSU") && (collegeName != "CIT")) {
    cout << endl;
    cout << "This university is not on the list. Please try again with a university from the list: ";
    cin >> collegeName;
    }

  if (collegeName == "UCLA") {
    cout << endl;
    cout << "The minimum required GPA to enroll in " << collegeName << " is " << fixed << setprecision(1) << uclaGPA << "."     << endl;
  }
  else if (collegeName == "CSU") {
    cout << endl;
    cout << "The minimum required GPA to enroll in " << collegeName << " is " << fixed << setprecision(1) << csunGPA << "."     << endl;
  }
  else if (collegeName == "CIT") {
    cout << endl;
    cout << "There is no minimum GPA, but as a top private university, you should have at least a GPA of " << fixed << setprecision(1) << citGPA << " to have a good chance of enrollment." << endl;
  }

  cout << endl;
  cout << "How many classes are you taking? ";
  cin >> numClasses;
  cout << endl;

  for (i = 1; i <= numClasses; ++i) {
    cout << "Enter your final grade for class " << i << ": ";
    cin >> finalGrade;

    if (finalGrade == 'A') {
      gradeValue += 4.0;
    }
    else if (finalGrade == 'B') {
      gradeValue += 3.0;
    }
    else if (finalGrade == 'C') {
      gradeValue += 2.0;
    }
    else if (finalGrade == 'D') {
      gradeValue += 1.0;
    }
    else if (finalGrade == 'F') {
      gradeValue += 0.0;
    }
  }

  cout << endl;
  cout << "Your GPA is " << fixed << setprecision(2) << CalcGradePointAverage(gradeValue, numClasses) << ". ";

  if (collegeName == "UCLA" && CalcGradePointAverage(gradeValue, numClasses) >= 3.0) {
    cout << "You meet the GPA requirement for enrollment at " << collegeName << ". Congratulations!";
  }
  else if (collegeName == "CSU" && CalcGradePointAverage(gradeValue, numClasses) >= 2.5) {
    cout << "You meet the GPA requirement for enrollment at " << collegeName << ". Congratulations!";
  }
  else if (collegeName == "CIT" && CalcGradePointAverage(gradeValue, numClasses) >= 3.8) {
    cout << "You meet the GPA recommendation to compete with other top students for enrollment at " << collegeName << ". Congratulations!";
  }
  else {
    cout << "You do not meet the required or recommended GPA for enrollment at " << collegeName << ".";
  }

  return 0;
  
  }
