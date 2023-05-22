#include <iostream>
#include <vector>

using namespace std;

int potencia(int base, int exponent)
{
    int result = 1;
    for (int i = 1; i <= exponent; i++)
    {
        result *= base;
    }
    return result;
}

int potenciaRecursive(int base, int exponent)
{

    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;

    int result = potencia(base, exponent / 2);
    result *= result;

    if (exponent % 2 == 1)
        result *= base;

    return result;
}

int main()
{
    cout << potencia(2, 6) << endl;
    cout << potenciaRecursive(2, 6) << endl;
    return 0;
}