/**
  * @Makayla Alston / Gift (Chidera) Uwakwe
  * @collaborators: Gift (Chidera) Uwakwe / Makayla Alston
  * @May 9,2022
 */

#ifndef TEACHER_H
#define TEACHER_H
#include <iostream>
#include "person.h"
#include "student.h"
#include <vector>
using namespace std;


class Teacher: public Person
{


public:
  Teacher (string name, vector<Student> &);
  void view_teacher(vector<Student>);
  void print_roster(vector<Student>);
  void input_grades(vector <Student> &);
  void class_average(vector <Student> &);
  void class_ranks(vector <Student> &);
  void if_failing(vector <Student> &);
  void input_attendance(vector <Student> &);




private:
  int students;
};


#endif
