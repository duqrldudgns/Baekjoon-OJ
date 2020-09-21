/*

세자리 수의 끝 자리 수가 4인 경우는 앞의 자리수인 두자리 수의 끝 자리수가 3, 5인 경우만 도달 할 수 있음.
따라서 세자리 수의 끝자리 수가 4인 경우는 두자리 수의 끝자리 수가 3, 5인 경우의 합과 같음.

0의 경우에는 1만이, 9의 경우에는 8만이 접근이 가능하기 때문에 그 경우만 고려해줘서 계산하면 됨.


아래 정리한 표를 보면 규칙을 볼 수 있는데
예를들어 
(2,4)은 (1,3)과 (1,5)의 합과 같고
(3,5)는 (2,4)와 (2,6)의 합과 같다.


끝 자리 수 
     0  1  2  3  4  5  6  7  8  9 

1    0  1  1  1  1  1  1  1  1  1 
2    1  1  2  2  2  2  2  2  2  1 
3    1  3  3  4  4  4  4  4  3  2 
4    3  4  7  7  8  8  8  7  6  3
*/
#include <iostream>

#define MOD_NUM 1000000000

using namespace std;

int main(){
    int N, sum=0;
    int dp[100][10]={0,};

    cin >> N;

    for(int i=1; i<10; i++) dp[0][i]=1;

    for(int i=1; i<N; i++){
        for(int j=0;j<10;j++){
            if (j==0) dp[i][0] = dp[i-1][1];
            else if (j==9) dp[i][9] = dp[i-1][8];
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD_NUM;
        }
    }

    for(int i=0; i<10; i++) sum = (sum + dp[N-1][i]) % MOD_NUM;
    cout << sum;
    return 0;
}