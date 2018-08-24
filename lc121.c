int maxProfit(int* prices, int pricesSize)
{
    int max = 0;
    int min_pri = prices[0];
    for (int i = 1;i < pricesSize;i++)
    {
        if (prices[i] < min_pri)
            min_pri = prices[i];
        if (prices[i] - min_pri > max)
            max = prices[i] - min_pri;
    }
    return max;
}
