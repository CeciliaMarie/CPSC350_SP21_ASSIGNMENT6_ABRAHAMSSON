/*
Stephanie Munday and Cecilia Marie Abrahamsson
2343625 and 2347542
smunday@chapman.edu and abrahamsson@chapman.edu
CPSC-350-08
Assignment 6
*/

#include "Database.h"


Database::Database(){}

Database::~Database(){}

void Database::simulation(){
  BST<Student> studentTree;
  BST<Faculty> facultyTree;
  Student studentDummy;
  Faculty facultyDummy;
  list<int> dummyIDs;
  list<BST<Student>> studentList;
  list<BST<Faculty>> facultyList;

  bool run = true;
  int choice = -1;
  int numRolls = 0;
  string hasAdvisees = "n";
  int studentID = -1;
  string studentName = "N/A";
  string studentLevel = "N/A";
  string studentMajor = "N/A";
  double studentGPA = 0.0;
  int studentAdvisorID = -1;
  int facultyID = -1;
  string facultyName = "N/A";
  string facultyLevel = "N/A";
  string facultyDep = "N/A";

  //read in files if they exist
  FileProcessor fileThings;
  fileThings.processInFileS("studentTable.txt", studentTree);
  fileThings.processInFileF("facultyTable.txt", facultyTree);


  while(run == true){
    //giving the user the options
    cout << "   MENU" << endl;
    cout << "----------" << endl;
    cout << "1. Print all students and their information (sorted by ascending id #)." << endl;
    cout << "2. Print all faculty and their information (sorted by ascending id #)." << endl;
    cout << "3. Find and display student information given the students id." << endl;
    cout << "4. Find and display faculty information given the faculty id." << endl;
    cout << "5. Given a student’s id, print the name and info of their faculty advisor." << endl;
    cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
    cout << "7. Add a new student." << endl;
    cout << "8. Delete a student given the id" << endl;
    cout << "9. Add a new faculty member." << endl;
    cout << "10. Delete a faculty member given the id." << endl;
    cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl;
    cout << "12. Remove an advisee from a faculty member given the ids" << endl;
    cout << "13. Rollback" << endl;
    cout << "14. Change a student's major given the student id and the new major." << endl; //NEW EC?
    cout << "15. Exit" << endl;

    cout << "\nPlease enter the number corresponding to your choice: " << endl;
    //saving the choice number
    cin >> choice;
    while(cin.fail()){ //input checking
      cout << "Please enter a number for the choice: " << endl;
      cin.clear();
      cin.ignore(256, '\n');
      cin >> choice;
    }

    if(choice == 1){
      if(!studentTree.containsRoot()){ //if the student tree doesn't exist can't be printed
        cout <<"There are no students in the database" << endl;
      }
      else{ //if it exists print
        studentTree.printInOrder();
      }
    }
    else if(choice == 2){
      if(!facultyTree.containsRoot()){ //if the faculty tree doesn't exist can't be printed
        cout <<"There are no faculty in the database" << endl;
      }
      else{ //if it exists print
        facultyTree.printInOrder();
      }
    }
    else if(choice == 3){
      //prompt user for ID
      cout << "Please enter the student ID: " << endl;
      cin >> studentID;
      while(cin.fail()){ //input checking
        cout << "Please enter a number for the student ID: " << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> studentID;
      }
      studentDummy.setID(studentID); //student dummy object to see if a matching ID exists in the tree

      if(studentTree.contains(studentDummy)){ //whenever using find need to check if it contains first
        cout << studentTree.find(studentDummy)->data << endl;
      }
      else{
        cout << "This student does not exist in the database." << endl;
      }
    }
    else if(choice == 4){
      //prompt user for ID
      cout << "Please enter the faculty ID: " << endl;
      cin >> facultyID;
      while(cin.fail()){ //input checking
        cout << "Please enter a number for the faculty ID: " << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> facultyID;
      }
      facultyDummy.setID(facultyID); //faculty dummy object to see if a matching ID exists in the tree

      if(facultyTree.contains(facultyDummy)){ //whenever using find need to check if it contains first
        cout << facultyTree.find(facultyDummy)->data << endl;
      }
    }
    else if(choice == 5){
      //prompt user for ID
      cout << "Please enter the student ID: " << endl;
      cin >> studentID;
      while(cin.fail()){ //input checking
        cout << "Please enter a number for the student ID: " << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> studentID;
      }
      studentDummy.setID(studentID); //student dummy object to see if a matching ID exists in the tree

      if(studentTree.contains(studentDummy)){ //whenever using find need to check if it contains first
        cout << "\nAdvisor information: " << endl;
        facultyID = studentTree.find(studentDummy)->data.getAdvisorID();
        facultyDummy.setID(facultyID); //faculty dummy object to see if a matching ID exists in the tree
        if (facultyTree.contains(facultyDummy)) {
          cout << facultyTree.find(facultyDummy)->data << endl;
        }
        else{
          cout << "This student was read in from the table. Their advisor does not exist. Referential integrity could not be enforced." << endl;
          cout << "Recommendation: do #11 next to fix this issue" << endl;
        }
      }
    }
    else if(choice == 6){

      //prompt user for ID
      cout << "Please enter the faculty ID: " << endl;
      cin >> facultyID;
      while(cin.fail()){ //input checking
        cout << "Please enter a number for the faculty ID: " << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> facultyID;
      }
      facultyDummy.setID(facultyID); //student dummy object to see if a matching ID exists in the tree

      if(facultyTree.contains(facultyDummy)){ //whenever using find need to check if it contains first
        cout << "\nAdvisee information: " << endl;
        dummyIDs = facultyTree.find(facultyDummy)->data.adviseeIDs;

        //iterate through list of advisees and check if they exist before printing data
        list<int>::const_iterator iter;
        for (iter = dummyIDs.begin(); iter != dummyIDs.end(); ++iter) {
          studentDummy.setID(*iter);
          if (studentTree.contains(studentDummy)) {
            cout << studentTree.find(studentDummy)->data << endl;
          }
          else{
            cout << "This faculty was read in from the table. Their advisee does not exist. Referential integrity could not be enforced." << endl;
            cout << "Recommendation: do #12 next to fix this issue" << endl;
          }

        }
      }
    }
    else if(choice == 7){

      //if no faculty exist
      if(!facultyTree.containsRoot()){
        cout << "\nThere are currently no advisors. please add a faculty before adding students.\n" << endl;
      }
      else{
        //prompt user for ID
        cout << "Please enter student ID: " << endl;
        cin >> studentID;
        while(cin.fail()){ //input checking
          cout << "Please enter a number for the student ID: " << endl;
          cin.clear();
          cin.ignore(256, '\n');
          cin >> studentID;
        } //prompt user for name
        cout << "Please enter student name: " << endl;
        cin >> studentName;
        //prompt user for level
        cout << "Please enter student level: " << endl;
        cin >> studentLevel;
        //prompt user for major
        cout << "Please enter student major: " << endl;
        cin >> studentMajor;
        //prompt user for GPA
        cout << "Please enter student GPA: " << endl; //check that enter a num
        cin >> studentGPA;
        while(cin.fail()){ //input checking
          cout << "Please enter a double for the student GPA: " << endl;
          cin.clear();
          cin.ignore(256, '\n');
          cin >> studentGPA;
        }
        //prompt user for advisor ID
        cout << "Please enter the students advisor ID: " << endl;
        cin >> studentAdvisorID;
        while(cin.fail()){ //input checking
          cout << "Please enter a number for the advisor ID: " << endl;
          cin.clear();
          cin.ignore(256, '\n');
          cin >> studentAdvisorID;
        }//set dummy object to check
        facultyDummy.setID(studentAdvisorID);

        while(!facultyTree.contains(facultyDummy)){ //need to check that advisor exists
          cout << "Please enter a valid student advisor ID: " << endl;
          cin >> studentAdvisorID;
          while(cin.fail()){ //input checking
            cout << "Please enter a number for the advisor ID: " << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> studentAdvisorID;
          }//set dummy object to check
          facultyDummy.setID(studentAdvisorID);
        }//add student to faculty advisee list
        facultyTree.find(facultyDummy)->data.adviseeIDs.push_back(studentID);

        //set dummy info from above
        studentDummy.setID(studentID);
        studentDummy.setName(studentName);
        studentDummy.setLevel(studentLevel);
        studentDummy.setMajor(studentMajor);
        studentDummy.setGPA(studentGPA);
        studentDummy.setAdvisorID(studentAdvisorID);
        //add the dummy object to the tree
        studentTree.insert(studentDummy);
      }
    }
    else if(choice == 8){

      //prompt user for ID
      cout << "Please enter a student ID to remove: " << endl;
      cin >> studentID;
      while(cin.fail()){ //input checking
        cout << "Please enter a number for the student ID: " << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> studentID;
      }
      studentDummy.setID(studentID); //student dummy object to see if a matching ID exists in the tree
      if (studentTree.contains(studentDummy)) {

        facultyID = studentTree.find(studentDummy)->data.getAdvisorID();
        facultyDummy.setID(facultyID); //faculty dummy object to see if a matching ID exists in the tree

        studentTree.deleteValue(studentDummy); //deletes the student

        facultyTree.find(facultyDummy)->data.adviseeIDs.remove(studentID); //removes the student from its advisor's list
      }
      else{
        cout << "Student ID could not be found in database." << endl;
      }
    }
    else if(choice == 9){

      //prompt user for ID
      cout << "Please enter faculty ID: " << endl;
      cin >> facultyID;
      while(cin.fail()){ //input checking
        cout << "Please enter a number for the faculty ID: " << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> facultyID;
      }//prompt user for name
      cout << "Please enter faculty name: " << endl;
      cin >> facultyName;
      //prompt user for level
      cout << "Please enter faculty level: " << endl;
      cin >> facultyLevel;
      //prompt user for department
      cout << "Please enter faculty department: " << endl;
      cin >> facultyDep;

      if(studentTree.containsRoot()){ //ask if the faculty has any advisees
        cout << "Does faculty have an current advisees? (y/n)" << endl;
        cin >> hasAdvisees;
      }


      while(hasAdvisees == "y"){ //if has advisees

        //prompt user for ID
        cout << "Please enter the advisee ID: " << endl;
        cin >> studentID;
        while(cin.fail()){ //input checking
          cout << "Please enter a number for the advisee ID: " << endl;
          cin.clear();
          cin.ignore(256, '\n');
          cin >> studentID;
        }
        studentDummy.setID(studentID); //student dummy object to see if a matching ID exists in the tree

        while(!studentTree.contains(studentDummy)){ //need to check that advisor exists
          cout << "Please enter a valid advisee ID: " << endl;
          cin >> studentID;
          while(cin.fail()){
            cout << "Please enter a number for the advisee ID: " << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> studentID;
          }
          studentDummy.setID(studentID); //student dummy object to see if a matching ID exists in the tree
        }

        studentTree.find(studentDummy)->data.setAdvisorID(facultyID); //sest new advisor ID

        facultyDummy.adviseeIDs.push_back(studentID); //add student to advisee list
        cout << "Does faculty have another current advisees? (y/n)" << endl;
        cin >> hasAdvisees;
      }

      //set faculty data
      facultyDummy.setID(facultyID);
      facultyDummy.setName(facultyName);
      facultyDummy.setLevel(facultyLevel);
      facultyDummy.setDepartment(facultyDep);

      //insert faculty into tree
      facultyTree.insert(facultyDummy);
    }
    else if(choice == 10){

      //prompt user for ID
      cout << "Please enter a faculty ID to remove: " << endl;
      cin >> facultyID;
      while(cin.fail()){ //input check
        cout << "Please enter a number for the faculty ID: " << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> facultyID;
      } // set faculty dummy object to see if faculty exists
      facultyDummy.setID(facultyID);
      if (facultyTree.contains(facultyDummy)) {

        dummyIDs = facultyTree.find(facultyDummy)->data.adviseeIDs; //gives dummyIDS the faculty advisee list
        if(dummyIDs.size() > 0) {
          cout << "You need to first reassign all the adviees to new advisors before deleteing the advisor" << endl;
        }
        else{
          facultyTree.deleteValue(facultyDummy);// delete faculty in database
        }
      }
      else{
        cout << "Faculty ID could not be found in database." << endl;
      }
    }
    else if(choice == 11){

      //prompt user for ID
      cout << "Please enter student ID: " << endl;
      cin >> studentID;
      while(cin.fail()){  //input check
        cout << "Please enter a number for the student ID: " << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> studentID;
      }//set student dummy object to see if it exist in database
      studentDummy.setID(studentID);

      if(studentTree.contains(studentDummy)){
        //set faculty dummy object to student advisor
        facultyDummy.setID(studentTree.find(studentDummy)->data.getAdvisorID());
        if(!facultyTree.contains(facultyDummy)){ //if the faculty doesn't exist
          cout << "Sorry but this advisor does not exist in the database" << endl;
        }
        else{ //if faculty exists
          facultyTree.find(facultyDummy)->data.adviseeIDs.remove(studentID);
          //get the current advisor
          int temp = studentTree.find(studentDummy)->data.getAdvisorID();
          //prompt user for ID
          cout << "Please enter the new faculty advisor ID:" << endl;
          cin >> studentAdvisorID;
          while(cin.fail()){//input check
            cout << "Please enter a number for the faculty advisor ID: " << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> studentAdvisorID;
          }//set faculty dummy object to student advisor
          facultyDummy.setID(studentAdvisorID);

          if(facultyTree.contains(facultyDummy)){ //if the new advisor exist
            //make them the new advisor for the student
            studentTree.find(studentDummy)->data.setAdvisorID(studentAdvisorID);
            facultyTree.find(facultyDummy)->data.adviseeIDs.push_back(studentID);
          }
          else{ //if they don't
            //keep the same advisor for the student
            facultyTree.find(facultyDummy)->data.adviseeIDs.push_back(studentID);
            studentTree.find(studentDummy)->data.setAdvisorID(temp);
            cout << "This faculty advisor does not exist in this database" << endl;
          }
        }
      }
      else{
        cout << "This student does not exist in this database" << endl;
      }
    }
    else if(choice == 12){
      //prompt user for ID
      cout << "Please enter the faculty ID: " << endl;
      cin >> facultyID;
      while(cin.fail()){ //input check
        cout << "Please enter a number for the faculty ID: " << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> facultyID;
      } //set faculty dummy object
      facultyDummy.setID(facultyID);
      //check if the faculty has any advisees
      if(facultyTree.contains(facultyDummy)){
        //if they do they can remove advisees
        if(facultyTree.find(facultyDummy)->data.adviseeIDs.size() > 0){
          //prompt user for ID
          cout << "Please enter the student ID to remove from advisee list: " << endl;
          cin >> studentID;
          while(cin.fail()){ //input check
            cout << "Please enter a number for the student ID: " << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> studentID;
          } //set student dummy
          studentDummy.setID(studentID);
          //if they both exist in the database
          if(facultyTree.contains(facultyDummy) && studentTree.contains(studentDummy)){
            if(studentTree.find(studentDummy)->data.getAdvisorID() == facultyID){ //accounts for trying to remove a student that has already been removed
              //remove student from advisee list
              facultyTree.find(facultyDummy)->data.adviseeIDs.remove(studentID);
              //reset the student advisor ID to -1 to show that they don't have one

              cout << "Please enter the student's new advisor:" << endl;
              cin >> facultyID;
              while(cin.fail()){ //input check
                cout << "Please enter a number for the faculty ID: " << endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin >> facultyID;
              } //set faculty dummy object
              facultyDummy.setID(facultyID);
              //check if the faculty exists in the database
              if(facultyTree.contains(facultyDummy)){
                //add the student to faculty advisee list
                facultyTree.find(facultyDummy)->data.adviseeIDs.push_back(studentID);
                //give the student a new advisor
                studentTree.find(studentDummy)->data.setAdvisorID(facultyID);
              }
              else{
                cout << "This faculty does not exist" << endl;
              }
            }
            else{
              cout << "This faculty is not the advisor for this student" << endl;
            }
          }
          else{
            cout << "This faculty advisor/student does not exist in this database" << endl;
          }
        }
        else{
          cout << "This faculty does not have any advisees" << endl;
        }
      }

    }
    else if(choice == 13){
      //prompt user for number of rollback
      cout << "How many commands would you like to rollback?" << endl;
      cin >> numRolls;
      while(cin.fail()){ //input check
        cout << "Please enter a number for the number of rollbacks: " << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> numRolls;
      }
      //need to check that numroll is less then 5
      if(numRolls > 5 || numRolls < 0){
        cout << "Invalid number of rollback please choose a number between 1 and 5." << endl;
        cout << "How many commands would you like to rollback?" << endl;
        cin >> numRolls;
        while(cin.fail()){ //input check
          cout << "Please enter a number for the number of rollbacks: " << endl;
          cin.clear();
          cin.ignore(256, '\n');
          cin >> numRolls;
        }
      }
      if(numRolls > studentList.size()){
        cout << "You have not made enough changes to the database to rollback to this number" << endl;
      }
      else{
        //removes numRolls of trees -1 from list
        for (int i = 0; i < numRolls; ++i) {
          studentList.pop_front();
          facultyList.pop_front();
        }
        //assigns appropriate tree from list to the current tree
        studentTree = studentList.front();
        facultyTree = facultyList.front();
        //remove that tree from the list
        studentList.pop_front();
        facultyList.pop_front();
      }
    }
    else if(choice == 14){ //Extra credit
      //prompt user for ID
      cout << "Please enter the student id:" << endl;
      cin >> studentID;
      while(cin.fail()){  //input check
        cout << "Please enter a number for the student ID: " << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> studentID;
      }
      //student dummy object to see if a matching ID exists in the tree
      studentDummy.setID(studentID);

      if(studentTree.contains(studentDummy)){
        cout << "Please enter the major you would like to change to" << endl;
        cin >> studentMajor;
        studentTree.find(studentDummy)->data.setMajor(studentMajor);
      }
    }
    else if(choice == 15){
      run = false;
      //writing to studentTable
      ofstream file;
      file.open("studentTable.txt");
      studentTree.processTree(studentTree.findRoot(), file);
      file.close();

      //writing to facultyTable
      file.open("facultyTable.txt");
      facultyTree.processTree(facultyTree.findRoot(), file);
      file.close();
    }
    else{
      cout << "\nERROR: Please enter a valid number \n" << endl;
    }

    if(choice > 6){
      //create dummy trees
      BST<Student> dummyStudentTree;
      BST<Faculty> dummyFacultyTree;
      //if dummyTrees are empty insert the root from respective current tree
      if(!dummyStudentTree.containsRoot()){
        dummyStudentTree.insert(studentDummy);
      }
      if(!dummyFacultyTree.containsRoot()){
        dummyFacultyTree.insert(facultyDummy);
      }
      //copy trees
      studentTree.copyTree(dummyStudentTree.findRoot());
      facultyTree.copyTree(dummyFacultyTree.findRoot());
      //add copyed tree to respective list
      studentList.push_front(dummyStudentTree);
      facultyList.push_front(dummyFacultyTree);
      //remove trees that are to old
      if(studentList.size() > 5){
        studentList.pop_back();
      }
      if(facultyList.size() > 5){
        facultyList.pop_back();
      }
    }
    else{
      cout << "This action did not change the Database" << endl;
    }
    //reset adviseeIDs
    facultyDummy.adviseeIDs.clear();
  }
}
