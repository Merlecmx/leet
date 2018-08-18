uint32_t reverseBits(uint32_t n)
{
    int count = 32;
    uint32_t result = n;
    while (n)
    {
        result = (result << 1) | (n & 1);
        n >>= 1;
        count--;
    }
    return result << count;
}
