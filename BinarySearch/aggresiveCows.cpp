#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int maxn = 1e6 + 5;
int n, c, arr[maxn];

int getNextIndex(int value) {
    int low = 0, high = n-1, ans = n;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(arr[mid] >= value) {
            ans = mid;
            high = mid - 1;
        } else
            low = mid + 1;
    }
    return ans;
}

bool isValid(int mid) {
    int cnt = 0, index = 0;
    while(index < n) {
        cnt += 1;
        int nextValue = arr[index] + mid;
        index = getNextIndex(nextValue);
    }
    return cnt >= c;
}

int getMaxDistance() {
    int low = 0, high = 1e9, ans = 0;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(isValid(mid)) {
            ans = mid;
            low = mid + 1;
        } else 
            high = mid - 1;
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;cin>>t;
    while(t--) {
        cin>>n>>c;
        for(int i=0; i<n; i++) {
            cin>>arr[i];
        }
        sort(arr, arr + n);
        cout<<getMaxDistance()<<endl;
    }
    return 0;
}