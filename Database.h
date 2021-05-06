/*
Stephanie Munday and Cecilia Marie Abrahamsson
2343625 and 2347542
smunday@chapman.edu and abrahamsson@chapman.edu
CPSC-350-08
Assignment 6
*/

#ifndef DATABASE_H
#define DATABASE_H
#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include "FileProcessor.h"
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;


class Database{
private:
public:
  Database(); //constructor
  ~Database(); //destructor
  void simulation(); //runs database simulation
};

#endif
