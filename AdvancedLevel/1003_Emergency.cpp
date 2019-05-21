#include<iostream>
#include<string>
using namespace std;

const int N = 500+3;
int Map[N][N]; // adjMatrix
int preNum[N]; // the number of previous city of i-th city

int main(){
    int n, m, curIn, save;
    cin>>n>>curIn>>save;
    int teamNum[N];
    for(int i = 0; i < n; i++){
        cin>>teamNum[i];
    }
    memset(Map, Map + n*n, 0);
    for(int i = 0; i < m; i++){
        int c1, c2, len;
        cin>>c1>>c2>>len;
        Map[c1][c2] = Map[c2][c1] = len;
    }
}
