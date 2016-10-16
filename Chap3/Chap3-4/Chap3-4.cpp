#include<iostream>
#include<algorithm>
#include<fstream>
#define MAX 101
using namespace std;

int D[MAX][MAX];
int maxSum[MAX][MAX];

/*
 * D(r,j)：第r行第j个数字（r，j从1开始算）
 * MaxSum(r,j)：从D(r,j)到底边的各条路径中，最佳路径的数字之和
 *
 * D(r,j)出发，下一步只能走D(r+1,j)或者D(r+1,j+1)
 * 对于N行的三角形：
 * if(r == N)
 *     MaxSum(r,j) = D(r,j)
 * else
 *     MaxSum(r,j) = Max{ MaxSum(r+1,j), MaxSum(r+1,j+1) } + D(r,j)
 */

int main(){
    int n;
    ifstream in("input.txt");
    in>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=i; j++)
            in>>D[i][j];
    for(int i=1; i<=n; i++)
        maxSum[n][i] = D[n][i];  // 最后一行的最大值即为数字本身

    // 状态转移方程：masSum[i][j] = max(maxSum[i+1][j],maxSum[i+1][j+1]) + D[i][j]
    for(int i=n-1; i>=1; i--)
        for(int j=1; j<=i; j++)
            maxSum[i][j] = max(maxSum[i+1][j],maxSum[i+1][j+1]) + D[i][j];
    ofstream out("output.txt");
    out<<maxSum[1][1]<<endl;
    return 0;
}
