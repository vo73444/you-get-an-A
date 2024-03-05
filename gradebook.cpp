#include "gradebook.hpp"

#include <iostream>
#include <string>


using namespace std;

Gradebook::Gradebook(){
      student_list.push_back(vector<string>());

      student_list[0].push_back("Last_Name");
      student_list[0].push_back("First_Name");
      student_list[0].push_back("Student_Id");
  }

void Gradebook::addStudent(string stuName, string stuId){
        int index = stuName.find(" ");

        string firstName = stuName.substr(0, index);

        string lastName = stuName.substr((index + 1));

        student_list.push_back(vector<string>());

        student_list[student_list.size() - 1].push_back(lastName);
        student_list[student_list.size() - 1].push_back(firstName);
        student_list[student_list.size() - 1].push_back(stuId);
    }

void Gradebook::addAssignment(string assignmentName, int grade){
    assignments.push_back(assignmentName);
    grades.push_back(grade);

    for(int i = 1; i < student_list.size(); i++){
        student_list[i].push_back("N/A");
    }

}

void Gradebook::enterGrade(string stuName, string assignmentName, int grade){
    int stuIndex = -1;
    int assignmentIndex = -1;
    for(int i = 0; i < student_list.size(); i++){
        string name = student_list[i][1] + " " + student_list[i][0];

        if(name == stuName){
            stuIndex = i;
            
        }
        
    }

    for(int i = 0; i < assignments.size(); i++){
        
        if(assignmentName == assignments[i]){
            assignmentIndex = i;
            
        }
    }

    if(grade > grades[assignmentIndex] || grade < 0 || stuIndex == -1 || assignmentIndex == -1){
        return;
    }

    student_list[stuIndex][assignmentIndex + 3] = to_string(grade);
    
}

void Gradebook::report(){
    string report = "\n" + student_list[0][0];
    for(int i = 1; i < student_list[0].size(); i++){
        report = report + "," + student_list[0][i];
    }
    
    for(int i = 0; i < assignments.size(); i++){
        report = report +  "," + assignments[i];

    }

    report += "\n";

    for(int i = 1; i < student_list.size(); i++){
        report = report + student_list[i][0];
        
        for(int j = 1; j < student_list[i].size(); j++){
            report = report + "," + student_list[i][j];
        }

        report += "\n";
    }

    cout << report << "\n";
}
