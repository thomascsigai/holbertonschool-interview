#!/usr/bin/python3
"""module island_perimeter
"""


def island_perimeter(grid):
    """
    Determine the fewest number of coins needed to meet a given amount total.

    Args:
        coins (list): List of coin denominations.
        total (int): The total amount to be met with the coins.

    Returns:
        int: Fewest number of coins needed, or -1
        if it's not possible to meet the total.
    """
    if not grid:
        return 0

    rows = len(grid)
    cols = len(grid[0])
    perimeter = 0

    for row in range(rows):
        for col in range(cols):
            if grid[row][col] == 1:
                # Check the four directions
                if row == 0 or grid[row - 1][col] == 0:  # Up
                    perimeter += 1
                if row == rows - 1 or grid[row + 1][col] == 0:  # Down
                    perimeter += 1
                if col == 0 or grid[row][col - 1] == 0:  # Left
                    perimeter += 1
                if col == cols - 1 or grid[row][col + 1] == 0:  # Right
                    perimeter += 1

    return perimeter
