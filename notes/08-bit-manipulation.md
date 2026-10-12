# Bit Manipulation

## Set or Unset the rightmost unset bit

Just use the clever bit hack: flip n, then AND it with n+1 to get a mask for the rightmost unset bit, then OR with n.

- The formula `(~n) & (n+1)` can misbehave for `int` when `n` is `INT_MAX`, resulting in `-1` due to signed overflow. Add an explicit check for `INT_MAX` and `-1`.
- TC O(1), SC O(1)

## Find xor of numbers from L to R

The XOR sum from 1 to N follows a pattern based on N modulo 4. We can find the XOR from L to R by doing XOR(1,R) ^ XOR(1,L-1).

- Remember xorTillN(0) for L=1 should be 0, which the pattern correctly handles.
- TC O(1), SC O(1)

## Check if a number is power of 2 or not

A number is a power of 2 if it's positive and has only one bit set. The bit trick `n & (n - 1)` clears the least significant set bit.

- Don't forget to handle negative numbers and zero, as they are not powers of two.
- TC O(1), SC O(1)

## Swap two numbers without a temp variable

Using XOR properties, a number XORed with itself is 0, and a^b^b is a. We can use this to swap without extra space.

- If 'a' and 'b' reference the exact same memory location, the variable will become 0.
- TC O(1), SC O(1)

## All Divisors of a Number

Iterate from 1 to sqrt(n) to find divisors. Each divisor 'i' has a pair 'n/i'. Handle perfect squares carefully. Sort the collected divisors.

- Don't add duplicate divisors for perfect squares (when i*i == n).
- TC O(sqrt(n) + D log D) where D is number of divisors, SC O(D) where D is number of divisors

## Sieve of Eratosthenes

I just use a boolean array to keep track of prime status. Then iterate and mark multiples of primes as not prime.

- Start marking multiples from p*p to avoid redundant work.
- TC O(N log log N), SC O(N)

## Find Prime Factorisation of a Number using Sieve

First, precompute the smallest prime factor for all numbers up to MX using a sieve. Then, to factorize a number, repeatedly divide it by its SPF until it becomes 1.

- The sieve should only be computed once, typically with a static flag for lazy initialization.
- TC O(MX log log MX + log N), SC O(MX)
