
#ifndef DEPARTMENT_H_
#define DEPARTMENT_H_

//!error because the two files include each other
#include "employee.h" 
struct Department
{

    string name;
    vector<Employee> deps;

    void PrintDepartment()
    {
    }
};
#endif
