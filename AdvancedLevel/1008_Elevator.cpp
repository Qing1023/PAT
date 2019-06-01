// 1008 Elevator
// By Milkyway, 2019/6/1.
// It runs in O(n) in time and O(1) in space, which n is N in problem.
#include<iostream>
#include<string>

using namespace std;

int main(){
    int n;
    cin>>n;
    int pre;
    cin>>pre;
    n--;
    int sum = pre*6 + 5;
    while(n--){
        int temp;
        cin>>temp;
        if(temp > pre){
            sum += (temp - pre)*6;
        }else{
            sum += (pre - temp)*4;
        }
        sum += 5;
        pre = temp;
    }
    cout<<sum;
    return 0;
}
