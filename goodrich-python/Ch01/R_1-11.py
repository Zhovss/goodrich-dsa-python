'''R-1.11 Demonstrate how to use Python’s list comprehension syntax to produce
the list [1, 2, 4, 8, 16, 32, 64, 128, 256].'''

if __name__ == "__main__":
    print([2**n for n in range(9)])