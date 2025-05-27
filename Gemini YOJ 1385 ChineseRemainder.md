The problem asks us to implement a secret sharing scheme based on the Chinese Remainder Theorem (CRT). We need to perform two main parts: secret sharing (calculating `s_i` for each participant) and preparing values for secret reconstruction using the first `k` participants (calculating `M_i`, `N_i`, `y_i`).

**Problem Breakdown:**

1.  **Inputs:**
    *   `n`: Total number of participants.
    *   `k`: Threshold number of participants required to reconstruct the secret.
    *   `s`: The secret value.
    *   `m_1, m_2, ..., m_n`: A list of `n` prime moduli, sorted in non-decreasing order. Each `m_i` is between 2 and 100.

2.  **Secret Sharing (Calculating `s_i`):**
    *   For each participant `i` (from 1 to `n`), their share component `s_i` is calculated as `s_i = s mod m_i`.
    *   The output requires printing all `s_i` values on one line, space-separated.

3.  **Secret Reconstruction (Calculations for the first `k` participants):**
    The problem simplifies reconstruction by considering only the first `k` participants. For each of these `k` participants (indexed `i` from 1 to `k`):
    *   **`M_full`**: First, we need the product of all `n` moduli: `M_full = m_1 * m_2 * ... * m_n`.
    *   **`km`**: This is the modulus for reconstruction using the first `k` shares: `km = m_1 * m_2 * ... * m_k`.
    *   **`M_i`**: For participant `i`, `M_i = M_full / m_i`.
    *   **`N_i`**: This is the modular multiplicative inverse of `M_i` with respect to `m_i`. That is, `N_i = M_i^(-1) mod m_i`. Since `m_i` is prime, we can find `N_i` using Fermat's Little Theorem: `N_i = M_i^(m_i - 2) mod m_i`.
    *   **`y_i`**: This value is calculated as `y_i = (s_i * M_i * N_i) mod km`.
    *   The output requires `k` lines. Each line `i` (for the `i`-th participant among the first `k`) should contain `M_i, N_i, y_i`, space-separated.

**Constraints and Data Types:**
*   `n, k` are small (`2 <= k < n <= 9`).
*   `m_i` are small primes (`<= 100`).
*   `M_full` (product of all `m_i`) can be up to `10^18`.
*   `km` (product of first `k` `m_i`) can also be large, up to `M_full`.
*   `s` is constrained such that `s < km`.
*   Values like `M_full`, `km`, `M_i`, and `s` can be large, requiring 64-bit integers (`long long` in C++, Python handles large integers automatically).
*   The calculation of `y_i` involves `s_i * M_i * N_i`. `s_i < m_i <= 100`, `N_i < m_i <= 100`. `M_i` can be large (e.g., `M_full / 2`). The product `s_i * M_i` could be up to `100 * (10^18 / 2) = 5 * 10^{19}`. This intermediate product can exceed the capacity of a 64-bit integer.
    *   In Python, this is handled automatically.
    *   In C++, modular multiplication (e.g., using `__int128` for the intermediate product or a binary multiplication algorithm) is needed for `(A * B) % P` if `A * B` overflows.

**Implementation Steps:**

