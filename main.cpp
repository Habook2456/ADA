#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

void mochila(vector<vector<int>>& v, int n, int m){
    vector<int> b = {1,2,5};
    vector<int> p = {2,3,4};
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(j-p[i-1] < 0){
                v[i][j] = v[i-1][j];
            } else{
                v[i][j] = max(v[i-1][j], b[i-1] + v[i-1][j-p[i-1]]);
            }
            
        }
    }
}

int main(){
    int n = 3;
    int m = 6;
    vector<vector<int>> v(10,vector<int>(10,0));

    mochila(v, n, m);

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}