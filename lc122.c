int maxProfit(int* prices, int pricesSize)
{
    int sum = 0;
    int min_pri = prices[0];
    int i = 1,j;
    for (i = 1;i < pricesSize;i++)
    {
        if (prices[i] <= prices[i-1])
        {
            min_pri = prices[i];
            continue;
        }
        while (prices[i] > prices[i-1] && i < pricesSize)
            i++;
        sum += prices[i-1] - min_pri;
        min_pri = prices[i];
    }
    return sum;
}
