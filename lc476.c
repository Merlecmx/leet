int findComplement(int num)
{
    int mask = 1;
    int temp = num;
    while (temp > 0)
    {
        mask <<= 1;
        temp >>= 1;
    }
    return num ^ mask-1; 
}
