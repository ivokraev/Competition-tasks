//
// Created by ivo on 12/13/23.
//

#include <iostream>

#define endl '\n'

using namespace std;

long long int n = 0, k = 0;
int takenNum = 0;
long long int a[101];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> k;

    for(int i = 0; i < k; i++) {
        cin >> a[i];
        bool isTaken = false;
        for(int j = 0; j < i; j++)
            if(a[j] == a[i])
            {
                isTaken = true;
                break;
            }
        if(isTaken) continue;

        takenNum++;
    }

    cout << n - takenNum << endl;

    cout.flush();

    return 0;
}