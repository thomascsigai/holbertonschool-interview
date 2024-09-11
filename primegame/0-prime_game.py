#!/usr/bin/python3

""" module 0
"""
def isWinner(x, nums):
    def sieve(n):
        is_prime = [True] * (n + 1)
        is_prime[0] = is_prime[1] = False
        p = 2
        while p * p <= n:
            if is_prime[p]:
                for multiple in range(p * p, n + 1, p):
                    is_prime[multiple] = False
            p += 1
        return [num for num, prime in enumerate(is_prime) if prime]

    def simulate_game(n):
        if n < 2:
            return "Ben"
        
        primes = sieve(n)
        numbers = set(range(1, n + 1))
        turn = 0  # Maria starts (0 for Maria, 1 for Ben)
        
        while primes:
            current_prime = primes[0]
            if current_prime > n:
                break
            
            # Remove current prime and its multiples
            to_remove = {current_prime}
            for multiple in range(current_prime * 2, n + 1, current_prime):
                to_remove.add(multiple)
            
            numbers -= to_remove
            primes = [p for p in primes if p in numbers]

            if not primes:
                return "Ben" if turn == 0 else "Maria"
            
            turn = 1 - turn  # Switch turn
        
        return "Ben" if turn == 0 else "Maria"

    maria_wins = 0
    ben_wins = 0
    
    for n in nums:
        if simulate_game(n) == "Maria":
            maria_wins += 1
        else:
            ben_wins += 1
    
    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
