#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;

/*
 * 贪心算法：程序存放在磁带上的长度最短的优先
 */

int main() {
    int n, L;
    ifstream in("input.txt");
    in >> n >> L;

    int * l = new int [n];  // 动态数组存放n个程序存放在磁带上的长度

    for(int i=0; i<n; i++)
        in >> l[i];
    sort(l,l+n);  // 升序排序

    int sum=0, ant=0;
    // 在不超过磁带长度的条件下，尽可能多存储程序
    for(int i=0; i<n; i++) {
        sum += l[i];
        if(sum<=L) ant++;
        else break;
    }
    ofstream out("output.txt");
    out<<ant<<endl;

    delete []l;  // 释放数组空间
    return 0;
}
