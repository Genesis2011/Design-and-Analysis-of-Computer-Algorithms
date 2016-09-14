#include<iostream>
#include<map>  // ʹ��map��������

using namespace std;

int main() {
    int n;
    cin>>n;

    map<int, int> num_count;  // map�����ÿ��Ԫ���У�ÿ�����������int���ͣ����ֵĴ�����int����
    /*
     * ��ȡÿ�����֣�ʹ��ÿ�����ֶ�num_count�����±������
     * ���tmp��δ��map�У��±�������ᴴ��һ����Ԫ�أ���ؼ���Ϊtmp��ֵΪ0��
     * ����Ԫ���Ƿ����´����ģ���ֵ��1��
     */
    for(int i=0; i<n; i++) {
        int tmp;
        cin>>tmp;
        ++num_count[tmp];
    }

    /*
     * ��map����ȡԪ��ʱ����õ�һ��pair���͵Ķ���mapʹ�õ�pair��first��Ա����ؼ��֣���second��Ա�����Ӧ��ֵ��
     * forѭ������map��ͳ������������
     */
    map <int, int>::iterator iter;
    int value, time;
    value = time = -1;
    for (iter = num_count.begin(); iter != num_count.end(); iter++) {
        time < iter->second ? time=iter->second,value=iter->first : 0 ;
    }

    cout<<value<<endl<<time<<endl;

    return 0;
}
