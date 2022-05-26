/**
  * @Grading program that can predict the grade that a student should receive.
  * It also alerts students who are close to failing and compares grades across semesters.
  * @Makayla Alston / Gift (Chidera) Uwakwe
  * @collaborators: Gift (Chidera) Uwakwe / Makayla Alston
  * @May 9,2022
 */

 #include <iostream>
 #include "student.h"
 #include "person.h"
 #include <cstring>
 #include <iomanip>
 #include <vector>
 using namespace std;


 /**
 * This is the Student constructor. Each student has an average, a vector of integers containing grades, a passing boolean,
 * an integer keeping track of their final attendance percentage, a vector of integers containing their attendance, and an integer keeping track of the courses a student is enrolled in.
 * @param name: the Student's name; the attribute of name is one inherited from the parent class, Person
 */
Student::Student (string name) : Person(name)
{
  average = 0;
  vector<int> grades;
  passing = true;
  attendance_final = 100;
  courses = 0;
}

 /**
 * this function is an operator overload. It gives the method sort the ability to compare the averages of two Student objects in order to find which average is greatest.
 * @param Student_1: the student object being compared against
 * @returns the better comparison
 */
bool Student::operator<(Student Student_1)
{
  return this->average > Student_1.average;
}

 /**
 * This function calculates the average of a given student by adding all of their grades and dividing by the total amount of grades
 * @param vector <int> grades: a vector of integers containing the grades assigned to a student.
 */
void Student::student_avg()
{
  int sum = 0;
  int total = grades.size();
  int average = 0;
  for (int index = 0; index < grades.size(); index++)
  {
    sum += grades.at(index);
  }
  average = sum / total;
  this->average = average;
}

 /**
 * This function prints the grades contained within a student's vector of grades
 */
void Student::view_grades()
{
  for (int index = 0; index < grades.size(); index++)
  {
    cout << index << " ";
  }
}

 /**
 * This function prints all of the attributes associated with a given student, including their name, ID number, average, courses enrolled, if they are passing, and their attendance percentage.
 */
void Student::view_student()
{
  cout << endl;
  cout << "Hello! My name is: " << name << "!" << endl;
  cout << "My ID is: " << ID << endl;
  cout << "My average is: " << average << "!" << endl;
  cout << "I am enrolled in " << courses << " courses!" << endl;
  cout << "My grades are: " << endl;
  for (int index = 0; index < grades.size(); index++)
  {
    cout << grades[index] << " ";
  }
  cout << endl;
  if (this->passing == true)
  {
    cout << "I am passing this class! :D" << endl;
  }
  else
  {
    cout << "I am not passing this class :(" << endl;
  }
  cout << "I have a " << attendance_final << "% attendance rate!" << endl;
}

void Student::set_grade(int grade)
{
  grades.push_back(grade);
}

void Student::set_average(int new_average)
{
  average = new_average;
}

 /**
 * This function recieves the amount of courses student is enrolled in, and sets the value for the Student.
 */
void Student::set_courses()
{
  string test_name = "hello";
  Student test(test_name);
  if (test.courses == 0)
  {
    int course_num = 0;
    cout << "How many courses is " << this->name << " enrolled in? ";
    cin >> course_num;
    test.courses = course_num;
    cout << "I am enrolled in " << this->courses << " courses!" << endl;
  }
  else if (test.courses != 0)
  {
    cout << "I am enrolled in " << this->courses << " courses!" << endl;
  }
}

/**
 * This function prints the attendance entered for student.
 */
void Student::print_attendance()
{
  cout<<"\n\n\t\t             STUDENT RESULT \n\n";
	cout<<"=========================================================================================\n";
	cout<<"Id.No    Monday   Tuesday   Wednesday   Thursday   Friday  " << endl;
	cout<<"=========================================================================================\n";
  for (int index = 0; index < 1; index++ )
    {
      cout << ID << setw(5);
      for (int index = 0; index < attendance.size(); index++)
   {
      if (attendance[index] == 0)
      {
        cout << " N " << setw(8) << " ";
      }
     else if (attendance[index] == 1)
     {
       cout << "Y" << setw(9) << " ";
     }
     else
       break;
   }
    cout << endl;
    }
}
