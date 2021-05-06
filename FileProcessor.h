/*
Stephanie Munday and Cecilia Marie Abrahamsson
2343625 and 2347542
smunday@chapman.edu and abrahamsson@chapman.edu
CPSC-350-08
Assignment 6
*/

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H
#include <iostream>
#include "BST.h"
#include "Student.h"
#include "Faculty.h"
using namespace std;


class FileProcessor{
private:
public:
  FileProcessor(); //constructor
  ~FileProcessor(); //destructor
  void processInFileS(string inFile, BST<Student>& studentTree); //read/write students
  void processInFileF(string inFile, BST<Faculty>& facultyTree); //read/write faculty

};

#endif
