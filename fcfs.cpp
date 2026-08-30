#include <bits/stdc++.h>
using namespace std;
int main()
{
    int bt[50], wt[50], tt[50], n;
    float avg_tt, avg_wt;
    cout << "Enter No. of proccess: ";
    cin >> n;
    cout << "Enter burst time for every proccess" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << ": ";
        cin >> bt[i];
    }

    wt[0] = 0;
    tt[0] = bt[0];
    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tt[i] = wt[i] + bt[i];
    }
    cout << "Process\t" << "BT\t" << "WT\t" << "TT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "\t";
        cout << bt[i] << "\t";
        cout << wt[i] << "\t";
        cout << tt[i] << endl;
        avg_wt += wt[i];
        avg_tt += tt[i];
    }
    cout << "Average Waiting Time: " << avg_wt / n << endl;
    cout << "Average Turnaround TIme: " << avg_tt / n << endl;
   
    cout << "Gantt Chart" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "----------------";
    }
    cout << endl;
    cout << "|";
    for (int i = 0; i < n; i++)
    {
        cout << "\tP" << i + 1 << "\t|";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "----------------";
    }
    cout << endl;
    cout << "0\t";
    for (int i = 0; i < n; i++)
    {
        cout << "\t" << tt[i] << "\t";
    }
}