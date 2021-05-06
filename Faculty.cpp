/*
Stephanie Munday and Cecilia Marie Abrahamsson
2343625 and 2347542
smunday@chapman.edu and abrahamsson@chapman.edu
CPSC-350-08
Assignment 6
*/

#include "Faculty.h"

Faculty::Faculty(){
  m_ID = -1;
  m_Name = "N/A";
  m_Level = "N/A";
  m_Department = "N/A";
}
Faculty::~Faculty(){}

//GETTERS
int Faculty::getID() const{
  return m_ID;
}
string Faculty::getName() const{
  return m_Name;
}
string Faculty::getLevel() const{
  return m_Level;
}
string Faculty::getDepartment() const{
  return m_Department;
}

//SETTERS
void Faculty::setID(int id){
  m_ID = id;
}
void Faculty::setName(string name){
  m_Name = name;
}
void Faculty::setLevel(string level){
  m_Level = level;
}
void Faculty::setDepartment(string department){
  m_Department = department;
}

//OPERATOR OVERLOADS
bool Faculty::operator <(const Faculty& f){
  if (m_ID < f.m_ID) {
    return true;
  }
  return false;
}

bool Faculty::operator >(const Faculty& f){
  if (m_ID > f.m_ID) {
    return true;
  }
  return false;
}

bool Faculty::operator ==(const Faculty& f){
  if (m_ID == f.m_ID) {
    return true;
  }
  return false;
}

bool Faculty::operator !=(const Faculty& f){
  if (m_ID != f.m_ID) {
    return true;
  }
  return false;
}

ostream& operator<<(ostream& os, const Faculty& f){
  os << f.getID() << endl;
  os << f.getName() << endl;
  os << f.getLevel() << endl;
  os << f.getDepartment()<< endl;

  list<int>::const_iterator iter;
  for (iter = f.adviseeIDs.begin(); iter != f.adviseeIDs.end(); ++iter) {
    os << *iter << endl;
  }
  return os;
}
