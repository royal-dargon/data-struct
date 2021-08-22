#include <stdio.h>
#include <time.h>

clock_t start, stop;
double duration;

int main()
{
    start = clock();
    Myfunction();
    stop = clock();
    duration = ((double)(stop-start))/CLOCKS_PER_SEC;

    return 0;
}