//
// Created by ivo on 5/28/23.
//

#include <iostream>

#define endl '\n'

using namespace std;

int n = 0, s = 0;
long long result = 1;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    cin >> n >> s;

    for(int i = 0; i < n; i++){
        int si;
        cin >> si;
        result = (result * si) / gcd(result, si);
    }

    if ((result + s) % 7 == 0) cout << 7 << endl;
    else cout << (result + s) % 7 << endl;

//    cout.flush();
//
//    fclose(stdin);
//    fclose(stdout);
    return 0;
}