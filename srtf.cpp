#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter Number of Process: ";
    cin >> n;
    int at[n], bt[n], wt[n], tat[n], ct[n], rem[n];
    vector<int> gantt, gant_time;
    cout << "Enter Arrival Time: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << ": ";
        cin >> at[i];
    }

    cout << "Enter Burst Time: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << ": ";
        cin >> bt[i];
        rem[i] = bt[i];
    }

    int time = 0;
    int completed = 0;
    while (completed < n)
    {
        int shortest = -1;
        int min = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (at[i] <= time && rem[i] > 0 && rem[i] < min)
            {
                min = rem[i];
                shortest = i;
            }
        }
        if (shortest == -1)
        {
            time++;
        }
        else
        {
            gantt.push_back(shortest);
            rem[shortest]--;
            time++;
            gant_time.push_back(time);
            if (rem[shortest] == 0)
            {
                completed++;
                ct[shortest] = time;
                tat[shortest] = ct[shortest] - at[shortest];
                wt[shortest] = tat[shortest] - bt[shortest];
            }
        }
    }
    cout << "Process\t" << "BT\t" << "CT\t" << "WT\t" << "TAT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "\t" << bt[i] << "\t" << ct[i] << "\t" << wt[i] << "\t" << tat[i] << "\t" << endl;
    }

    cout << "Gantt Chart" << endl;
    cout << "|";
    for (int i = 0; i < gantt.size(); i++)
    {
        cout << "  P" << gantt[i] + 1 << "\t|";
    }
    cout << endl;
    cout << "0\t";
    for (int i = 0; i < gant_time.size(); i++)
    {
        cout << gant_time[i] << "\t";
    }
}