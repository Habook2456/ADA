#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool puedeObtenerValorA(const string& x) {
    int n = x.length();
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    // Inicializar la diagonal principal como verdadera
    for (int i = 0; i < n; i++) {
        if (x[i] == 'a') {
            dp[i][i] = true;
        }
    }

    // Calcular dp[i][j] para subcadenas de longitud 2 hasta n
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;

            // Verificar si es posible obtener "a" a partir de las subcadenas x[i...k] y x[k+1...j]
            for (int k = i; k < j; k++) {
                if (dp[i][k] && dp[k + 1][j]) {
                    // Verificar las reglas de multiplicación para los caracteres en x[k] y x[k+1]
                    if ((x[k] == 'a' && x[k + 1] == 'b') ||
                        (x[k] == 'b' && x[k + 1] == 'a') ||
                        (x[k] == 'c' && x[k + 1] == 'c')) {
                        dp[i][j] = true;
                        break;
                    }
                }
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    string x;
    cout << "Ingrese la cadena de caracteres x: ";
    cin >> x;

    bool esPosible = puedeObtenerValorA(x);

    if (esPosible) {
        cout << "Es posible poner paréntesis en x de tal manera que el valor de la expresión resultante sea 'a'." << endl;
    } else {
        cout << "No es posible poner paréntesis en x de tal manera que el valor de la expresión resultante sea 'a'." << endl;
    }

    return 0;
}

/*6. “Multiplicación” de símbolos:
Tenemos un alfabeto Σ = {a,b,c}. Los elementos de Σ tienen la siguiente tabla de
multiplicación, donde las filas muestran primer operando y las columnas
muestran el segundo operando de la multiplicación de símbolos:
 a b c
a b b a
b c b a
c a c c
Esto es, ab = b, ba = c, y así sucesivamente. Diseñe un algoritmo eficiente
basado en programación dinámica que examine una cadena de caracteres x =
x1x2 ... xn y decida si es posible o no poner paréntesis en x de tal manera que el
valor de la expresión resultante sea a. */