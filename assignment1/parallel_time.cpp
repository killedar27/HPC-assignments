#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

static int sum =0;
int main(int argc, char *argv[])
{
    double itime, ftime, exec_time;
    itime = omp_get_wtime();
    //#pragma omp parallel
        for(int i=1; i<=100;i++)
        {
            if(i%4==omp_get_thread_num())
            {
                printf("\nThread No. %d Number : %d Square : %d", omp_get_thread_num(), i, i * i);  
                sum+=i*i;
            }
        }
        printf("\n\nSum is %d",sum);
        cout << endl;
        ftime = omp_get_wtime();
        exec_time = (ftime - itime);
        printf("\nTime taken is %f\n", exec_time);
    return 0;
}