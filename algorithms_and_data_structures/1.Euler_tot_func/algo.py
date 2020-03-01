#!/usr/bin/env python3


def phi_original(n):
    """Method based on third quality of Euler function"""""
    result = n
    prime = 2
    while prime * prime <= n:
        # Check if i is a prime factor of n
        if n % prime == 0:
            # Multiple result by phi from prime i
            result -= result / prime
            # Delete all occurrences of i in n
            while n % prime == 0:
                n /= prime
        prime += 1

    # If n has a prime factor
    # greater than sqrt(n)
    # (There can be at-most one
    # such prime factor)
    if n > 1:
        result -= result / n
    return int(result)


if __name__ == '__main__':
    n = int(input("Enter positive integer n: "))
    print(phi_original(n))
