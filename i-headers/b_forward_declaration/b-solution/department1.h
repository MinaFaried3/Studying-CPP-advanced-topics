
#ifndef DEPARTMENT1_H_
#define DEPARTMENT1_H_

//! error because the two files include each other
#include "employee1.h"
struct Department
{

    string name;
    vector<Employee> deps;

    void PrintDepartment()
    {
    }
};
#endif
