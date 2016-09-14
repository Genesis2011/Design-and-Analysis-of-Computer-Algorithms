#include<iostream>
#include<map>  // 使用map关联容器

using namespace std;

int main() {
    int n;
    cin>>n;

    map<int, int> num_count;  // map保存的每个元素中，每个输入的数是int类型，出现的次数是int类型
    /*
     * 读取每个数字，使用每个数字对num_count进行下标操作。
     * 如果tmp还未在map中，下标运算符会创建一个新元素，其关键字为tmp，值为0。
     * 不管元素是否是新创建的，其值加1。
     */
    for(int i=0; i<n; i++) {
        int tmp;
        cin>>tmp;
        ++num_count[tmp];
    }

    /*
     * 从map中提取元素时，会得到一个pair类型的对象。map使用的pair用first成员保存关键字，用second成员保存对应的值。
     * for循环遍历map，统计重数、众数
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
