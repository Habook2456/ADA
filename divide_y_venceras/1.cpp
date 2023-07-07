#include <iostream>
#include <vector>
using namespace std;
using std::cout;

bool MAYOR(int a, int b){
    return a > b;
}
bool MENOR(int a, int b){
    return a < b;
}

int partition(vector<int> &v, int start, int end, bool(* op)(int,int))
{
    int i = start + 1;
    int piv = v[start];
    for (int j = start + 1; j <= end; j++)
    {
        if (op(v[j], piv))
        {
            swap(v[i], v[j]);
            i += 1;
        }
    }
    swap(v[start], v[i - 1]);
    return i - 1;
}
void quickSort(vector<int> &v, int start, int end, bool(* op)(int,int))
{
    if (start < end)
    {
        int piv = partition(v, start, end, op);
        cout << "pivot_position: " << piv << endl;
        quickSort(v, start, piv, op);
        quickSort(v, piv + 1, end, op);
    }
}
void merge(vector<int> &v, int start, int mid, int end, bool(*op)(int,int))
{
    int p = start, q = mid + 1;
    vector<int> Arr(end - start + 1, 0);
    int k = 0;

    for (int i = start; i <= end; i++)
    {
        if (p > mid)
            Arr[k++] = v[q++];

        else if (q > end)
            Arr[k++] = v[p++];

        else if (op(v[p], v[q]))
            Arr[k++] = v[p++];

        else
            Arr[k++] = v[q++];
    }
    for (int p = 0; p < k; p++)
    {
        v[start++] = Arr[p];
    }
}

void mergeSort(vector<int> &v, int start, int end, bool(*op)(int,int))
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(v, start, mid, op);
        mergeSort(v, mid + 1, end, op);

        merge(v, start, mid, end, op);
    }
}

void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v = {9, 1, 3, 5, 0, 4, 2, 6, 8, 7};
    //quickSort(v, 0, v.size() - 1, MENOR);
    mergeSort(v, 0, v.size() - 1, MENOR);
    print(v);
    return 0;
}

/*

1. Ordene el siguiente vector de números enteros ( 9 1 3 5 0 4 2 6 8 7 )
a. ... utilizando el algoritmo Mergesort.
b. ... utilizando el algoritmo Quicksort.
c. ... de mayor a menor adaptando el algoritmo Mergesort.
d. ... de mayor a menor adaptando el algoritmo Quicksort.
*/