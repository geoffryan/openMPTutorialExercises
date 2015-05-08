#include <stdio.h>
#include <omp.h>

static long num_steps = 100000000;
double step;

int main()
{
    int i;
    double pi;
    double sum = 0;
    double t1, t2;
    
    step = 1.0/((double) num_steps);

    t1 = omp_get_wtime();
    for(i=0; i<num_steps; i++)
    {
        double x = (i+0.5)*step;
        sum += 4.0/(1.0+x*x);
    }
    pi = step*sum;
    t2 = omp_get_wtime();

    printf("pi = %1.12f in %1.12f seconds\n", pi, t2-t1);

}
