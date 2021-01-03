#include<bits/stdc++.h>
using namespace std;

#define lli long long int
#define mod 1000000007

lli dp[1000001], inv[1000001];

string text, pattern;

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

void init(){
  inv[0] = 1;
  dp[0] = text[0]-'a'+1;
  lli p_power = 1;
  lli p = 31;

  for(int i=1;i<text.size();i++) {
    p_power = (p_power * p ) % mod;
    dp[i] = (dp[i-1] + (text[i]-'a'+1)*p_power) % mod;
    inv[i] = p_power % mod;
  }
}

lli matchHash(int start, int end) {
    lli result = dp[end];

    if(start>0) {
        result = (result - dp[start-1] + mod) % mod;
    }
    return result;
}

int main() {
	int testCases;
	cin >> testCases;
    while(testCases--) {
        cin.ignore();
        cin >> text >> pattern;
        lli hashInput = computeHash(pattern);
        init();
        bool found = false;
        vector<int> result;
        for(int start=0, end=pattern.size()-1;end<text.size();start++, end++) {
            lli tempHash = (hashInput * inv[start]) % mod;
            if(tempHash == matchHash(start, end)){
                found = true;
                result.push_back(start+1);
            }
        }
        if(!found)
            cout << "Not Found"<< endl;
        else {
            cout << result.size() << endl;
            for(auto occ:result) {
                cout << occ << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

