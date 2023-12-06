//
// Created by ivo on 11/28/23.
//

#include <iostream>
#include <cstdio>
#include <list>
#include <string>
#include <cstring>

#define endl '\n'

using namespace std;

string s, t;

list<string> S, T;

char sNum[4096],
    tNum[4096],
    resultNum[4096];

string maxNUM(string a) {
    string maxA = a;
    for(int i = 0, k = i; i < a.length(); i++, k = i){
        string temp;

        while (true){
            k++;
            if( k >= a.length()) k = 0;
            temp.push_back(a[k]);
            if( k == i ) break;
        }

        if(temp[0] != '0' && maxA.compare(temp) < 0) swap(maxA, temp);
    }
    return maxA;
}

string minNUM(string a) {
    string min = a;
    for(int i = 0, k = i; i < a.length(); i++, k = i){
        string temp;

        while (true){
            k++;
            if( k >= a.length()) k = 0;
            temp.push_back(a[k]);
            if( k == i ) break;
        }

        if(temp[0] != '0' && min.compare(temp) > 0) swap(min, temp);
    }
    return min;
}

void printList(list<string> A){
    for(const string a : A)
        cout << a << endl;
}

void convertString(string a, char aNum[]){
    for(int i = 0; i < a.length(); i++)
        aNum[i] = (int)a[i];
}

void printArray(char a[]){
    for(size_t i = 0; i < strlen(a); i++){
        cout << a[i];
    }
    cout << endl;
}

short int compareCharArray(char a[], char b[]){
    if(strlen(a) > strlen(b))
        return 1;
    else if(strlen(a) < strlen(b))
        return -1;

    for(size_t i = 0; i < strlen(a); i++)
        if(a[i] > b[i])
            return 1;
        else if(a[i] < b[i])
            return -1;

    return 0;
}

void subtract(char x[], char y[], char result[]) {
    int len1 = strlen(x);
    int len2 = strlen(y);

    int carry = 0;

    for (int i = 0; i < len1; ++i) {
        int digit1 = x[len1 - 1 - i] - '0';
        int digit2 = i < len2 ? y[len2 - 1 - i] - '0' : 0;

        int diff = digit1 - digit2 - carry;

        if (diff < 0) {
            diff += 10;
            carry = 1;
        } else {
            carry = 0;
        }

        result[i] = diff + '0';
    }

    result[len1] = '\0';

    int nonZeroIdx = len1 - 1;
    while (nonZeroIdx > 0 && result[nonZeroIdx] == '0') {
        result[nonZeroIdx] = '\0';
        nonZeroIdx--;
    }

    int start = 0;
    int end = strlen(result) - 1;
    while (start < end) {
        std::swap(result[start], result[end]);
        start++;
        end--;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    cin >> t;

    string maxS = maxNUM(s);
    string minT = minNUM(t);

    convertString(maxS, sNum);
    convertString(minT, tNum);

    if (compareCharArray(sNum, tNum) < 0) {
        cout << '-';
        swap(sNum, tNum);
    }

    subtract(sNum, tNum, resultNum);

    printArray(resultNum);

    cout.flush();
    return  0;
}