#include <stdio.h>
#include "process.h"

/* ============================================================
 * Student implementation area
 * ============================================================ */
void rr_schedule(Process p[], int n, int quantum)
{
    int current_time = 0;
    int completed_count = 0;

    int queue[n];
    int front = 0, rear = 0;

    int in_queue[n];
    for (int i = 0; i < n; i++) {
        in_queue[i] = 0;
    }

    Process result[n];
    int res_idx = 0;

    while (completed_count < n) {

        /* Agregar procesos que ya llegaron */
        for (int i = 0; i < n; i++) {
            if (!p[i].completed &&
                !in_queue[i] &&
                p[i].arrival_time <= current_time) {

                queue[rear++] = i;
                in_queue[i] = 1;
            }
        }

        /* CPU ociosa */
        if (front == rear) {
            current_time++;
            continue;
        }

        int idx = queue[front++];

        int exec_time =
            (p[idx].remaining_time < quantum)
                ? p[idx].remaining_time
                : quantum;

        p[idx].remaining_time -= exec_time;
        current_time += exec_time;

        /* Revisar nuevos arrivals durante la ejecución */
        for (int i = 0; i < n; i++) {
            if (!p[i].completed &&
                !in_queue[i] &&
                p[i].arrival_time <= current_time) {

                queue[rear++] = i;
                in_queue[i] = 1;
            }
        }

        if (p[idx].remaining_time == 0) {
            p[idx].completed = 1;
            completed_count++;

            p[idx].turnaround_time =
                current_time - p[idx].arrival_time;
            p[idx].waiting_time =
                p[idx].turnaround_time - p[idx].burst_time;

            result[res_idx++] = p[idx];
        } else {
            queue[rear++] = idx;
        }
    }

    /* Reordenar p[] según finalización */
    for (int i = 0; i < n; i++) {
        p[i] = result[i];
    }
}

/* ============================================================
 * DO NOT MODIFY MAIN
 * ============================================================ */
#ifndef UNIT_TEST
int main(void)
{
    int n;
    printf("Número de procesos: ");
    scanf("%d", &n);

    Process p[n];
    read_processes(p, n);
    init_processes(p, n);

    int quantum;
    printf("Quantum: ");
    scanf("%d", &quantum);

    rr_schedule(p, n, quantum);

    print_results(p, n, "Round Robin Scheduling");
    return 0;
}
#endif
