
#ifndef EMPLOYEE1_H_
#define EMPLOYEE1_H_

#include <iostream>
#include <vector>
using namespace std;
//! error because the two files include each other
// #include "department1.h" //?remove this

//?forward_declaration
struct Department;

struct Employee
{

    string name;
    vector<Department*> deps; // notice must be pointer to not important implement it now


    // Declare
    Employee(string name_);
    void Print();
};

#endif