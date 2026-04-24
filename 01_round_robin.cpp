#include <iostream>
#include <queue>
using namespace std;
//큐를 쓰네

struct Process{
    int pid;
    int remainingTime;
};
//구조체


int main(){
    queue<Process> readyQueue;

    readyQueue.push({1, 5});
    readyQueue.push({2, 3});
    readyQueue.push({3, 7});
    //큐를 생성하고 구조체를 넣네

    int timeQuantum = 2;
    int currentTime = 0;
    //새로운 변수 생성. 지금 시간이랑 쪼갤수 있는 시간?

     while (!readyQueue.empty()) { //큐가 빌때까지
        Process p = readyQueue.front();
        readyQueue.pop();
        //fifo식으로 들어온거 맨 앞 프로세스 하나만 꺼냄

        cout << "[time " << currentTime << "] "
             << "Process " << p.pid << " 실행\n";
            //현재 실행상태 출력. 현재 시각. p.pid는 프로세스 이름


        if (p.remainingTime > timeQuantum) {
            p.remainingTime -= timeQuantum;
            currentTime += timeQuantum;
            //라운드로빈. 2 넘으면 바로 쪼개서 넘겨버림

            cout << "Process " << p.pid
                 << " 남은 시간: " << p.remainingTime << "\n";
                 //남은시간이 있으니 다시 뒤에 보냄

            readyQueue.push(p); //그리고 다시 뒤에 넣음
        } else {
            currentTime += p.remainingTime;

            cout << "Process " << p.pid
                 << " 종료 at time " << currentTime << "\n";
        }
    }//다 종료됐을때 얼마나 걸렸는지. 모든 프로세스가 종료될때까지 반복. 2초씩

    return 0;
}