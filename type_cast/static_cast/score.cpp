#include <stdio.h>

int main(void)
{
    int kor, eng, mat;
    scanf("%d %d %d", &kor, &eng, &mat);
    
    int sum;
    double average;
    sum = kor + eng + mat;
    average = static_cast<double> (sum) / 3;

    printf("sum : %d\tarverate: %.2f\n", sum, average);

    return 0;
}