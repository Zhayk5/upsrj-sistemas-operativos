#include <stdio.h>
#include <stdbool.h>
#include "process.h"

#define MAX 100

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    Process p[MAX];
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    read_processes(p, n);
    init_processes(p, n);

    int quantum;
    printf("Enter quantum: ");
    scanf("%d", &quantum);

    int queue[MAX];
    int front = 0, rear = 0;

    bool in_queue[MAX] = { false };

    int current_time = 0;
    int finished = 0;

    while (finished < n) {

        /* Agregar procesos que ya llegaron */
        for (int i = 0; i < n; i++) {
            if (!in_queue[i] &&
                !p[i].completed &&
                p[i].arrival_time <= current_time) {

                queue[rear++] = i;
                in_queue[i] = true;
            }
        }

        /* CPU ociosa */
        if (front == rear) {
            current_time++;
            continue;
        }

        int idx = queue[front++];

        int exec_time = min(quantum, p[idx].remaining_time);
        p[idx].remaining_time -= exec_time;
        current_time += exec_time;

        /* Revisar arrivals durante la ejecución */
        for (int i = 0; i < n; i++) {
            if (!in_queue[i] &&
                !p[i].completed &&
                p[i].arrival_time <= current_time) {

                queue[rear++] = i;
                in_queue[i] = true;
            }
        }

        if (p[idx].remaining_time == 0) {
            p[idx].completed = 1;
            finished++;

            p[idx].turnaround_time =
                current_time - p[idx].arrival_time;
            p[idx].waiting_time =
                p[idx].turnaround_time - p[idx].burst_time;
        } else {
            queue[rear++] = idx; // vuelve al final
        }
    }

    print_results(p, n, "Round Robin (Arrival Time)");

    return 0;
}
