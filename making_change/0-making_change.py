#!/usr/bin/python3
"""module makechange
"""


def makeChange(coins, total):
    """
    Determine the fewest number of coins needed to meet a given amount total.

    Args:
        coins (list): List of coin denominations.
        total (int): The total amount to be met with the coins.

    Returns:
        int: Fewest number of coins needed, or -1
        if it's not possible to meet the total.
    """
    if total <= 0:
        return 0

    dp = [float('inf')] * (total + 1)

    dp[0] = 0

    for coin in coins:
        for i in range(coin, total + 1):
            dp[i] = min(dp[i], dp[i - coin] + 1)

    return dp[total] if dp[total] != float('inf') else -1
