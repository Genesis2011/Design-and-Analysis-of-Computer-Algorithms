#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

/* �ݹ�ʽ��
 * i==0 j==0ʱ��d(i,j)=0
 * i==0 j>0ʱ��d(i,j)=j
 * i>0 j==0ʱ��d(i,j)=i
 * i>=1 j>=1 A[i]==B[j]ʱ��d(i,j)= min{ d(i-1,j)+1,d(i,j-1)+1,d(i-1,j-1) }
 * i>=1 j>=1 A[i]!=B[j]ʱ��d(i,j)= min{ d(i-1,j)+1,d(i,j-1)+1,d(i-1,j-1)+1 }
 */

int main() {
    string A,B;
    ifstream in("input.txt");
    in >> A >> B;

    vector<vector<int> > d(A.length()+1,vector<int>(B.length()+1));  // ��STL�е�vector��̬���ٶ�ά����

    // i==0 j==0��d(i,j)=0
    d[0][0] = 0;
    // i>0 j==0��d(i,j)=i
    for(int i=1; i<=A.length(); i++)
        d[i][0] = i;
    // i==0 j>0��d(i,j)=j
    for(int i=1; i<=B.length(); i++)
        d[0][i] = i;
    // i>=1 j>=1 A[i]==B[j]ʱ��d(i,j)= min{ d(i-1,j)+1,d(i,j-1)+1,d(i-1,j-1) }
    // i>=1 j>=1 A[i]!=B[j]ʱ��d(i,j)= min{ d(i-1,j)+1,d(i,j-1)+1,d(i-1,j-1)+1 }
    for(int i=1; i<=A.length(); i++)
        for(int j=1; j<=B.length(); j++)
            A[i-1] == B[j-1] ? d[i][j] = min(min(d[i-1][j]+1,d[i][j-1]+1),d[i-1][j-1]) : d[i][j] = min(min(d[i-1][j]+1,d[i][j-1]+1),d[i-1][j-1]+1);

    ofstream out("output.txt");
    out<<d[A.length()][B.length()];

    return 0;
}
