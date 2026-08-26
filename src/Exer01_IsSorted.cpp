//
// Created by Juninho Moreira on 20/08/26.
// dev by Pedro
// Question 1 - Pre-check with is_sorted
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
int is_sorted(const vector<int>& array, int n) {
    // TODO: Return 1 if array is sorted non-decreasingly, 0 otherwise (with early return)
    for (int i = 1; i < n-1; i++) {
        if (array[i] < array[i - 1]) {
            return 0;
        }
    }
    return 1;
}

// 2. ONLINE JUDGE ADAPTER
void onlineJudge() {
    int n;
    cin >> n;
    vector<int> array(n);
    for (int i = 0; i < n; i++) cin >> array[i];

    cout << (is_sorted(array, n) ? "SORTED" : "UNSORTED") << "\n";
}

// 3. LOCAL TESTS
void runLocalTests() {
    vector<int> array = {10, 20, 20, 35, 50};
    (is_sorted(array, static_cast<int>(array.size())) ? cout << "SORTED\n" : cout << "UNSORTED\n");
    vector<int> array2 = {4, 8, 15, 12, 23, 42};
    (is_sorted(array2, static_cast<int>(array2.size())) ? cout << "SORTED\n" : cout << "UNSORTED\n");

    // TODO: Implement assertions and local test cases
}

int main() {
    IOFAST();
    runLocalTests();  // <- local testing mode
    // onlineJudge(); // <- online judge mode

    return 0;
}