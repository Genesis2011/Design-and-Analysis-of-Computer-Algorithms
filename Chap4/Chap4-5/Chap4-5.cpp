#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;

/*
 * ̰���㷨���������ڴŴ��ϵĳ�����̵�����
 */

int main() {
    int n, L;
    ifstream in("input.txt");
    in >> n >> L;

    int * l = new int [n];  // ��̬������n���������ڴŴ��ϵĳ���

    for(int i=0; i<n; i++)
        in >> l[i];
    sort(l,l+n);  // ��������

    int sum=0, ant=0;
    // �ڲ������Ŵ����ȵ������£������ܶ�洢����
    for(int i=0; i<n; i++) {
        sum += l[i];
        if(sum<=L) ant++;
        else break;
    }
    ofstream out("output.txt");
    out<<ant<<endl;

    delete []l;  // �ͷ�����ռ�
    return 0;
}
