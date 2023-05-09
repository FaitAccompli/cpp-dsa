#include <iostream>

using namespace std;

int main()
{

    int numA = 11;
    int numB = numA;

    cout << "numA = " << numA << endl;
    cout << "numB = " << numB << endl;

    int *num1 = new int(11); // num1 basically contains the address pointing to the value of 11
    int *num2 = num1;        // num2 was given the address pointing to the value of 11 which makes them both point to 11

    cout << "num1 = " << *num1 << endl;
    cout << "num2 = " << *num2 << endl;
}