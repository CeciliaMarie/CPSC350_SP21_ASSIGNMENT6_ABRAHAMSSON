/*
Stephanie Munday and Cecilia Marie Abrahamsson
2343625 and 2347542
smunday@chapman.edu and abrahamsson@chapman.edu
CPSC-350-08
Assignment 6
*/

#ifndef FACULTY_H
#define FACULTY_H
#include <list>
#include <iterator> //new
#include <string>
#include <iostream>
using namespace std;

class Faculty{
private:
  int m_ID;
  string m_Name;
  string m_Level;
  string m_Department;
public:
  Faculty(); //constructor
  ~Faculty(); //destructor
  list<int> adviseeIDs; //list of advisee IDs

  //GETTERS
  int getID() const;
  string getName() const;
  string getLevel() const;
  string getDepartment() const;

  //SETTERS
  void setID(int id);
  void setName(string name);
  void setLevel(string level);
  void setDepartment(string department);

  //overload equality, less than, greater than operators from bst
  bool operator <(const Faculty& f);
  bool operator >(const Faculty& f);
  bool operator ==(const Faculty& f);
  bool operator !=(const Faculty& f);

};

ostream& operator<<(ostream& os, const Faculty& f);


#endif
