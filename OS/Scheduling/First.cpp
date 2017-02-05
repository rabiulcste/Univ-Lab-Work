#include <bits//stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    cout << "First come, first-served scheduling\n";
    cout << "------------------------------------\n";
    int n;
    cout << "\nNumber of processe?\n";
    cin >> n;
    vector<int> t(n+1), s(n+1); // burst time
    string p[n+1]; //string p[10]

    cout << "\nInput process number and burst time\n";
    for(int i = 1; i <= n; i++) cin >> p[i] >> t[i];
    for(int i = 0; i <= n; i++) s[i] = 0;
    for(int i = 1; i <= n; i++) {
        s[i] = s[i-1] + t[i];
    }

    cout << "\nWaiting time for individual process\n";

    int tot_time = 0;
    for(int i = 1; i <= n; i++) {
        cout << p[i] << " = " <<  s[i-1] << endl;
        tot_time += s[i-1];
    }

    cout << "\nAverage Waiting time for all process = " << (tot_time+0.0)/n << "\n";

    return 0;
}
