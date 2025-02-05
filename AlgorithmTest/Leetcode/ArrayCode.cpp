//
//  ArrayCode.cpp
//  AlgorithmTest
//
//  Created by pinky on 2024-09-14.
//

#include "ArrayCode.hpp"

#include <utility>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int maxProfit(vector<int>& prices) {
    int minprice = INT_MAX;
    int maxprofit = 0;
    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < minprice)
            minprice = prices[i];
        else if (prices[i] - minprice > maxprofit)
            maxprofit = prices[i] - minprice;
    }
    return maxprofit;
}

int getMin( vector<int>& prices, int p, int q )
{
    auto min_it = std::min_element(prices.begin() + p, prices.begin() + q + 1 );
    return *min_it;
}

int getMax( vector<int>& prices, int p, int q )
{
    auto max_it = std::max_element(prices.begin() + p, prices.begin() + q + 1 );
    return *max_it;
}

int maxProfit2( vector<int>& prices, int p, int q )
{
    if( p == q )
    {
        return 0;
    }

    int mid = (p + q)/2;

    int preMax = maxProfit2( prices, p, mid );
    int postMax = maxProfit2( prices, mid+1, q );

    int min = getMin( prices, p , mid );
    int max = getMax( prices, mid +1, q );

    int maxPro = std::max<int>( preMax, postMax);
    maxPro = std::max( maxPro, max > min ? max - min: 0  );
    return maxPro;
}
int maxProfit2(vector<int>& prices) {
    return maxProfit2( prices, 0, prices.size() -1 );
}
void testMaxProfit()
{
    std::vector<int> prices = { 5, 15, 1, 9 };
    
    int max = maxProfit( prices );
    int max2 = maxProfit2( prices );
    
    cout<<max<<"___"<<max2<<endl;
}

void testLeetcode()
{
    testMaxProfit();
}
