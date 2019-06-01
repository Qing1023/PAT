// 1007 Maximum Subsequence Sum
// By Milkyway, 2019/6/1.
// It runs in O(n) in time and O(n) in space, which n is K in problem.
#include<iostream>

using namespace std;

const int N = 1e4;

int A[N+5];

int main(){
    int k;
    cin>>k;
    int start, last;
    long long subSum=0, subMaxSum=-1;
    int temS=0, temL=-1;
    for(int i=0; i<k; i++){
        int temp;
        cin>>temp;
        A[i] = temp;
        subSum += temp;
        temL++;
        if(subSum < 0){
            subSum = 0;
            temS = i+1;
            temL = i;
        }else{
            if(subSum > subMaxSum){
                subMaxSum = subSum;
                start = temS;
                last = temL;
            }
        }
        //cout<<subSum<<" "<<temS<<" "<<temL<<" "<<start<<" "<<last<<endl;
    }
    if(subMaxSum >= 0){
        cout<<subMaxSum<<" "<<A[start]<<" "<<A[last];
    }else{
        cout<<0<<" "<<A[0]<<" "<<A[k-1];
    }
    return 0;
}
