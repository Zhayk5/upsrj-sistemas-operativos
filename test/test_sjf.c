#include <stdio.h>
#include <assert.h>

/* Include infrastructure from student code */
#include "../src/schdl/process.h"

/* Prototype of student implementation */
void sjf_schedule(Process p[], int n);

/* Load deterministic test data */
static void load_test_processes(Process p[], int *n)
{
    *n = 4;

    /*
     * ID | AT | BT
     *  1 |  0 |  7
     *  2 |  2 |  4
     *  3 |  4 |  1
     *  4 |  5 |  2
     */
    p[0] = (Process){ .id = 1, .arrival_time = 0, .burst_time = 7 };
    p[1] = (Process){ .id = 2, .arrival_time = 2, .burst_time = 4 };
    p[2] = (Process){ .id = 3, .arrival_time = 4, .burst_time = 1 };
    p[3] = (Process){ .id = 4, .arrival_time = 5, .burst_time = 2 };

    init_processes(p, *n);
}

/* Test SJF ordering and timing */
static void test_sjf_behavior(void)
{
    Process p[10];
    int n;

    load_test_processes(p, &n);
    sjf_schedule(p, n);

    /*
     * Expected behavior:
     *
     * t=0   P1 (only available)
     * t=7   P3 (shortest among P2,P3,P4)
     * t=8   P4
     * t=10  P2
     */

    /* Validate execution order */
    assert(p[0].id == 1);
    assert(p[1].id == 3);
    assert(p[2].id == 4);
    assert(p[3].id == 2);

    /* Validate waiting times */
    assert(p[0].waiting_time == 0);  /* P1 */
    assert(p[1].waiting_time == 3);  /* P3: 7 - 4 */
    assert(p[2].waiting_time == 3);  /* P4: 8 - 5 */
    assert(p[3].waiting_time == 8);  /* P2: 10 - 2 */

    /* Validate turnaround times */
    assert(p[0].turnaround_time == 7);
    assert(p[1].turnaround_time == 4);
    assert(p[2].turnaround_time == 5);
    assert(p[3].turnaround_time == 12);

    printf("[PASS] SJF behavior validated\n");
}

int main(void)
{
    test_sjf_behavior();

    printf("\nAll SJF tests passed successfully.\n");
    return 0;
}
