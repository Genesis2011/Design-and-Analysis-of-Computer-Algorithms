#include<iostream>
#include<fstream>
using namespace std;

/*
 * �ȼƵ�ǰ���İ���������Ϊ1�����жϵ�ǰ���Ƿ����1
 * �������1���ݹ����1~n/2�����������ֱ�ӷ��ظ���
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
