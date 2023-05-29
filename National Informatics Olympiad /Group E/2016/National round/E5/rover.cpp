//
// Created by ivo on 5/29/23.
//

#include <iostream>
#include <cstdio>

using namespace std;

int n = 0;
long long result = 1;

long long gcd(long long a, long long b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;

    for(int i = 0; i < n; i++){
        int temp = 0;
        cin >> temp;

        result = (result * temp) / gcd(result, temp);
    }

    cout << result;

    cout.flush();

    fclose(stdin);
    fclose(stdout);

    return 0;
}