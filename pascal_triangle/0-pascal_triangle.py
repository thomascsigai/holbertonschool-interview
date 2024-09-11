#!/usr/bin/python3
"""
0-main
"""

def print_triangle(triangle):
	"""
	Print the triangle
	"""
	for row in triangle:
		print("[{}]".format(",".join([str(x) for x in row])))
