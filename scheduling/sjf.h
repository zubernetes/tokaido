// sjf.h
//
// CPU scheduling simulation. This header contains
// operations to simulate a Shortest Job First
// (SJF) CPU scheduling algorithm.
// 2016 (c) zubernetes
#ifndef SJF_H
#define SJF_H

#include "pcb.h"
#include "ready_queue.h"

int operateSJF(std::queue<PCB*>);

int operateSJF(std::queue<PCB*> q) {
    // Declare CPU object variables
    int workComplete = 0, 
        process      = 0, 
        arrivalTime  = 0,
        burstTime    = 0,
        systemTime   = 0,
        wait_time    = 0;

    // Simulation CPU activity until there
    // are no more processes in the ready queue.
    while(!q.empty()) {
        struct timeval wait_start, wait_stop;
        wait_start.tv_usec = 0, wait_stop.tv_usec = 0;
        gettimeofday(&wait_start, NULL);

        process     = q.front()->getProcessID();
        arrivalTime = q.front()->getArrivalTime();
        burstTime   = q.front()->getBurstSize();

        while(workComplete < burstTime) { 
            std::cout << "<system time " << systemTime << "> process " <<
               process << " is runnning" << std::endl;
            workComplete++;
            systemTime++;
            if (workComplete == burstTime) {
                std::cout << "<system time " << systemTime << "> process " <<
                   process << " is finished......." << std::endl;
            }
        }

        gettimeofday(&wait_stop, NULL);
        wait_time = ((wait_stop.tv_sec - wait_start.tv_sec) * 1000000 +
            wait_stop.tv_usec - wait_start.tv_usec);
        q.pop();
        workComplete = 0;
    }
    std::cout << "<system time " << systemTime << "> All processes " <<
       "finish...................." << std::endl;
    return wait_time;
}

#endif
