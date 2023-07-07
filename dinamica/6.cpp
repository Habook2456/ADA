#include <iostream>
#include <vector>

using namespace std;

bool checkExpression(const string& x) {
    int n = x.length();

    // Crear una matriz para almacenar los resultados de los subproblemas
    vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(3, false)));

    // Inicializar los casos base
    for (int i = 0; i < n; i++) {
        if (x[i] == 'a') dp[i][i][0] = true;
        if (x[i] == 'b') dp[i][i][1] = true;
        if (x[i] == 'c') dp[i][i][2] = true;
    }

    // Llenar la matriz dp
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
                if (dp[i][k][0] && dp[k + 1][j][0]) dp[i][j][0] = true;
                if (dp[i][k][0] && dp[k + 1][j][1]) dp[i][j][1] = true;
                if (dp[i][k][0] && dp[k + 1][j][2]) dp[i][j][2] = true;
                if (dp[i][k][1] && dp[k + 1][j][0]) dp[i][j][2] = true;
                if (dp[i][k][1] && dp[k + 1][j][1]) dp[i][j][1] = true;
                if (dp[i][k][1] && dp[k + 1][j][2]) dp[i][j][0] = true;
                if (dp[i][k][2] && dp[k + 1][j][0]) dp[i][j][0] = true;
                if (dp[i][k][2] && dp[k + 1][j][1]) dp[i][j][2] = true;
                if (dp[i][k][2] && dp[k + 1][j][2]) dp[i][j][2] = true;
            }
        }
    }

    // Si es posible poner paréntesis de manera que el valor sea 'a', devolver true
    if (dp[0][n - 1][0]) return true;

    return false;
}

int main() {
    string x;
    cout << "Ingrese la cadena de caracteres: ";
    cin >> x;

    if (checkExpression(x)) {
        cout << "Es posible poner paréntesis para obtener el valor 'a'." << endl;
    } else {
        cout << "No es posible poner paréntesis para obtener el valor 'a'." << endl;
    }

    return 0;
}

/*6. “Multiplicación” de símbolos:
Tenemos un alfabeto Σ = {a,b,c}. Los elementos de Σ tienen la siguiente regla de multiplicion
la regla de multiplicacion de caracteres es 
a*a = b
a*b = b
a*c = c
b*a = c
b*b = b
b*c = a
c*a = a
c*b = c
c*c =  c
Esto es, ab = b, ba = c, y así sucesivamente. Diseñe un algoritmo eficiente
basado en programación dinámica que examine una cadena de caracteres x =
x1x2 ... xn y decida si es posible o no poner paréntesis en x de tal manera que el
valor de la expresión resultante sea a. */