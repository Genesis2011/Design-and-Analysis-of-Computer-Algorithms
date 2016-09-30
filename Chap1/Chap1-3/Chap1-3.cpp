#include<iostream>
#include<fstream>

using namespace std;

/*
 * 求x~y间每个数的约数个数
 */
void factor(int cnt[], int x, int y) {
    for(int i=x-1; i<y; i++) {  // 从x~y，逐个计算每个数的约数个数
        int j=0;
        // j从0到当前数i（j+1表示从1到i+1,i+1等于y），逐个判断i+1能否整除j+1
        do {
            if( (i+1)%(j+1)==0 )
                cnt[i]++;
            j++;
        } while(j<=i);
    }
}

/*
 * 统计a~b间的约数最多的数，并返回其约数个数
 */
int max_factor(int cnt[], int x, int y) {
    int div=0;
    for(int i=x-1; i<y; i++) {
        if(div < cnt[i])
            div = cnt[i];
    }
    return div;
}

int main() {
    int a,b;
    ifstream in("input.txt");
    in>>a>>b;

    int *count = new int[b];  // 申请b个元素的数组count，用于统计a~b之间数的约数个数
    for(int i=0; i<b; i++) {  // 数组count所有元素初始化为0
        count[i] = 0;
    }

    ofstream out("output.txt");
    factor(count, a, b);  // 求a~b间每个数的约数个数
    out<<max_factor(count, a, b)<<endl;  // 查询a~b间约数个数最大值并输出

    delete []count;  // 释放数组count的空间

    return 0;
}
