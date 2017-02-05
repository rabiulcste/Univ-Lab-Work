#include <bits//stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    cout << "Shortest job first scheduling\n";
    cout << "------------------------------------\n";
    int n;
    cout << "\nNumber of processe?\n";
    cin >> n;
    pair<int, string> v[n+1]; // burst time n process name
    int s[n+1];
    cout << "\nInput process number and burst time\n";
    for(int i = 1; i <= n; i++)
    {
        string name;
        int time;
        cin >> name >> time;
        v[i].first = time, v[i].second = name;
    }

    sort(v+1, v+n+1);
    for(int i = 0; i <= n; i++) s[i] = 0;
    for(int i = 1; i <= n; i++) {
        s[i] = s[i-1] + v[i].first;
    }

    cout << "\nWaiting time for individual process\n";

    int tot_time = 0;
    for(int i = 1; i <= n; i++) {
        cout << v[i].second << " = " <<  s[i-1] << endl;
        tot_time += s[i-1];
    }

    cout << "\nAverage Waiting time for all process = " << (tot_time+0.0)/n << "\n";

    return 0;
}
