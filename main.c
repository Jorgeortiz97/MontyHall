#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define ITERATIONS  10000000


/**
 * Simulate a single round of the Monty Hall problem.
 * If `switch_mode` is set to `true`, the contestant
 * is always supposed to change his/her answer.
 * Return `true` if contestant chose the appropriate
 * option.
 */
bool simulate_monty_hall_round(bool switch_mode)
{
    // Correct option
    int correct_idx = rand() % 3;

    // Option selected by contestant
    int contestant_idx = rand() % 3;

    // Option that is revealed
    int wrong_idx = 0;

    // Remaining option
    int switch_idx = 0;

    if (switch_mode)
    {
        while (wrong_idx == correct_idx ||
                wrong_idx == contestant_idx)
            wrong_idx++;
        while (switch_idx == contestant_idx ||
                switch_idx == wrong_idx)
            switch_idx++;
        contestant_idx = switch_idx;
    }

    return correct_idx == contestant_idx;
}


int usage()
{
    printf("Usage: ./main < switch >\n"
            "    < switch > := false / true\n");
    return 1;
}


int main(int argc, char *argv[])
{
    bool switch_mode;
    unsigned long won_rounds = 0;
    float won_rounds_percentage;

    srand(time(NULL));

    if (argc != 2)
        return usage();

    if (strncmp(argv[1], "true", 4) == 0)
        switch_mode = true;
    else if (strncmp(argv[1], "false", 5) == 0)
        switch_mode = false;
    else
        return usage();


    printf("Starting simulation of the Monty Hall problem\n"
           ".........................................\n"
           "  - Switch mode:   %s\n"
           "  - #total_rounds: %d\n",
           switch_mode ? "true" : "false",
           ITERATIONS);

    for (unsigned int i = 0; i < ITERATIONS; i++)
        if (simulate_monty_hall_round(switch_mode))
            won_rounds++;

    won_rounds_percentage = 100 * (float) won_rounds / ITERATIONS;

    printf("  - #won_rounds:   %lu (%.2f%%)\n"
           ".........................................\n",
           won_rounds,
           won_rounds_percentage);

    return 0;
}