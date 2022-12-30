
#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iostream>
#include <vector>
using namespace std;
//!error because the two files include each other
#include "department.h"

struct Employee
{

    string name;
    vector<Department *> deps;

    // Declare
    Employee(string name_);
    void Print();
};

#endif