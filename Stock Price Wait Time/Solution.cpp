#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m;
    vector<int> stocks, days;
    stack<int> stockIndex;
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> m;
        stocks.push_back(m);
        days.push_back(0);
    }
    
    for(int i = 0; i < n; i++){
        while(!stockIndex.empty() && stocks[stockIndex.top()] < stocks[i]){
            int top = stockIndex.top(); stockIndex.pop();
            days[top] = i - top;
        }
        stockIndex.push(i);
    }
    
    for(int i: days){
        cout << i << " ";
    }
    
    return 0;
}
