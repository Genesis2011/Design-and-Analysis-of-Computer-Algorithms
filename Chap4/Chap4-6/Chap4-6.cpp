#include<iostream>
#include<algorithm>
#include<fstream>
#include<cstdio>
using namespace std;

/*
 * 贪心策略：最短服务时间优先
 * 根据题目的输入、输出可推断出，计算等待时间时，应该包括等待时间与服务时间
 */

int main() {
    int n;
    ifstream in("input.txt");
    in >> n;

    int * serve = new int [n];  // 动态数组存放n个顾客的服务时间
    for(int i=0; i<n; i++)
        in >> serve[i];
    sort(serve,serve+n);  // 升序排序

    // 计算等待时间
    double wait=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<=i ;j++)
            wait += serve[j];

    ofstream out("output.txt");
    out<<wait/n;

    delete []serve;  // 释放数组空间
    return 0;
}
