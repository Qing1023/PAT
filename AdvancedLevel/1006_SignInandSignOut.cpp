// 1006 Sign in and Sign out.
// By Milkyway, 2019/5/31.
// It runs in O(n) in time and O(n) in space, which n is M.
#include<iostream>

using namespace std;

const int M = 0x7fff;

string str[3];
int m;

bool lessThan(string str1, string str2){
    for(int i=0; i<str1.length(); i++){
        if(str1[i] < str2[i]){
            return true;
        }else if(str1[i] > str2[i]){
            return false;
        }
    }
}

int main(){
    cin>>m;
    string fp, lp;
    string unlockT, lockT;
    cin>>fp>>unlockT>>lockT;
    lp=fp;
    for(int i=1; i<m; i++){
        cin>>str[0]>>str[1]>>str[2];
        if(!lessThan(unlockT, str[1])){
            unlockT = str[1];
            fp = str[0];
        }
        if(lessThan(lockT, str[2])){
            lockT = str[2];
            lp = str[0];
        }
    }
    cout<<fp<<" "<<lp;
    return 0;
}
