#!/usr/bin/python3
def pascal_triangle(n):
	"""
	Generate Pascal's Triangle up to n rows.
	
	Args:
		n (int): Number of rows in the Pascal's Triangle.
		
	Returns:
		List[List[int]]: A list of lists representing Pascal's Triangle.
	"""
	if n <= 0:
		return []

	triangle = []
	
	for i in range(n):
		row = [1] * (i + 1)  # Start with a row of ones
		for j in range(1, i):
			row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j]
		triangle.append(row)
	
	return triangle
