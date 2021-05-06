/*
Stephanie Munday and Cecilia Marie Abrahamsson
2343625 and 2347542
smunday@chapman.edu and abrahamsson@chapman.edu
CPSC-350-08
Assignment 6
*/

#include <iostream>
#include <string>
#include <fstream>
#include "FileProcessor.h"
#include "BST.h" //new
using namespace std;

FileProcessor::FileProcessor(){ //constructor
}

FileProcessor::~FileProcessor(){ //deconstructor
}


void FileProcessor::processInFileS(string inFile, BST<Student>& studentTree){ //pass by value
  ifstream inFS;
  string fileLine;
  Student dummyStudent;

  //opening both input file and output file
  inFS.open(inFile);

  //checks if its is actually open
  if(inFS.is_open()){
    //while there is line input
    while(!inFS.fail()){

      getline(inFS, fileLine);
      if(fileLine == ""){}
      else{
        dummyStudent.setID(stoi(fileLine)); //set id

        getline(inFS, fileLine);
        dummyStudent.setName(fileLine); //set name

        getline(inFS, fileLine);
        dummyStudent.setLevel(fileLine); //set level

        getline(inFS, fileLine);
        dummyStudent.setMajor(fileLine); //set major

        getline(inFS, fileLine);
        dummyStudent.setGPA(stod(fileLine)); //set gpa

        getline(inFS, fileLine);
        dummyStudent.setAdvisorID(stoi(fileLine)); //set advisor

        //add student to studentTree
        studentTree.insert(dummyStudent);
      }
    }
  }
  //closing file
  inFS.close();
}

void FileProcessor::processInFileF(string inFile, BST<Faculty>& facultyTree){ //pass by value
  ifstream inFS;
  string fileLine;
  Faculty dummyFaculty;

  //opening both input file and output file
  inFS.open(inFile);

  //checks if its is actually open
  if(inFS.is_open()){
    //while there is line input
    while(!inFS.fail()){

      getline(inFS, fileLine);
      if(fileLine == ""){}
      else{
        dummyFaculty.setID(stoi(fileLine)); //set id

        getline(inFS, fileLine);
        dummyFaculty.setName(fileLine); //set name

        getline(inFS, fileLine);
        dummyFaculty.setLevel(fileLine); //set level

        getline(inFS, fileLine);
        dummyFaculty.setDepartment(fileLine); //set department

        getline(inFS, fileLine);
        while(fileLine != ""){ //set advisee list
          dummyFaculty.adviseeIDs.push_back(stoi(fileLine));
          getline(inFS, fileLine);
        }
        //add student to studentTree
        facultyTree.insert(dummyFaculty);
        dummyFaculty.adviseeIDs.clear();
      }
    }
  }
  //closing file
  inFS.close();
}
