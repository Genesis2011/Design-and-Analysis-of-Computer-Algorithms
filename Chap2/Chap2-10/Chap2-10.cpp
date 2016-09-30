#include<iostream>
#include<fstream>
using namespace std;

int main() {
    int n;
    ifstream in("input.txt");
    in>>n;

    /*
     * 搜索关于标准二维表问题，知这题是“卡特兰（Catalan）数”，可按计算公式来做
     * 卡特兰数的一般项公式为 (2n)!/[(n+1)!*n!] ，化简后得 [2n*(2n-1)*...*(n+2)]/n!
     */
    long long a,b;
    a = b = 1;
    // 求一般项公式的分子
    for(int i=n+1; i<2*n; i++)
        a*=(i+1);
    // 求一般项公式的分母
    for(int i=0; i<n; i++)
        b*=(i+1);

    ofstream out("output.txt");
    out<<a/b<<endl;

    return 0;
}
