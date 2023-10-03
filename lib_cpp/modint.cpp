#include <iostream>


////////////////////////////////////////

template<int MOD>
struct ModInt {
    int value;

    ModInt() : value(0) {}
    ModInt(int value) : value(value % MOD) {
        if (this->value < 0) this->value += MOD;
    }

    ModInt operator+(const ModInt& other) const {
        return ModInt((value + other.value) % MOD);
    }

    ModInt operator-(const ModInt& other) const {
        return ModInt((value - other.value + MOD) % MOD);
    }

    ModInt operator*(const ModInt& other) const {
        return ModInt((1LL * value * other.value) % MOD);
    }

    ModInt operator/(const ModInt& other) const {
        return *this * other.inv();
    }

    ModInt inv() const {
        int a = value, b = MOD, u = 1, v = 0;
        while (b) {
            int t = a / b;
            a -= t * b; std::swap(a, b);
            u -= t * v; std::swap(u, v);
        }
        return ModInt(u);
    }
};



////////////////////////////////////////

int main() {
    using mint = ModInt<3>;  // mod 3での計算を行う

    mint a = 5;  // 自動で2になる
    mint b = 2;  // 自動で2になる
    mint c = -1; // 自動で2になる

    std::cout << (a + b).value << std::endl; // 1 (2 + 2 mod 3)
    std::cout << (a - c).value << std::endl; // 0 (2 - 2 mod 3)
    std::cout << (a * b).value << std::endl; // 1 (2 * 2 mod 3)
    std::cout << (a / b).value << std::endl; // 1 (2 / 2 mod 3)

    return 0;
}