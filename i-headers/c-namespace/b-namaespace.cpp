
#include <iostream>
namespace OurSystem
{
    namespace Customer
    {
        int limit = 1;
    }

    namespace Admin
    {
        int limit = 10;

    }
}
// ++17 simplifies nested namespace
namespace OurSystem1::Customer1
{
    int limit = 10;
}

int main()
{

    std::cout << OurSystem::Customer::limit << "\n";
    std::cout << OurSystem1::Customer1::limit << "\n";

    namespace scope = OurSystem::Customer; // alias
    std::cout << scope::limit << "\n ";
}
