#include <omp.h>
#include <stdio.h>

void main()
{
    printf("Adding Vector into Scalar\n");
    int a1[] = {1, 2, 3, 4, 5};
    int answer = 0;
	int i;
	#pragma omp parallel
    for (i = 0; i < 5; i++)
    {
        answer += a1[i];
    }
    printf("Answer %d ", answer);
}
