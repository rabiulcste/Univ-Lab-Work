#include <bits//stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    cout << "Round-Robin scheduling\n";
    cout << "------------------------------------\n";
    int n, time_slice;
    cout << "\nNumber of processe?\n";
    cin >> n;

    int t[n+1]; // burst time
    string p[n+1]; //string p[10]
    int s[100]; // waiting counter
    string an[100]; // process counter

    cout << "\nInput process number and burst time\n";
    for(int i = 1; i <= n; i++) cin >> p[i] >> t[i];

    cout << "\nInput time slice\n";
    cin >> time_slice;

    for(int i = 0; i < 100; i++) s[i] = 0;

    int loop = 1;
    while(1) {
        bool f = 0;
        for(int i = 1; i <= n; i++)
        {
             if(t[i]) {
                if(t[i] >= time_slice) {
                    s[loop] = s[loop-1] + time_slice;
                    t[i] -= time_slice;
                }
                else {
                    s[loop] = s[loop-1] + t[i];
                    t[i] = 0;
                }
                f = 1;
                an[loop] = p[i];
                loop++;
             }
        }
        if(!f) break;

    }

    cout << "\nWaiting time for individual process\n";

    int tot_time = 0;
    map<string, int> cur;
    for(int i = 1; i < loop; i++) {
        cout << an[i] << " = " <<  s[i-1] << "\n";

        if(an[i] != an[i-1]) {
            tot_time += s[i-1];
            if(cur[an[i]]) tot_time -= cur[an[i]];
            if(i == 0) cur[an[i]] = s[i];
            else cur[an[i]] +=  s[i] - s[i-1];
        }
    }

    cout << "\nAverage Waiting time for all process = " << (tot_time+0.0)/n << "\n";

    return 0;
}
