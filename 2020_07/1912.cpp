/*
연속합

문제
n개의 정수로 이루어진 임의의 수열이 주어진다. 우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다. 단, 수는 한 개 이상 선택해야 한다.

예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자. 여기서 정답은 12+21인 33이 정답이 된다.

입력
첫째 줄에 정수 n(1 ≤ n ≤ 100,000)이 주어지고 둘째 줄에는 n개의 정수로 이루어진 수열이 주어진다. 수는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다.

출력
첫째 줄에 답을 출력한다.

예제 입력 1 
10
10 -4 3 1 5 6 -35 12 21 -1
예제 출력 1 
33

예제 입력 2 
10
2 1 -4 3 4 -4 6 5 -5 1
예제 출력 2 
14

예제 입력 3 
5
-1 -2 -3 -4 -5
예제 출력 3 
-1
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n,save=0;

  cin >> n;
  int arr[n];
  int temp[n];

  for(int i=0;i<n;i++) cin >> arr[i];
  
  temp[0] = arr[0];
  save = temp[0];

  for(int i=1;i<n;i++){
    temp[i] = max(arr[i]+temp[i-1],arr[i]);
    save = max(save, temp[i]);
  }
  cout << save;

  return 0;
}
