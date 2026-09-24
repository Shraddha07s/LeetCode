class Solution {
    public int buyChoco(int[] prices, int money) {
        int m=101,n=101;

        for(int i=0;i<prices.length;i++)
        {
            if(m>prices[i])
            {
                n = m;
                m = prices[i];
            }
            else if(n>prices[i])
            {
                n = prices[i];
            }
        }

        if(money-(m+n)>=0)
        {
            return money-(m+n);
        }
        return money;
    }
}