//
// Created by ivo on 5/30/23.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

#define endl '\n'

using namespace std;

int L = 0;
int d1 = 0, d2 = 0, minDiff = INT_MAX;

vector<int> dels;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b){
    return static_cast<long long>((a * b) / gcd(a, b));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> L;

    // Get all divisors of L

    for (int i = 2; i * i <= L; i++)
        if (L % i == 0){
            dels.push_back(i);
            if (i * i < L) dels.push_back(L / i);
        }

    sort(dels.begin(), dels.end());


    // Get those divisors for which the task condition is correct

    for(size_t i = 0; 0 < dels.size() && i < dels.size() - 1; i++){
        for(size_t j = i + 1; j < dels.size(); j++){
            if(lcm(dels[i], dels[j]) == L){
                if(abs(dels[j] - dels[i]) < minDiff){
                    minDiff = abs(dels[j] - dels[i]);
                    d1 = dels[i];
                    d2 = dels[j];
                }
            }
        }
    }


    // Show the result

    if (d1 >= 2 && d2 >= 2) cout << d1 << ' ' << d2 << endl;
    else cout << "No solution" << endl;

    cout.flush();

    fclose(stdin);
    fclose(stdout);

    return 0;
}