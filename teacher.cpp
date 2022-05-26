/**
  * @Grading program that can predict the grade that a student should receive.
  * It also alerts students who are close to failing and compares grades across semesters.
  * @Makayla Alston / Gift (Chidera) Uwakwe
  * @collaborators: Gift (Chidera) Uwakwe / Makayla Alston
  * @May 9,2022
 */

 #include <iostream>
 #include <iomanip>
 #include "student.h"
 #include "person.h"
 #include "teacher.h"
 #include <cstring>
 #include <vector>
 #include <algorithm>
 using namespace std;


 /**
 * Constructor for a teacher. Each teacher has a certain amount of students, a name, and an ID number; both the name and ID number are attributes that are inherited from the Person class
 * @param the Teacher's name; the attribute of name is one inherited from the parent class, Person
 */
Teacher::Teacher(string name, vector<Student> & classroom) : Person(name)
{
  int students = classroom.size(); //something wrong, fix
}

 /**
 * This function reads out the teacher attributes such as name, ID, and the students they teach.
 * @param vector<Student> classroom: a vector of Student objects that contain the classroom a teacher is in charge of.
 */
void Teacher::view_teacher(vector <Student> classroom)
{
  cout << "Hello! My name is: " << this->name << "!" << endl;
  cout << "I teach " << students << " students!";
  cout << "My ID is: " << this->ID << endl;
}


 /**
 * This function reads through classroom vectr and outputs all student names.
 * @param vector<Student> classroom: a vector of Student objects that contain the classroom a teacher is in charge of.
 */
void Teacher::print_roster (vector <Student> classroom)
{
  for (int index = 0; index < classroom.size(); index++)
  {
    cout << classroom.at(index).name << endl;
  }
}

 /**
 * This function prints the names of the students whose passing boolean is false.
 * @param vector<Student> classroom: a vector of Student objects that contain the classroom a teacher is in charge of.
 */
void Teacher::if_failing(vector <Student> & classroom)
{
  cout << "Oops! Looks like a parent-teacher conference is in order for: " << endl;
  int counter = 0;
  for (int index = 0; index < classroom.size(); index++)
  {
    if (classroom.at(index).passing == false)
    {
      cout << classroom.at(index).name << " " << endl;
      counter += 1;
    }
  }
  cout << endl;
  if (counter == 0)
  {
    cout << "Joe mama! Just kidding. Go buy yourself something special, everyone's passing ;)" << endl;
  }
}

 /**
 * This function prints the students in the class by name in order of their averages, from greatest to least.
 * @param vector<Student> classroom: a vector of Student objects that contain the classroom a teacher is in charge of.
 */
void Teacher::class_ranks(vector <Student> & classroom)
{
  sort(classroom.begin(), classroom.end());
  for (auto student : classroom)
    {
      cout << student.name << endl;
    }
}

/**
 * This function function calculates the average of the classroom by adding all of their grades and dividing by the total amount of students
 * @param vector<Student> classroom: a vector of Student objects that contain the classroom a teacher is in charge of.
 */
void Teacher::class_average(vector <Student> & classroom)
{
  int sum = 0;
  int class_total = classroom.size();
  int class_average = 0;
  for (int index = 0; index < classroom.size(); index++)
  {
    sum += classroom.at(index).average;
  }
  class_average = sum / class_total;
  cout << "Class average is: " << class_average << ".";
  if (class_average > 90)
  {
    cout << " Someone was valedictorian in teacher school!";
  }
  else if (class_average > 70)
  {
    cout << " Wow, looking good!";
  }
  else if (class_average < 70)
  {
    cout << " Looks like some tutoring is needed...";
  }
  else if (class_average < 50)
  {
    cout << " We heard McDonald's is hiring...";
  }
  cout << endl;
}

/**
 * This function allows the teacher to input grades for all the students in the classroom. Every time a grade is added, the average for the Student is updated accordingly.
 * @param vector<Student> classroom: a vector of Student objects that contain the classroom a teacher is in charge of.
 */
void Teacher::input_grades(vector <Student> & classroom)
{
  cout << "How many assignments will you be entering into the gradebook? " << endl;
  int assignments = 0;
  cin >> assignments;
  while (assignments != 0)
  {
    for (int index = 0; index < classroom.size(); index++)
    {
      int temp = 0;
      int grade = 0;
      cout << "Enter the grade for assignment # " << index << " for " <<  classroom.at(index).name << ":";
      cin >> grade;
      classroom[index].set_grade(grade);
      int new_total = classroom[index].grades.size();
      int new_sum = 0;
      for (int index2 = 0; index2 < classroom[index].grades.size(); index2++)
      {
        new_sum += classroom[index].grades.at(index2);
        cout << "These are your grades " << classroom[index].grades.at(index2) << endl;
      }
      cout << "This is the new sum: " << new_sum << endl;
      cout << "This is the new total: " << new_total << endl;
      classroom[index].set_average(new_sum / new_total);
      if (classroom[index].average < 70)
      {
        classroom[index].passing = false;
      }
    }
    assignments--;
  }
  cout << endl;
}

/**
 * This function allows the teacher to input attendance for the week for every student in a classroom. The final percentage of attendance awarded to each student is adjusted according to whether or not they were present for class.
 * @param vector<Student> classroom: a vector of Student objects that contain the classroom a teacher is in charge of.
 */
void Teacher::input_attendance(vector <Student> & classroom)
{
  int counter = 0;
  for (int index = 0; index < classroom.size(); index++)
  {
    for (int index2 = 1; index2 < 6; index2++)
    {
      int counter = 0;
      int present = 0;
      cout << "Was " << classroom.at(index).name << " present for class on day " << index2 << " today? Enter 0 for absent and 1 for present." << endl;
      cin >> present;
      classroom.at(index).attendance.push_back(present);
    }
  }
  for (int index = 0; index < classroom.size(); index++)
  {
    int counter = 0;
    for (int index2 = 0; index2 < classroom.at(index).attendance.size(); index2++)
    {
      if (classroom.at(index).attendance.at(index) == 0)
      {
        counter += 1;
      }
    }
    if (counter == 0)
    {
      classroom.at(index).attendance_final = 100;
    }
    else if (counter == 1)
    {
      classroom.at(index).attendance_final = 80;
    }
    else if (counter == 2)
    {
      classroom.at(index).attendance_final = 60;
    }
    else if (counter == 3)
    {
      classroom.at(index).attendance_final = 40;
    }
    else if (counter == 4)
    {
      classroom.at(index).attendance_final = 20;
    }
    else if (counter == 5)
    {
      classroom.at(index).attendance_final = 0;
    }
  }
}
