#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v={1,2,32,533,64, -56,12,-1,3};
    sort(v.begin(), v.end(), [=](int a, int b){return a > b;});
    for(auto var : v) {
        cout<< var << endl;
    }
    return 0;
}
