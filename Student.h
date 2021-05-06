/*
Stephanie Munday and Cecilia Marie Abrahamsson
2343625 and 2347542
smunday@chapman.edu and abrahamsson@chapman.edu
CPSC-350-08
Assignment 6
*/

#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
using namespace std;

class Student{
private:
  int m_ID;
  string m_Name;
  string m_Level;
  string m_Major;
  double m_GPA;
  int m_AdvisorID;
public:
  Student(); //constructor
  ~Student(); //destructor

  //GETTERS
  int getID();
  string getName();
  string getLevel();
  string getMajor();
  double getGPA();
  int getAdvisorID();

  //SETTERS
  void setID(int id);
  void setName(string name);
  void setLevel(string level);
  void setMajor(string major);
  void setGPA(double gpa);
  void setAdvisorID(int advisorID);

  //overload equality, less than, greater than operators from bst
  bool operator <(const Student& s);
  bool operator >(const Student& s);
  bool operator ==(const Student& s);
  bool operator !=(const Student& s);

};

ostream& operator<<(ostream& os, Student& s);

#endif
