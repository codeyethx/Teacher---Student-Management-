/**
  * @Makayla Alston / Gift (Chidera) Uwakwe
  * @collaborators: Gift (Chidera) Uwakwe / Makayla Alston
  * @May 9,2022
 */

#ifndef STUDENTS_H
#define STUDENTS_H
#include "person.h"
#include <iostream>
#include <vector>
using namespace std;


class Student: public Person
{


public:
  Student(string name);
  int average;
  vector<int> grades;
  bool passing;
  vector<int> attendance;
  int attendance_final;
  int courses;
  bool operator<(Student Student_1);
  void student_avg();
  void view_grades();
  void view_student();
  void set_courses();
  void generate(string name);
  void set_grade(int grade);
  void set_average(int new_average);
  void print_attendance();




private:





};


 #endif
