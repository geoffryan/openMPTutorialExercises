#include <stdio.h>
#include <omp.h>

static long num_steps = 100000000;
double step;

int main()
{
    double pi;
    double sum = 0;
    double t1, t2;
    
    step = 1.0/((double) num_steps);

    t1 = omp_get_wtime();

    #pragma omp parallel
    {
        int ID, N;
        long i, ia, ib;
        ID = omp_get_thread_num();
        N = omp_get_num_threads();
        ia = (ID*num_steps)/N;
        ib = ((ID+1)*num_steps)/N;
        double lsum = 0;

        for(i=ia; i<ib; i++)
        {
            double x = (i+0.5)*step;
            lsum += 4.0/(1.0+x*x);
        }

        #pragma omp atomic
            sum += lsum;
    }
    pi = step*sum;
    t2 = omp_get_wtime();

    printf("pi = %1.12f in %1.12f seconds\n", pi, t2-t1);
}
