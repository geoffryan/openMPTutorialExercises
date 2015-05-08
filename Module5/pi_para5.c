#include <stdio.h>
#include <omp.h>

static long num_steps = 100000000;

int main()
{
    double pi;
    double t1, t2;
    
    t1 = omp_get_wtime();
    double step = 1.0/((double) num_steps);
    double sum;
    long i;

    #pragma omp parallel for schedule(auto) reduction(+:sum)
    for(i=0; i<num_steps; i++)
    {
        double x = (i+0.5)*step;
        sum += 4.0/(1.0+x*x);
    }

    pi = step*sum;

    t2 = omp_get_wtime();

    printf("pi = %1.12f in %1.12f seconds\n", pi, t2-t1);
}
