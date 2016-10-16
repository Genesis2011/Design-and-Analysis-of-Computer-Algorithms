#include<iostream>
#include<algorithm>
#include<fstream>
#define MAX 101
using namespace std;

int D[MAX][MAX];
int maxSum[MAX][MAX];

/*
 * D(r,j)����r�е�j�����֣�r��j��1��ʼ�㣩
 * MaxSum(r,j)����D(r,j)���ױߵĸ���·���У����·��������֮��
 *
 * D(r,j)��������һ��ֻ����D(r+1,j)����D(r+1,j+1)
 * ����N�е������Σ�
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
        maxSum[n][i] = D[n][i];  // ���һ�е����ֵ��Ϊ���ֱ���

    // ״̬ת�Ʒ��̣�masSum[i][j] = max(maxSum[i+1][j],maxSum[i+1][j+1]) + D[i][j]
    for(int i=n-1; i>=1; i--)
        for(int j=1; j<=i; j++)
            maxSum[i][j] = max(maxSum[i+1][j],maxSum[i+1][j+1]) + D[i][j];
    ofstream out("output.txt");
    out<<maxSum[1][1]<<endl;
    return 0;
}
