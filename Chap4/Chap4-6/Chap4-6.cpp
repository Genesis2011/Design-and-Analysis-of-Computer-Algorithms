#include<iostream>
#include<algorithm>
#include<fstream>
#include<cstdio>
using namespace std;

/*
 * ̰�Ĳ��ԣ���̷���ʱ������
 * ������Ŀ�����롢������ƶϳ�������ȴ�ʱ��ʱ��Ӧ�ð����ȴ�ʱ�������ʱ��
 */

int main() {
    int n;
    ifstream in("input.txt");
    in >> n;

    int * serve = new int [n];  // ��̬������n���˿͵ķ���ʱ��
    for(int i=0; i<n; i++)
        in >> serve[i];
    sort(serve,serve+n);  // ��������

    // ����ȴ�ʱ��
    double wait=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<=i ;j++)
            wait += serve[j];

    ofstream out("output.txt");
    out<<wait/n;

    delete []serve;  // �ͷ�����ռ�
    return 0;
}