**Python:**
1.  Read `n, k, s`.
2.  Read the list `m_values`.
3.  Calculate `s_i_values`: For each `m_val` in `m_values`, compute `s % m_val`. Print these.
4.  Calculate `M_full`: Product of all elements in `m_values`.
5.  Calculate `km`: Product of the first `k` elements in `m_values`.
6.  For `i` from `0` to `k-1`:
    a.  `mi = m_values[i]`
    b.  `si = s_i_values[i]`
    c.  `Mi_val = M_full // mi`
    d.  `Ni_val = pow(Mi_val, mi - 2, mi)` (Python's built-in `pow` does modular exponentiation).
    e.  `yi_val = (si * Mi_val * Ni_val) % km`
    f.  Print `Mi_val, Ni_val, yi_val`.

**C++:**
1.  Read `n, k, s_secret`. Use `long long` for `s_secret`.
2.  Read `m_values` into a `std::vector<long long>`.
3.  Calculate `s_i_values` and print them.
4.  Calculate `M_full` (product of all `m_values`, fits in `long long`).
5.  Calculate `km` (product of first `k` `m_values`, fits in `long long`).
6.  Implement a modular exponentiation function `power(base, exp, mod)`:
    *   `long long power(long long base, long long exp, long long mod)`
    *   The `mod` argument here will be `mi` (which is `<=100`). `base` should be taken modulo `mi`. Intermediate products `res*base` and `base*base` will be `< mi*mi <= 10000`, fitting in `long long`.
7.  Implement a modular multiplication function `mul(a, b, m)` for `(a*b)%m` where `a*b` might overflow `long long`:
    *   `long long mul(long long a, long long b, long long m)`
    *   This can use `static_cast<__int128>(a) * b % m`.
8.  For `i` from `0` to `k-1`:
    a.  `mi = m_values[i]`
    b.  `si = s_i_values[i]`
    c.  `Mi_val = M_full / mi`
    d.  `Ni_val = power(Mi_val, mi - 2, mi)`
    e.  `term_s_M = mul(si, Mi_val, km)` (This is where `si * Mi_val` could overflow `long long`).
    f.  `yi_val = (term_s_M * Ni_val) % km` (Here `term_s_M < km`, `Ni_val < 100`. Product `~km * 100` fits in `long long` if `km <= 10^16 / 100 = 10^{16}`. Max `km` is `~10^{17}` with `m_i=97, k=9`. So `km*100` might exceed `10^{18}`. Thus, better use `mul` here too, or be careful. Since `Ni_val` is small, direct multiplication `(term_s_M * Ni_val)` will fit if `km * 100` fits `long long`. Max `km` from `97^8` is `~7.8e15`. `km*100` `~7.8e17`. Fits. If `k=9` then `km` could be `~7.6e17`. `km*100` `~7.6e19`. This would overflow. Let's recheck. `k < n <= 9`. Max `k` is 8. So `97^8 * 100` is `~7.8 * 10^{17}`. This should fit in `long long`.
    g.  Print `Mi_val, Ni_val, yi_val`.

For safety, `yi_val` calculation in C++ could be `yi_val = mul(term_s_M, Ni_val, km)`. However, given `k < n <= 9`, max `k` is 8. The product of eight largest primes under 100 (e.g., `97*89*...`) or `97^8` is less than `10^{16}`. `10^{16} * 100 = 10^{18}`, which fits in a signed `long long` (max `~9*10^{18}`). So direct multiplication `(term_s_M * Ni_val) % km` is fine.

Let's provide the Python solution first, then C++.

```python
def power(base, exp, mod):
    res = 1
    base %= mod
    while exp > 0:
        if exp % 2 == 1:
            res = (res * base) % mod
        base = (base * base) % mod
        exp //= 2
    return res

def solve():
    n, k, s = map(int, input().split())
    m_values = list(map(int, input().split()))

    # Part 1: Calculate and print s_i
    s_i_values = []
    for i in range(n):
        s_i_values.append(s % m_values[i])
    print(*(s_i_values))

    # Part 2: Calculate M_full and km
    M_full = 1
    for val in m_values:
        M_full *= val

    km = 1
    for i in range(k):
        km *= m_values[i]

    # Part 3: Calculate and print M_i, N_i, y_i for first k participants
    for i in range(k):
        mi = m_values[i]
        si = s_i_values[i]

        # M_i = M_full / m_i
        Mi_val = M_full // mi  # Integer division
        
        # N_i = Mi_val^(-1) mod m_i
        # Since mi is prime, use Fermat's Little Theorem: a^(p-2) mod p
        Ni_val = power(Mi_val, mi - 2, mi)

        # y_i = (s_i * M_i * N_i) mod km
        # Python handles large intermediate products automatically.
        # The order of operations for modulo:
        # (A * B * C) % P = (((A * B) % P) * C) % P
        # Or, Python can do (A*B*C) then take modulo P.
        term1 = (si * Mi_val) % km # si * Mi_val can be large
        yi_val = (term1 * Ni_val) % km
        
        # A more direct way in Python, relying on its large integer arithmetic:
        # yi_val = (si * Mi_val * Ni_val) % km

        print(Mi_val, Ni_val, yi_val)

solve()
```

```cpp
#include <iostream>
#include <vector>
#include <numeric> // Not strictly needed for this problem

// Modular exponentiation: (base^exp) % mod
// Constraints: mod (which is mi) is <= 100.
// base is Mi_val % mi, so base < mi.
// Intermediate products like res*base or base*base will be < mi*mi <= 100*100 = 10000.
// These fit comfortably in long long.
long long power_mod(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    // Ensure base is non-negative, C++ % can yield negative if base is negative.
    // Here, Mi_val is positive, mi is positive, so base will be non-negative.
    // if (base < 0) base += mod; 
    
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

// Modular multiplication: (a * b) % m
// Handles potential overflow of a * b if a * b > LLONG_MAX.
// Uses __int128 for intermediate product if available and `m` is large.
long long multiply_mod(long long a, long long b, long long m) {
    // Ensure a and b are in [0, m-1] if they come from other calculations.
    // Here, 'a' (si) is < mi <= 100. 'b' (Mi_val) can be large.
    // 'm' (km) can be large.
    // Product a*b can be ~100 * 10^18/2 = 5*10^19, needs 128-bit integer.
    long long res = (static_cast<__int128>(a) * b) % m;
    // Result of % in C++ can be negative if dividend is negative.
    // Here a,b,m are positive, so res will be in [0, m-1].
    // if (res < 0) res += m; 
    return res;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n_val, k_val;
    long long s_secret;
    std::cin >> n_val >> k_val >> s_secret;

    std::vector<long long> m_values(n_val);
    for (int i = 0; i < n_val; ++i) {
        std::cin >> m_values[i];
    }

    // Part 1: Calculate and print s_i
    std::vector<long long> s_i_values(n_val);
    for (int i = 0; i < n_val; ++i) {
        s_i_values[i] = s_secret % m_values[i];
    }
    for (int i = 0; i < n_val; ++i) {
        std::cout << s_i_values[i] << (i == n_val - 1 ? "" : " ");
    }
    std::cout << std::endl;

    // Part 2: Calculate M_full and km
    long long M_full = 1;
    for (long long val : m_values) {
        M_full *= val; 
    }

    long long km = 1;
    for (int i = 0; i < k_val; ++i) {
        km *= m_values[i]; 
    }

    // Part 3: Calculate and print M_i, N_i, y_i for first k_val participants
    for (int i = 0; i < k_val; ++i) {
        long long mi = m_values[i];    
        long long si = s_i_values[i];  

        long long Mi_val = M_full / mi; 
        
        long long Ni_val = power_mod(Mi_val, mi - 2, mi);
        
        // y_i = (s_i * M_i_val * N_i_val) mod km
        // Step 1: (s_i * M_i_val) mod km. This uses multiply_mod due to potential overflow.
        long long term_s_M = multiply_mod(si, Mi_val, km);
        
        // Step 2: (term_s_M * N_i_val) mod km
        // term_s_M < km. N_i_val < mi <= 100.
        // Max k_val is 8. Max km ~ (smallest prime > 1)^8, e.g. 2^8=256, up to ~97^8 ~ 7.8*10^15.
        // Max term_s_M * N_i_val ~ 7.8*10^15 * 99 ~ 7.7*10^17. Fits in long long.
        long long yi_val = (term_s_M * Ni_val) % km;
        // if (yi_val < 0) yi_val += km; // Ensure positive if intermediate could be negative. Not here.

        std::cout << Mi_val << " " << Ni_val << " " << yi_val << std::endl;
    }

    return 0;
}

```