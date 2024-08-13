#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a[1000];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x;
        while(cin >> x){
            a[i].push_back(x);
            if (cin.peek() == '\n') break;
        }
    }
    vector<pair<int, int>> v;
    for(int i = 1; i <= n; i++){
        for(int j :a[i]){
            if(i < j){
                v.push_back(make_pair(i, j));
            }
        }
    }
    sort(v.begin(), v.end());
    for(auto& p : v){
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}