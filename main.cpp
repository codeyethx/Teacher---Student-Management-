/**
  * @Grading program that can predict the grade that a student should receive.
  * It also alerts students who are close to failing and compares grades across semesters.
  * @Makayla Alston / Gift (Chidera) Uwakwe
  * @collaborators: Gift (Chidera) Uwakwe / Makayla Alston
  * @May 9,2022
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <ctime>
#include "person.h"
#include "student.h"
#include "teacher.h"
using namespace std;


void Student_View(string input,vector<Student> & classroom, vector<Teacher> & instructor);

/**
* This is the function that allows the user to switch to the teacher view and control / access grade management attributes.
* @param name: input is the selection that user makes, classroom holds all the students with their specified attributes, instructor, likewise, holds information for the teachers.
*/
void Teacher_View (string input, vector<Student> & classroom, vector<Teacher> & instructor)
{
  cout << endl << "Select an action:" << endl << "1) View Roster" << endl << "2) View Class Average" << endl <<  "3) Input Grades" << endl << "4) Check Failing" << endl <<  "5) View Ranks" << endl << "6) Input Attendance" << endl << "7) View Teacher" << endl << "8) Switch View" << endl << "9) Done" << endl;
  cout << endl << "Selection: ";
  string action = " ";
  cin >> action;
  if (action == "1")
  {
    instructor.back().print_roster(classroom);
    Teacher_View(input, classroom, instructor);
  }
  else if (action == "2")
  {
    instructor.back().class_average(classroom);
    Teacher_View(input, classroom, instructor);
  }
  else if (action == "3")
  {
    instructor.back().input_grades(classroom);
    Teacher_View(input, classroom, instructor);
  }
  else if (action == "4")
  {
    instructor.back().if_failing(classroom);
    Teacher_View(input, classroom, instructor);
  }
  else if (action == "5")
  {
    instructor.back().class_ranks(classroom);
    Teacher_View(input, classroom, instructor);
  }
  else if (action == "6")
  {
    instructor.back().input_attendance(classroom);
    Teacher_View(input, classroom, instructor);
  }
  else if (action == "7")
  {
    string test_name = " ";
    cin >> test_name;
    Teacher test(test_name, classroom);
    test.view_teacher(classroom);
    Teacher_View(input, classroom, instructor);
  }
  else if (action == "8")
  {
    Student_View(input, classroom, instructor);
  }
  else if (action == "9")
  {
    cout << "Class dismissed!" << endl;
    return;
  }
}

/**
* This is the function that allows the user to switch to the student view and access grade management attributes.
* @param name: input is the selection that user makes, classroom holds all the students with their specified attributes, instructor, likewise, holds information for the teachers.
*/
void Student_View(string input, vector<Student> & classroom, vector<Teacher> & instructor)
{
  cout << endl << "Select an action:" << endl << "1) View Student" << endl << "2) Check Attendance" << endl <<  "3) View Student Grades" << endl << "4) View Student Courses" << endl << "5) View Student Average" << endl << "6) Switch View" << endl << "7) Done" << endl << "Selection: ";
  string action = " ";
  cin >> action;
  if (action == "1")
  {
    cout << "Which student would you like to view? ";
    string test_name = " ";
    cin >> test_name;
    for (int index = 0; index < classroom.size(); index++)
    {
      if (classroom[index].name == test_name)
      {
        classroom[index].view_student();
      }
    }
    Student_View(input, classroom, instructor);
  }
  else if (action == "2")
  {
    cout << "Which student would you like to view? ";
    string test_name = " ";
    cin >> test_name;
    for (int index = 0; index < classroom.size(); index++)
    {
      if (classroom[index].name == test_name)
      {
        classroom[index].print_attendance();
      }

    }
    Student_View(input, classroom, instructor);
  }

  else if (action == "3")
  {
    cout << "Which student would you like to view? ";
    string test_name = " ";
    cin >> test_name;
    for (int index = 0; index < classroom.size(); index++)
    {
      if (classroom[index].name == test_name)
      {
        classroom[index].view_grades();
      }
    }
    Student_View(input, classroom, instructor);
  }
  else if (action == "4")
  {
    cout << "Which student would you like to view? ";
    string test_name = " ";
    cin >> test_name;
    for (int index = 0; index < classroom.size(); index++)
    {
      if (classroom[index].name == test_name)
      {
        classroom[index].set_courses();
      }

    }
    Student_View(input, classroom, instructor);
  }
  else if (action == "5")
  {
    string test_name = " ";
    cin >> test_name;
    for (int index = 0; index < classroom.size(); index++)
    {
      if (classroom[index].name == test_name)
      {
        classroom[index].view_grades();
      }

    }
    Student_View(input, classroom, instructor);
  }
  else if (action == "6")
  {
    Teacher_View(input, classroom, instructor);
  }
  else if (action == "7")
  {
    cout << "Class dismissed!" << endl;
    return;
  }

}

//Controls program execution
int main()
{
  srand(time(0));
  cout << "How many students are in your class?" << endl;
  int students = 0;
  cin >> students;
  vector<Student> classroom;
  for (int index = 0; index < students; index++)
  {
    cout << "Enter the name for Student # " << index << ": ";
    string student_name;
    cin >> student_name;
    Student s(student_name);
    classroom.push_back(s);
  }
  cout << "How many teachers are in your class? " << endl;
  int teachers = 0;
  cin >> teachers;
  vector<Teacher> instructor;
  for (int index = 0; index < teachers; index++)
  {
    cout << "Enter the name for Teacher # " << index << ": ";
    string teacher_name;
    cin >> teacher_name;
    Teacher t(teacher_name, classroom);
    instructor.push_back(t);
  }
  cout << "1) Teacher View or 2) Student View? " << endl;
  string input = " ";
  cin >> input;
  if (input == "1")
  {
    Teacher_View(input, classroom, instructor);
  }
  else if (input == "2")
  {
    Student_View(input,classroom, instructor);
  }
  return 0;
}
