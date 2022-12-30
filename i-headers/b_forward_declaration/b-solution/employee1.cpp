#include "employee1.h"

// important to see the complete implementation later
#include "department1.h"

Employee :: Employee(string name_)
{
    name = name_;
}
void Employee :: Print()
{
    cout << "I am " << name << "\n";
    cout << "I work in the following departments: \n";

    for (Department *d : deps)
        d->PrintDepartment();
}