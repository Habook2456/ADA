#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int>> matrix)
{

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<vector<int>> multMatrix(vector<vector<int>> matrix1, vector<vector<int>> matrix2)
{
    int row1 = matrix1.size();
    int col1 = matrix1[0].size();
    int row2 = matrix2.size();
    int col2 = matrix2[0].size();
    vector<vector<int>> matrixResult(row1, vector<int>(col2, 0));

    int sum = 0;

    if (col1 != row2)
    {
        cout << "cannot multiply matrix" << endl;
        return matrixResult;
    }

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            for (int k = 0; k < col1; k++)
            {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            matrixResult[i][j] = sum;
            sum = 0;
        }
    }
    return matrixResult;
}

vector<vector<int>> sumMatrix(vector<vector<int>> matrix1, vector<vector<int>> matrix2)
{
    int rows = matrix1.size();
    int cols = matrix1[0].size();

    vector<vector<int>> result(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
}

vector<vector<int>> multStrassen(vector<vector<int>> matrix1, vector<vector<int>> matrix2)
{
    int n = matrix1.size();

    vector<vector<int>> matrixResult(n, vector<int>(n, 0));

    if (n == 1)
    {
        matrixResult[0][0] = matrix1[0][0] * matrix2[0][0];
    }
    else
    {
        vector<vector<int>> A11(n / 2, vector<int>(n / 2, 0));
        vector<vector<int>> A12(n / 2, vector<int>(n / 2, 0));
        vector<vector<int>> A21(n / 2, vector<int>(n / 2, 0));
        vector<vector<int>> A22(n / 2, vector<int>(n / 2, 0));

        vector<vector<int>> B11(n / 2, vector<int>(n / 2, 0));
        vector<vector<int>> B12(n / 2, vector<int>(n / 2, 0));
        vector<vector<int>> B21(n / 2, vector<int>(n / 2, 0));
        vector<vector<int>> B22(n / 2, vector<int>(n / 2, 0));

        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                A11[i][j] = matrix1[i][j];
                A12[i][j] = matrix1[i][j + n / 2];
                A21[i][j] = matrix1[i + n / 2][j];
                A22[i][j] = matrix1[i + n / 2][j + n / 2];

                B11[i][j] = matrix2[i][j];
                B12[i][j] = matrix2[i][j + n / 2];
                B21[i][j] = matrix2[i + n / 2][j];
                B22[i][j] = matrix2[i + n / 2][j + n / 2];
            }
        }

        vector<vector<int>> C11 = sumMatrix(multStrassen(A11, B11), multStrassen(A12, B21));
        vector<vector<int>> C12 = sumMatrix(multStrassen(A11, B12), multStrassen(A12, B22));
        vector<vector<int>> C21 = sumMatrix(multStrassen(A21, B11), multStrassen(A22, B21));
        vector<vector<int>> C22 = sumMatrix(multStrassen(A21, B12), multStrassen(A22, B22));

        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                matrixResult[i][j] = C11[i][j];
                matrixResult[i][j + n / 2] = C12[i][j];
                matrixResult[i + n / 2][j] = C21[i][j];
                matrixResult[i + n / 2][j + n / 2] = C22[i][j];
            }
        }
    }
    return matrixResult;
}

int main()
{

    vector<vector<int>> matrix1 = {{4, 7, 2, 8}, {9, 2, 8, 4}, {1, 7, 4, 3}, {5, 3, 2, 1}};

    vector<vector<int>> matrix2 = {{9, 6, 5, 3}, {8, 5, 1, 2}, {7, 5, 1, 4}, {6, 1, 8, 3}};

    vector<vector<int>> matrixResult;

    cout << "Multiplicacion Normal" << endl;
    matrixResult = multMatrix(matrix1, matrix2);
    printMatrix(matrixResult);

    cout << "Multiplicacion Strassen" << endl;
    matrixResult = multStrassen(matrix1, matrix2);
    printMatrix(matrixResult);

    return 0;
}