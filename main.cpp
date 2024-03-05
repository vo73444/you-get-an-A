#include <iostream>
#include "gradebook.hpp"

using namespace std;

int main(){
    Gradebook gradebook;

    gradebook.addStudent("Bob Bobberson", "ABC123");
    gradebook.addStudent("Sam Sammerson", "DEF456");
    gradebook.addStudent("Jess Jesserson", "HIJ789");

    gradebook.addAssignment("Quiz 1", 100);
    gradebook.addAssignment("Lab 1", 50);

    gradebook.enterGrade("Sam Sammerson", "Quiz 1", 95);
    gradebook.enterGrade("Bob Bobberson", "Quiz 1", 85);
    gradebook.enterGrade("Jess Jesserson", "Lab 1", 49);
    gradebook.enterGrade("Jess Jesserson", "Quiz 1", 93);
    gradebook.enterGrade("Bob Bobberson", "Lab 1", 0);

    gradebook.report();

    return 0;
}
