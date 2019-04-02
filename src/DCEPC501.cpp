/*Let's get high :D*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define M_PI                3.14159265358979323846

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

const int MAXN = 1e5+5;
ll arr[MAXN];
ll dp[MAXN];

ll solve(int idx){
	if(idx < 0)
		return 0;
	if(dp[idx] != -1)
		return dp[idx];
	ll ans = 0;
	ans = max(ans, arr[idx] + solve(idx-2));
	if(idx-1 >= 0)
		ans = max(ans, arr[idx] + arr[idx-1] + solve(idx-4));
	if(idx-2 >= 0)
		ans = max(ans, arr[idx] + arr[idx-1] + arr[idx-2] + solve(idx-6));
	// ans = max(ans, solve(idx-1));
	dp[idx] = ans;
	return ans;
}

int main(){
    io;
    int t;
    cin >> t;
    while(t--){
    	memset(dp, -1, sizeof dp);
    	int n;
    	cin >> n;
    	for(int i = 0; i < n; i++)
    		cin >> arr[i];
    	int l = 0, r = n-1;
    	while(l < r){
    		int temp = arr[l];
    		arr[l] = arr[r];
    		arr[r] = temp;
    		l++;
    		r--;
    	}
    	cout << solve(n-1) << endl;
    }
    return 0;
}