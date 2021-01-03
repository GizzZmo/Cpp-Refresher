#include<bits/stdc++.h>
using namespace std;

#define lli long long int
#define mod 1000000007

lli dp[1000001], inv[1000001];

string needle, haystack;

lli computeHash(string input) {
    int p = 31;
    lli p_power = 1;
    lli result = 0;

    for(auto ch: input) {
        result  = (result + (ch-'a'+1)*p_power) % mod;
        p_power = (p_power * p) % mod;
    }

    return result;
}

lli inverseMod(lli base, lli exponenet) {
    lli result =1 ;
    while(exponenet) {
        if(exponenet%2)
            result = (result * base) % mod;
        exponenet/=2;
        base = (base * base) % mod;
    }
    return result;
}

void init(){
  dp[0] = haystack[0]-'a'+1;
  lli p_power = 1;
  lli p = 31;

  for(int i=1;i<haystack.size();i++) {
    p_power = (p_power * p ) % mod;
    dp[i] = (dp[i-1] + (haystack[i]-'a'+1)*p_power) % mod;
    inv[i] = inverseMod(p_power,mod-2) % mod;
  }
}

lli matchHash(int start, int end) {
    lli result = dp[end];

    if(start>0) {
        result = (result - dp[start-1] + mod) % mod;
    }

    result = (result * inv[start] ) % mod;
    return result;
}

int main() {
	int needleLength;
    while(cin >> needleLength) {
        cin >> needle >> haystack;
        lli hashInput = computeHash(needle);
        init();
        for(int start=0, end=needle.size()-1;end<haystack.size();start++, end++) {
            if(hashInput == matchHash(start, end)){
                cout << start << endl;
            }
        }
        cout << endl;
    }
    return 0;
}

