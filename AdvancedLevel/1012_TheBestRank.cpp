/* 1012 The Best Rank
 * By Milkyway, 2019/6/5.
 * It runs in O(3*nlogn + n*m) in time and O(n) in space.
 */
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 2e3 + 3;
char course[4] = {'A', 'C', 'M', 'E'};
struct student{
    int name;
    int grade;
    bool operator < (const student &stu) const{
        return grade > stu.grade ? true : false;
    }
}ACME[4][N];
int n, m;

void inputData(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        int name, sum=0;
        cin>>name>>ACME[1][i].grade>>ACME[2][i].grade>>ACME[3][i].grade;
        for(int j=0; j<4; j++){
            ACME[j][i].name = name;
            sum += ACME[j][i].grade;
        }
        ACME[0][i].grade = sum/3;
    }
}

void findStuMaxRank(int stuName){
    int i=0, j=0;
    for(i=1; i<=n;){
        int jump = N;
        for(j=0; j<4; j++){
            int k = i;
            while(ACME[j][i].grade == ACME[j][k].grade && k<=n){
                if(ACME[j][k].name == stuName){
                    goto next;
                }
                k++;
            }
            jump = min(k, jump);
        }
        i = jump;
    }
    next:
        if(i != n + 1){
            cout<<i<<" "<<course[j]<<endl;
        }else{
            cout<<"N/A"<<endl;
        }
}

int main(){
    inputData();
    for(int i=0; i<4; i++){
        sort(ACME[i] + 1, ACME[i] + n + 1);
    }
    while(m--){
        int stuName;
        cin>>stuName;
        findStuMaxRank(stuName);
    }
    return 0;
}
