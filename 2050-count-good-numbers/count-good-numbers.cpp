class Solution {
public:
    static const long long MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long result = 1;

        while (exp > 0) {
            if (exp & 1) {
                result = (result * base) % MOD;
            }

            base = (base * base) % MOD;
            exp >>= 1;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenPos = (n + 1) / 2;
        long long oddPos = n / 2;

        return (power(5, evenPos) * power(4, oddPos)) % MOD;
    }
};