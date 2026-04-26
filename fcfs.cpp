#include <iostream>
#include <vector>
using namespace std;

struct Process {
    int pid;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};

int main(){
    vector<Process> processes ={
        {1,5,0,0},
        {2, 3, 0, 0},
        {3, 7, 0, 0}
    };

    int n = processes.size();

    processes[0].waitingTime =0;

    for(int i =1; i<n; i++){
        processes[i].waitingTime=
            processes[i-1].waitingTime+
            processes[i-1].burstTime;
    }


    for(int i=0; i<n; i++){
        processes[i].turnaroundTime=
            processes[i].waitingTime+
            processes[i].burstTime;
    }

    cout << "PID\tBT\tWT\tTAT\n";

    for (auto p: processes){
        cout << p.pid << "\t"
             << p.burstTime << "\t"
             <<p.waitingTime<< "\t"
             << p.turnaroundTime << "\n";
    }

    return 0;

}