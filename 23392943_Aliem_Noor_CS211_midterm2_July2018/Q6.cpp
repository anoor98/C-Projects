#include <iostream>
#include <string>
using namespace std;

class Math{
    public:
        static double const pi;
        static double const root2;
// etc
};
double const Math::pi = 3.1416;
double const Math::root2 = 1.4142;

int main() {
    cout << Math::pi << endl;
    cout << Math::root2 << endl;
    return 0;  
}
