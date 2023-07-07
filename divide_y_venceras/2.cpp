#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <bitset>
using namespace std;
using std::cout;

string karatsuba(string num1, string num2)
{

    if (stoi(num1) < 10 || stoi(num2) < 10)
    {
        return to_string(stoi(num1) * stoi(num2));
    }

    int m = max(num1.size(), num2.size());
    int m2 = floor(m / 2.0);

    string high1 = num1.substr(0, num1.length() - m2);
    string low1 = num1.substr(num1.length() - m2);
    string high2 = num2.substr(0, num2.length() - m2);
    string low2 = num2.substr(num2.length() - m2);

    string _z0 = karatsuba(low1, low2);
    string _z1 = karatsuba(to_string(stoi(low1) + stoi(high1)), to_string(stoi(low2) + stoi(high2)));
    string _z2 = karatsuba(high1, high2);

    string result = to_string(stoi(_z2) * pow(10, (m2 * 2)) + ((stoi(_z1) - stoi(_z2) - stoi(_z0)) * pow(10, m2)) + stoi(_z0));
    return result;
}

string karatsubaBinary(string num1, string num2)
{
    num1 = to_string(stoi(num1, 0, 2));
    num2 = to_string(stoi(num2, 0, 2));

    if (stoi(num1) < 10 || stoi(num2) < 10)
    {
        return to_string(stoi(num1) * stoi(num2));
    }

    int m = max(num1.size(), num2.size());
    int m2 = floor(m / 2.0);

    string high1 = num1.substr(0, num1.length() - m2);
    string low1 = num1.substr(num1.length() - m2);
    string high2 = num2.substr(0, num2.length() - m2);
    string low2 = num2.substr(num2.length() - m2);

    string _z0 = karatsuba(low1, low2);
    string _z1 = karatsuba(to_string(stoi(low1) + stoi(high1)), to_string(stoi(low2) + stoi(high2)));
    string _z2 = karatsuba(high1, high2);

    string result = to_string(stoi(_z2) * pow(10, (m2 * 2)) + ((stoi(_z1) - stoi(_z2) - stoi(_z0)) * pow(10, m2)) + stoi(_z0));
    int tamBin = (int)(log2(stoi(result)));
    cout << tamBin << endl;
    result = bitset<64>(stoi(result)).to_string().substr(64-tamBin-1);
    return result;
}

int main()
{

    string x = "1823";
    string y = "1241";
    string _x = "10011011"; // 155
    string _y = "10111010"; // 186
    cout << karatsubaBinary(_x, _y) << endl;
    // cout << stoi(x)*stoi(y) << endl;

    return 0;
}

/*


2. Modifique el algoritmo "divide y vencerás" para la multiplicación de grandes
enteros de forma que permita multiplicar números en binario. Ilustre el
funcionamiento del algoritmo a la hora de multiplicar los siguientes enteros:
A = 10011011 y B = 10111010.



*/