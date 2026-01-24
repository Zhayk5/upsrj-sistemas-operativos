#include <stdio.h>
#include <limits.h>
#include "process.h"

/* ============================================================
 * Student implementation area
 * ============================================================ */
void sjf_schedule(Process p[], int n)
{
    int current_time = 0;
    int completed = 0;

    while (completed < n) {
        int idx = -1;
        int min_burst = INT_MAX;

        /* Buscar el proceso disponible con menor burst time */
        for (int i = 0; i < n; i++) {
            if (!p[i].finished &&
                p[i].arrival_time <= current_time &&
                p[i].burst_time < min_burst) {

                min_burst = p[i].burst_time;
                idx = i;
            }
        }

        /* Si no hay proceso disponible, la CPU queda ociosa */
        if (idx == -1) {
            current_time++;
            continue;
        }

        /* Calcular tiempos */
        p[idx].waiting_time = current_time - p[idx].arrival_time;
        current_time += p[idx].burst_time;
        p[idx].turnaround_time = p[idx].waiting_time + p[idx].burst_time;

        /* Marcar como terminado */
        p[idx].finished = 1;
        completed++;
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

    sjf_schedule(p, n);

    print_results(p, n, "SJF Scheduling");
    return 0;
}
#endif
