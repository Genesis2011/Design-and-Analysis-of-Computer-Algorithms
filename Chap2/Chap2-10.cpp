#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;

    /*
     * �������ڱ�׼��ά�����⣬֪�����ǡ���������Catalan���������ɰ����㹫ʽ����
     * ����������һ���ʽΪ (2n)!/[(n+1)!*n!] �������� [2n*(2n-1)*...*(n+2)]/n!
     */
    long long a,b;
    a = b = 1;
    // ��һ���ʽ�ķ���
    for(int i=n+1; i<2*n; i++)
        a*=(i+1);
    // ��һ���ʽ�ķ�ĸ
    for(int i=0; i<n; i++)
        b*=(i+1);

    cout<<a/b<<endl;

    return 0;
}
