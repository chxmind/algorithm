/**
 * 最大乘积
 * 有一个整数n，将n分解成若干个不同自然数之和，问如何分解能使这些数的乘积最大，输出这个乘积m
 * 
 */

long max_product(int number)
{
    long result = 1;
    while (number > 0)
    {
        if (number > 3 || number == 2)
        {
            number -=2;
            result *= 2;
        }
        else if (number == 3)
        {
            number -=3;
            result *= 3;
        }
    }

    return result;
}