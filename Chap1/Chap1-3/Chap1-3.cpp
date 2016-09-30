#include<iostream>
#include<fstream>

using namespace std;

/*
 * ��x~y��ÿ������Լ������
 */
void factor(int cnt[], int x, int y) {
    for(int i=x-1; i<y; i++) {  // ��x~y���������ÿ������Լ������
        int j=0;
        // j��0����ǰ��i��j+1��ʾ��1��i+1,i+1����y��������ж�i+1�ܷ�����j+1
        do {
            if( (i+1)%(j+1)==0 )
                cnt[i]++;
            j++;
        } while(j<=i);
    }
}

/*
 * ͳ��a~b���Լ������������������Լ������
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

    int *count = new int[b];  // ����b��Ԫ�ص�����count������ͳ��a~b֮������Լ������
    for(int i=0; i<b; i++) {  // ����count����Ԫ�س�ʼ��Ϊ0
        count[i] = 0;
    }

    ofstream out("output.txt");
    factor(count, a, b);  // ��a~b��ÿ������Լ������
    out<<max_factor(count, a, b)<<endl;  // ��ѯa~b��Լ���������ֵ�����

    delete []count;  // �ͷ�����count�Ŀռ�

    return 0;
}
