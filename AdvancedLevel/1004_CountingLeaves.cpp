// 1004 Counting Leaves
// By Milkyway, 2019/5/31.
#include<iostream>
#include<cstring>
using namespace std;

const int N = 100 + 5;
int num[N]; // a array to the number of each layer's non-leaf nodes in trees

int tree[N][N];
int maxDepth=0;

int transNum(string str){
    // transform string into number
    int number = (str[0] - '0') * 10 + (str[1] - '0'); // attention: when trans str into number, we need minus '0'
    return number;
}

void dfs(int depth, int next){
    int sign = 0;
    for(int i = 0; i < N; i++){
        if(tree[next][i] == 1){
            dfs(depth+1, i);
            sign = 1;
        }
    }
    if(sign == 0){
        num[depth]++;
    }
    maxDepth = max(depth, maxDepth);
}

int main(){
    int n, m;
    cin>>n>>m;
    fill(tree[0], tree[0] + N*N, 0);
    fill(num, num + N, 0);
    while(m--){
        string str;
        cin>>str;
        int fa = transNum(str);
        int numofSon;
        cin>>numofSon;
        while(numofSon--){
            string str1;
            cin>>str1;
            int son = transNum(str1);
            tree[fa][son] = 1;
        }
    }
    dfs(1, 1);
    cout<<num[1];
    for(int i = 2; i <= maxDepth; i++)
        cout<<" "<<num[i];
    return 0;
}
