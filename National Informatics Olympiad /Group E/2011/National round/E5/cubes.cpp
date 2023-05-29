//
// Created by ivo on 5/29/23.
//

#include <iostream>
#include <cstdio>

#define endl '\n';

using namespace std;

int n = 0, m = 0, k = 0;
long long result = 0;

long long gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> m >> k;

    long long currGCD = gcd(gcd(n, m), k);

    result = (n / currGCD) * (m / currGCD) * (k / currGCD);

    cout << result << endl;

    cout.flush();

    fclose(stdin);
    fclose(stdout);

    return 0;
}