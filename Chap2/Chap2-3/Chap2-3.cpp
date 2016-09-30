#include<iostream>
#include<fstream>
using namespace std;

/*
 * 先计当前数的半数集个数为1，再判断当前数是否大于1
 * 如果大于1，递归计算1~n/2间个数；否则，直接返回个数
 */
int set(int n) {
    int count = 1;
    if(n > 1)
        for(int i=1; i<=n/2; i++)
            count += set(i);
    return count;
}

int main() {
    int n;
    ifstream in("input.txt");
    in>>n;
    ofstream out("output.txt");
    out<<set(n)<<endl;
    return 0;
}
