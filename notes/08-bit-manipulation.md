# Bit Manipulation

## Set or Unset the rightmost unset bit

Just use the clever bit hack: flip n, then AND it with n+1 to get a mask for the rightmost unset bit, then OR with n.

- The formula `(~n) & (n+1)` can misbehave for `int` when `n` is `INT_MAX`, resulting in `-1` due to signed overflow. Add an explicit check for `INT_MAX` and `-1`.
- TC O(1), SC O(1)
