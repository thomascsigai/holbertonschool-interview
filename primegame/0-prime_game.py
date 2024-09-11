#!/usr/bin/python3
"""
prime_game_module

This module provides functionality to simulate a prime number game between two players, Maria and Ben, and determine the winner of multiple rounds.

The game rules are as follows:
- Players alternate picking prime numbers from a set of consecutive integers starting from 1 up to and including `n`.
- The chosen prime number and its multiples are removed from the set.
- The player who cannot make a move loses the game.

Functions:
- isWinner(x, nums): Determines which player won the most rounds across multiple values of `n`.
- sieve(n): Generates a list of prime numbers up to and including `n`.
- simulate_game(n): Simulates the game for a given `n` and determines the winner if both players play optimally.
"""

def sieve(n):
    """
    Generates a list of prime numbers up to and including n using the Sieve of Eratosthenes.

    Args:
    n (int): The maximum number up to which primes are to be generated.

    Returns:
    list of int: A list of prime numbers up to and including n.
    """
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False  # 0 and 1 are not primes
    p = 2
    while p * p <= n:
        if is_prime[p]:
            for multiple in range(p * p, n + 1, p):
                is_prime[multiple] = False
        p += 1
    return [num for num, prime in enumerate(is_prime) if prime]

def simulate_game(n):
    """
    Simulates the prime number game for a given n and determines the winner if both players play optimally.

    Args:
    n (int): The upper bound of the set of integers (1 to n) for the game.

    Returns:
    str: The name of the winner ("Maria" or "Ben").
    """
    if n < 2:
        return "Ben"  # If n < 2, Maria has no moves and thus Ben wins.

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

def isWinner(x, nums):
    """
    Determines the player who won the most rounds in the prime number game.

    Args:
    x (int): The number of rounds.
    nums (list of int): A list of integers where each integer represents the value of `n` for a round.

    Returns:
    str: The name of the player who won the most rounds ("Maria" or "Ben").
    None: If both players won an equal number of rounds.
    """
    # Count wins for Maria and Ben
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
