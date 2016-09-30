#include<iostream>
#include<cstring> // 使用memset初始化函数
#include<fstream>

using namespace std;

/*
 * 从1到n遍历每个页码，对每一个页码，统计每一位上的数字
 */
void solve(int n) {
    int num[10];
    memset(num, 0, sizeof(num)); // 数组num中的元素全部初始化为0

    for(int i=1; i<=n; i++) {
        int tmp = i;  //  tmp表示遍历过程中，当前的页码
        while(tmp) {  //  统计当前页码每一位上的数字
            num[tmp % 10]++;  // tmp对10取余，表示当前最低位的数字
            tmp /= 10;
        }
    }

    ofstream out("output.txt");
    for(int i=0; i<10; i++)
        out<< num[i] <<endl;
}

int main() {
    int n;
    ifstream in("input.txt");
    in>>n;
    solve(n);
    return 0;
}
