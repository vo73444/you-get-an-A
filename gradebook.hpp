#include <iostream>
#include <vector>

class Gradebook{

    std::vector<std::vector<std::string> > student_list;
    std::vector<std::string> assignments;
    std::vector<int> grades;

    public:

    Gradebook();

    void addStudent(std::string stuName, std::string stuId);

    void addAssignment(std::string assignmentName, int grade);

    void enterGrade(std::string stuName, std::string assignmentName, int grade);

    void report();

};
