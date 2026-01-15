#include <stdio.h>
#include <assert.h>

/* Include infrastructure from student code */
#include "../src/schdl/process.h"

/* Prototype of student implementation */
void fcfs_schedule(Process p[], int n);

/* Load deterministic test data */
static void load_test_processes(Process p[], int *n)
{
    *n = 4;

    p[0] = (Process){ .id = 1, .arrival_time = 2, .burst_time = 4 };
    p[1] = (Process){ .id = 2, .arrival_time = 0, .burst_time = 3 };
    p[2] = (Process){ .id = 3, .arrival_time = 1, .burst_time = 2 };
    p[3] = (Process){ .id = 4, .arrival_time = 2, .burst_time = 1 };

    init_processes(p, *n);
}

/* Test FCFS process ordering */
static void test_fcfs_order(void)
{
    Process p[10];
    int n;

    load_test_processes(p, &n);
    fcfs_schedule(p, n);

    /* FCFS must be stable (arrival_time, then ID) */
    assert(p[0].id == 2); /* AT = 0 */
    assert(p[1].id == 3); /* AT = 1 */
    assert(p[2].id == 1); /* AT = 2 */
    assert(p[3].id == 4); /* AT = 2 */

    printf("[PASS] FCFS order validation\n");
}

/* Test FCFS timing calculations */
static void test_fcfs_timing(void)
{
    Process p[10];
    int n;

    load_test_processes(p, &n);
    fcfs_schedule(p, n);

    assert(p[0].waiting_time == 0); /* ID 2 */
    assert(p[1].waiting_time == 2); /* ID 3 */
    assert(p[2].waiting_time == 3); /* ID 1 */
    assert(p[3].waiting_time == 7); /* ID 4 */

    assert(p[0].turnaround_time == 3);
    assert(p[1].turnaround_time == 4);
    assert(p[2].turnaround_time == 7);
    assert(p[3].turnaround_time == 8);

    printf("[PASS] FCFS timing validation\n");
}

int main(void)
{
    test_fcfs_order();
    test_fcfs_timing();

    printf("\nAll FCFS tests passed successfully.\n");
    return 0;
}
