#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;

int N, M;
int arr[8] = {0,};
vi v;
bool visited[8] = {false,};

void solve(int cnt){

    if( cnt == M ){
        for(int i=0; i<M; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    int check = 0;
    
    for(int i=0; i<N; i++){
        
        if( v[i] != check){
           // visited[i] = true;
            arr[cnt] = v[i];

            check = arr[cnt];
            
            solve(cnt + 1);
        //    visited[i] = false;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    v.resize(N);  // 필수
    for(int i=0; i<N; i++) cin >> v[i];

    sort(all(v));

    solve(0);
}