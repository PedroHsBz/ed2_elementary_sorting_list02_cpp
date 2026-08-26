//
// Created by Juninho Moreira on 20/08/26.
// dev by Pedro
// Question 4 - Sorted Insertion with Shifting (insert_sorted)
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
vector<int> insert_sorted(vector<int> array, int n, int key) {
    // Append key at the end, then shift larger elements right (Insertion Sort step)
    array.push_back(key);
    int j = n - 1;
    while (j >= 0 && array[j] > key) {
        array[j + 1] = array[j];
        j--;
    }
    array[j + 1] = key;
    return array;
}

// 2. ONLINE JUDGE ADAPTER
void onlineJudge() {
    int n, key;
    cin >> n >> key;
    vector<int> array(n);
    for (int i = 0; i < n; i++) cin >> array[i];

    vector<int> result = insert_sorted(array, n, key);
    printVector(result);
}

// 3. LOCAL TESTS
void runLocalTests() {
    vector<int> v1 = {10, 20, 30, 40, 50};
    vector<int> got1 = insert_sorted(v1, static_cast<int>(v1.size()), 25);
    vector<int> expected1 = {10, 20, 25, 30, 40, 50};
    cout << "Teste 1: " << (got1 == expected1 ? "OK" : "FALHOU") << " -> ";
    printVector(got1);

    vector<int> v2 = {10, 20, 30, 40};
    vector<int> got2 = insert_sorted(v2, static_cast<int>(v2.size()), 5);
    vector<int> expected2 = {5, 10, 20, 30, 40};
    cout << "Teste 2: " << (got2 == expected2 ? "OK" : "FALHOU") << " -> ";
    printVector(got2);
}

int main() {
    IOFAST();
    runLocalTests();  // <- local testing mode
    // onlineJudge(); // <- online judge mode

    return 0;
}