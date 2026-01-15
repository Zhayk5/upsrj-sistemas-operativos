#include <stdio.h>
#include <assert.h>

/* Include infrastructure from student code */
#include "../src/schdl/process.h"

/* Prototype of student implementation */
void rr_schedule(Process p[], int n, int quantum);

/* Load deterministic test data */
static void load_test_processes(Process p[], int *n)
{
    *n = 4;

    p[0] = (Process){ .id = 1, .arrival_time = 0, .burst_time = 5 };
    p[1] = (Process){ .id = 2, .arrival_time = 1, .burst_time = 3 };
    p[2] = (Process){ .id = 3, .arrival_time = 2, .burst_time = 1 };
    p[3] = (Process){ .id = 4, .arrival_time = 3, .burst_time = 2 };

    init_processes(p, *n);
}


/* Test RR correctness properties */
static void test_rr_properties(void)
{
    Process p[10];
    int n;
    const int quantum = 2;

    load_test_processes(p, &n);
    rr_schedule(p, n, quantum);

    for (int i = 0; i < n; i++) {

        /* Process must complete */
        assert(p[i].completed == 1);

        /* Turnaround definition */
        assert(
            p[i].turnaround_time ==
            (p[i].waiting_time + p[i].burst_time)
        );

        /* Waiting time cannot be negative */
        assert(p[i].waiting_time >= 0);

        /* Turnaround must be >= burst */
        assert(p[i].turnaround_time >= p[i].burst_time);
    }

    printf("[PASS] RR fundamental properties validated\n");
}

/* Optional: sanity check on total CPU time */
static void test_rr_cpu_time(void)
{
    Process p[10];
    int n;
    int total_burst = 0;
    int max_completion = 0;

    load_test_processes(p, &n);
    rr_schedule(p, n, 2);

    for (int i = 0; i < n; i++) {
        total_burst += p[i].burst_time;

        if (p[i].turnaround_time + p[i].arrival_time > max_completion) {
            max_completion =
                p[i].turnaround_time + p[i].arrival_time;
        }
    }

    /* CPU time must cover total burst */
    assert(max_completion >= total_burst);

    printf("[PASS] RR CPU time sanity check\n");
}

int main(void)
{
    test_rr_properties();
    test_rr_cpu_time();

    printf("\nAll RR tests passed successfully.\n");
    return 0;
}
