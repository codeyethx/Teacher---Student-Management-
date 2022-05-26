/**
  * @Grading program that can predict the grade that a student should receive.
  * It also alerts students who are close to failing and compares grades across semesters.
  * @Makayla Alston / Gift (Chidera) Uwakwe
  * @collaborators: Gift (Chidera) Uwakwe / Makayla Alston
  * @May 9,2022
 */

 #include <iostream>
 #include <cstring>
 #include <ctime>
 #include <vector>
 #include "person.h"
 using namespace std;

 /**
 * This is the Person constructor that holds attributes such as name and unqiue ID for student..
 * @param name: the person's name; the attribute of name is one that base classes inherit from the parent class, Person
 */
Person::Person(string name)
{
  this->name = name;
  ID = rand();

}
