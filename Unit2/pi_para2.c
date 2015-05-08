#include <stdio.h>
#include <omp.h>

static long num_steps = 100000000;
double step;

int main()
{
    double pi;
    double sum = 0;
    double t1, t2;
    int nthrd;
    
    step = 1.0/((double) num_steps);

    t1 = omp_get_wtime();

    double asum[16];

    #pragma omp parallel
    {
        int ID, N;
        long i;
        ID = omp_get_thread_num();
        N = omp_get_num_threads();

        if(ID == 0)
            nthrd = N;

        for(i=0; i<num_steps; i+=N)
        {
            double x = (i+0.5)*step;
            asum[ID] += 4.0/(1.0+x*x);
        }
    }

    pi = 0.0;
    int i;
    for(i=0; i<nthrd; i++)
        pi += step*asum[i];

    t2 = omp_get_wtime();

    printf("pi = %1.12f in %1.12f seconds\n", pi, t2-t1);

}
