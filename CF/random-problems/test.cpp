#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef long double ld;
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define inf 1e15+5
const int mod = 1e9+7;

string printBinary(int n){
	int bits = 0;
	int temp = n;
	string result;
	while(temp != 0){
		bits++;
		temp >>= 1;
	}
	for(int i = bits - 1; i >= 0; i--){
		int k = n >> i;
		if(k&1){
			result += '1';
		}
		else result += '0';;
	}
	return result;
}

int mostSF(int n){
	int k = __builtin_clz(n);
	return (32 - k);
}

int fact(int n){
	int ans = 1;
	for(int i = 1; i <= n; i++) ans *= i;
	return ans;
}

int ncr(int n, int r){
	return fact(n) / fact(r) * fact(n-r);
}

bool is_sorted(vector<int>& a){
	int n = a.size();
	for(int i = 0; i + 1 < n; i++){
		if(a[i] > a[i+1]) return 0;
	}
	return 1;
}

int md(int n){
	if(n < 0){
		return ((n % mod) + mod) % mod;
	}
	return n % mod;
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> mat(n, vector<int>(n)); //it just takes on taking input on local device
		//did you make anything of it?
		//infinite here's
		// no idea why
		//this should be no
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }    
        bool ok = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1 && i + 1 < n && j + 1 < n){
                    if(mat[i+1][j] == 1 || mat[i][j+1] == 1) continue;
					else{ 
						cout << i << " " << j << endl;
						ok = 0;
						break;
					}
                }
				if(!ok) break;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}


