//
// Created by Juninho Moreira on 20/08/26.
// dev by Pedro
// Question 3 - Median Calculation via Insertion Sort
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

//#include <bits/stdc++.h>

using namespace std;

#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0);
#define ulli unsigned long long int
#define uli unsigned long int
#define lli long long int

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s)) //LASTBIT
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second
#define PI 2*acos(0)

// Helper function to print vectors in terminal
void printVector(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << (i + 1 == v.size() ? "" : " ");
    }
    cout << "\n";
}

// 1. PURE LOGIC
int find_median(vector<int> array, int n) {
    // Insertion Sort ascending, then return the element at index floor((n - 1) / 2)
    for (int i = 1; i < n; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
    return array[(n - 1) / 2];
}

// 2. ONLINE JUDGE ADAPTER
void onlineJudge() {
    int n;
    cin >> n;
    vector<int> array(n);
    for (int i = 0; i < n; i++) cin >> array[i];

    cout << find_median(array, n) << "\n";
}

// 3. LOCAL TESTS
void runLocalTests() {
    vector<int> v1 = {99, 2, 51, 1, 8};
    int median1 = find_median(v1, static_cast<int>(v1.size()));
    cout << "Teste 1: " << (median1 == 8 ? "OK" : "FALHOU") << " (mediana = " << median1 << ")\n";

    vector<int> v2 = {70, 10, 30, 50};
    int median2 = find_median(v2, static_cast<int>(v2.size()));
    cout << "Teste 2: " << (median2 == 30 ? "OK" : "FALHOU") << " (mediana = " << median2 << ")\n";
}

int main() {
    IOFAST();
    runLocalTests();  // <- local testing mode
    // onlineJudge(); // <- online judge mode

    return 0;
}