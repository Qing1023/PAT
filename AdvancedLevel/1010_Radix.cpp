// 1010 Radix
// By Milkyway, 2019/6/2.
// It runs in O() in time and O(1) in space.
#include<iostream>
typedef long long LL;
using namespace std;

LL chtoDecimal(char ch){
    return ch <= '9' ? ch - '0' : ch - 'a' + 10;
}

LL strtoDecimal(string str, LL radix){
    LL decbase = 0;
    for(int i=0; i<str.length(); i++){
        decbase *= radix;
        decbase += chtoDecimal(str[i]);
        if(decbase < 0){
            return -1;
        }
    }
    return decbase;
}

LL findMinRadix(string str){
    LL minRadix = 2;
    for(int i=0; i<str.length(); i++){
        minRadix = max(minRadix, chtoDecimal(str[i]) + 1);
    }
    return minRadix;
}

LL findRadix(string str, LL base){
    LL l = findMinRadix(str), r = max(base, l); // attention: r = max(base, l);
    while(l <= r){
        LL mid = (l+r)>>1;
        LL temp = strtoDecimal(str, mid);
        if(base == temp){
            return mid;
        }else if(base < temp || temp == -1){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return 0;
}

int main(){
    string str1;
    string str2;
    LL tag, radixT;
    cin>>str1>>str2>>tag>>radixT;
    if(tag == 2){
        swap(str1, str2);
    }
    LL base = strtoDecimal(str1, radixT);
    LL radix = findRadix(str2, base);
    if(radix == 0){
        cout<<"Impossible";
    }else{
        cout<<radix;
    }
    return 0;
}
