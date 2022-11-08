#include<omp.h>
#include<bits/stdc++.h>
using namespace std;
static int sum =0;
int main()
{
    #pragma omp parallel for
    for(int i=1; i<=100;i++)
    {
        printf("thread No. %d Number : %d Square : %d\n", omp_get_thread_num(), i, i * i);  
        sum+=i*i;
        printf("Sum is %d \n",sum);        
	}
    printf("%d",sum);
    return 0;
}

