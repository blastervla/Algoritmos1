#include <iostream>
#include <vector>

using namespace std;

int main() {
    pair<int, int> div = division(16, 3);
    std::cout << "div: " << div.first << ", resto: " << div.second << std::endl;
    return 0;
}

/*
 * proc suma (in v: seq<Z>, out res: Z) {
 *      Pre { true }
 *               [|v| - 1]
 *      Post { res = ∑ (v[i])}
 *                [i = 0]
 * }
 *
 *                       [i - 1]
 * I = 0 ≤ i ≤ |v| ^L res = ∑ (v[i])
 *                       [j = 0]
 */

int suma(vector<int> v) {
    int i = 0;
    int res = 0;

    while (i < v.size()) {
        res += v[i];
        i++;
    }
    return res;
}

/*
 * 25.
 * proc indice_min_subsec (in s:seq⟨Z⟩, in i,j:Z, out res:Z) {
 *      Pre { |s| > 0 ^ 0 ≤ i, j < |s| ^ i ≤ j }
 *      Post { i ≤ res ≤ j ^ (∀k : Z) i ≤ k ≤ j −→L s[k] ≥ s[res] }
 * }
 *
 * I = i − 1 ≤ l ≤ j ^ i ≤ res ≤ j ^ (∀k : Z) l < k ≤ j −→L s[k] ≥ s[res]
 *
 */
int indice_min_subsec(vector<int> s, int i, int j) {
    if (s.size() <= 0 || i >= s.size() || j >= s.size() || i > j) {
        return -1;
    }

    int res = j;
    int l = j;
    while (l >= i) {
        if (s[l] <= s[res]) {
            res = l;
        }
        l--;
    }

    return res;
}

/*
 * 26.                                                  [i−1]
 * I ≡ 1 ≤ i ≤ (|s| div 2) + 1 ^L suma = s[(|s| div 2)] + ∑ s[(|s| div 2) − k]
                                                        [k=1]
 *                         + (if (|s| div 2) + k ≥ |s| then 0 else s[(|s| div 2) + k] fi)
 */
int sumaTotal(vector<int> s) {
    int mitad = s.size() / 2;
    int suma = s[mitad];
    int i = 1;
    while (i <= mitad) {
        suma += s[mitad - i];
        if (mitad + i < s.size()) {
            suma += s[mitad + i];
        }
        i++;
    }

    return suma;
}

/*
 * 27. Máximo Común Divisor
 *
 * Post condición del ciclo: Qc ≡ a = b = mcd(a, b)
 *
 * I ≡ 0 ≤ a ≤ m ∧ 0 ≤ b ≤ n ∧ mcd(a, b) = mcd(m, n)
 */
int mcd(int m, int n) {
    int a = m;
    int b = n;

    while (a != b) {
        int c = a % b;
        a = b;
        b = c;
        if (b == 0) {
            b = a;
        }
    }

    return a;
}

/*
 * 28. División
 *
 * Post condición del ciclo: Qc ≡ 0 ≤ r < d ∧ 0 ≤ q ≤ n ∧ n = q × d + r.
 *
 * I ≡ (n mod d) ≤ r ≤ n ^ 0 ≤ q ≤ n ^ n = q × d + r
 */
pair<int, int> division(int n, int d) {
    int r = n;
    int q = 0;
    while (r >= d) {
        q++;
        r -= d;
    }
    return {q, r};
}

/*
 * 29. Existe pico (una secuencia tiene picos si en alguna posición el elemento es mayor tanto del anterior como del siguiente)
 * I ≡ 1 ≤ i < |s| ^L res = (∃k : Z) 1 ≤ k < i ^L s[k] > s[k − 1] ^ s[k] > s[k + 1]
 */

bool existePico(vector<int> s) {
    bool res = false;
    int i = 1;
    while (i < s.size() - 1) {
        res = res || (s[i] > s[i - 1] && s[i] > s[i + 1]);
        i++;
    }
    return res;
}

/*
 * 30. Ordenar
 * I ≡ 0 ≤ i ≤ |s| ^L |s| = |s0| ^ mismos(s, s0) ^L ordenada(subseq(s, 0, i)) ^
 * (∀k : Z) 0 ≤ k < |s| ^ i > 0 −→L ((k < i ^ s[k] ≤ s[i − 1]) ∨ (k ≥ i ^ s[k] ≥ s[i − 1]))
 */
