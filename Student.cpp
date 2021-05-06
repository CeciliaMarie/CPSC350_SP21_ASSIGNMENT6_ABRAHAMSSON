/*
Stephanie Munday and Cecilia Marie Abrahamsson
2343625 and 2347542
smunday@chapman.edu and abrahamsson@chapman.edu
CPSC-350-08
Assignment 6
*/

#include "Student.h"


Student::Student(){
  m_ID = -1;
  m_Name = "N/A";
  m_Level = "N/A";
  m_Major = "N/A";
  m_GPA = 0.0;
  m_AdvisorID = -1;
}

Student::~Student(){}

//GETTERS
int Student::getID(){
  return m_ID;
}
string Student::getName(){
  return m_Name;
}
string Student::getLevel(){
  return m_Level;
}
string Student::getMajor(){
  return m_Major;
}
double Student::getGPA(){
  return m_GPA;
}
int Student::getAdvisorID(){
  return m_AdvisorID;
}

//SETTERS
void Student::setID(int id){
  m_ID = id;
}
void Student::setName(string name){
  m_Name = name;
}
void Student::setLevel(string level){
  m_Level = level;
}
void Student::setMajor(string major){
  m_Major = major;
}
void Student::setGPA(double gpa){
  m_GPA = gpa;
}
void Student::setAdvisorID(int advisorID){
  m_AdvisorID = advisorID;
}

//OPERATOR OVERLOADS
bool Student::operator <(const Student& s){
  if (m_ID < s.m_ID) {
    return true;
  }
  return false;
}

bool Student::operator >(const Student& s){
  if (m_ID > s.m_ID) {
    return true;
  }
  return false;
}

bool Student::operator ==(const Student& s){
  if (m_ID == s.m_ID) {
    return true;
  }
  return false;
}

bool Student::operator !=(const Student& s){
  if (m_ID != s.m_ID) {
    return true;
  }
  return false;
}

ostream& operator<<(ostream& os, Student& s){
  os << s.getID() << endl; //include all other fields later
  os << s.getName() << endl;
  os << s.getLevel() << endl;
  os << s.getMajor() << endl;
  os << s.getGPA()<< endl;
  os << s.getAdvisorID() << endl;
  return os;
}
