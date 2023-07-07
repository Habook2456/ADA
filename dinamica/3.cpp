#include <iostream>
#include <vector>

using namespace std;

// Función para calcular la probabilidad de ganar el playoff (caso a)
double calcularProbabilidadA(int n, double P) {
    vector<vector<double>> dp(n + 1, vector<double>(n + 1));

    // Casos base
    dp[0][0] = 1.0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] * (1 - P);
        dp[0][i] = dp[0][i - 1] * P;
    }

    // Calcular la probabilidad usando la programación dinámica
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j] * (1 - P) + dp[i][j - 1] * P;
        }
    }

    return dp[n][n];
}

// Función para calcular la probabilidad de ganar el playoff con ventaja de campo (caso b)
double calcularProbabilidadB(int n, double PL, double PV) {
    vector<vector<double>> dp(n + 1, vector<double>(n + 1));

    // Casos base
    dp[0][0] = 1.0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] * PL;
        dp[0][i] = dp[0][i - 1] * PV;
    }

    // Calcular la probabilidad usando la programación dinámica
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j] * PL + dp[i][j - 1] * PV;
        }
    }

    return dp[n][n];
}

// Función para calcular la probabilidad considerando la intercalación de partidos (caso c)
double calcularProbabilidadC(int n, double PL, double PV) {
    vector<vector<double>> dp(n + 1, vector<double>(n + 1));

    // Casos base
    dp[0][0] = 1.0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] * PL;
        dp[0][i] = dp[0][i - 1] * PV;
    }

    // Calcular la probabilidad usando la programación dinámica
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i + j) % 2 == 1) {
                dp[i][j] = dp[i - 1][j] * PL + dp[i][j - 1] * PV;
            } else {
                dp[i][j] = dp[i - 1][j] * PV + dp[i][j - 1] * PL;
            }
        }
    }

    return dp[n][n];
}

int main() {
    int n = 10;
    double P = 0.5, PL = 0.7, PV = 0.3;
    

    cout << "a. Probabilidad de que Informáticos CB gane el playoff (caso a): "
         << calcularProbabilidadA(n, P) << endl;

    cout << "b. Influencia de la ventaja de campo: "
         << calcularProbabilidadB(n, PL, PV) << endl;

    cout << "c. Diferencia al intercalar partidos en casa y fuera: "
         << calcularProbabilidadC(n, PL, PV) << endl;

    return 0;
}

/*3. Problema del play-off:
Supongamos que dos equipos de baloncesto, Informáticos CB y Basket
Telecom, disputan un play-off que ganará el primero en conseguir n victorias
(esto es, tendrán que disputar, como mucho 2n-1 partidos):
a. Si suponemos que la probabilidad de que Informáticos CB gane un
partido concreto es un valor fijo P (p.ej. ½), calcule la probabilidad de
que Informáticos CB gane el playoff.
b. Si suponemos que la probabilidad de que un equipo gane un partido
concreto depende de si juega como equipo local o como visitante, siendo
PL la probabilidad de que gane el partido como local y PV la
probabilidad de que lo gane como visitante, con PL>PV, diseñe un
algoritmo que permita determinar la influencia que supone sobre el
resultado final el hecho de contar con ventaja de campo (esto es, jugar el
primer partido del play-off en casa).
c. ¿Hay alguna diferencia si se intercalan los partidos en casa y fuera con
respecto a jugar el primero en casa, los dos siguientes fuera, otros dos en
casa y así sucesivamente?
CONSEJO: Utilice P(i,j) para representar la probabilidad de que el primer equipo
gane el play-off si necesita ganar i partidos cuando el segundo equipo aún
tendría que ganar j partidos. Antes de comenzar el play-off, por tanto, la
probabilidad de que el primer equipo gane el play-off es P(n,n). */
