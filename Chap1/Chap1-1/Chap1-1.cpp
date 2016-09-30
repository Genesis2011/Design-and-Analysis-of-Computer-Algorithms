#include<iostream>
#include<cstring> // ʹ��memset��ʼ������
#include<fstream>

using namespace std;

/*
 * ��1��n����ÿ��ҳ�룬��ÿһ��ҳ�룬ͳ��ÿһλ�ϵ�����
 */
void solve(int n) {
    int num[10];
    memset(num, 0, sizeof(num)); // ����num�е�Ԫ��ȫ����ʼ��Ϊ0

    for(int i=1; i<=n; i++) {
        int tmp = i;  //  tmp��ʾ���������У���ǰ��ҳ��
        while(tmp) {  //  ͳ�Ƶ�ǰҳ��ÿһλ�ϵ�����
            num[tmp % 10]++;  // tmp��10ȡ�࣬��ʾ��ǰ���λ������
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
