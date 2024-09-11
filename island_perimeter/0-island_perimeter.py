#!/usr/bin/python3
"""0-island_perimeter
"""


def island_perimeter(grid):
    """
    Calculates the perimeter of an island described in a grid.

    Args:
        grid (list of list of int): A 2D grid where 1 represents
        land and 0 represents water.

    Returns:
        int: The perimeter of the island.
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
