//
// Created by Juninho Moreira on 20/08/26.
// dev by Pedro
// Question 5 - Task Scheduling with Selection Sort
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <utility>

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
pair<vector<int>, ll> task_scheduling(vector<int> duration, int n) {
    // Selection Sort ascending
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (duration[j] < duration[minIdx]) minIdx = j;
        }
        swap(duration[i], duration[minIdx]);
    }

    // Sum of completion times: each completion is the running prefix sum
    ll completion = 0, total = 0;
    for (int i = 0; i < n; i++) {
        completion += duration[i];
        total += completion;
    }

    return {duration, total};
}

// 2. ONLINE JUDGE ADAPTER
void onlineJudge() {
    int n;
    cin >> n;
    vector<int> duration(n);
    for (int i = 0; i < n; i++) cin >> duration[i];

    pair<vector<int>, ll> result = task_scheduling(duration, n);
    printVector(result.first);
    cout << result.second << "\n";
}

// 3. LOCAL TESTS
void runLocalTests() {
    vector<int> v1 = {5, 2, 8};
    auto [sorted1, total1] = task_scheduling(v1, static_cast<int>(v1.size()));
    cout << "Teste 1: " << (total1 == 24 ? "OK" : "FALHOU") << " -> ";
    printVector(sorted1);
    cout << "Soma total: " << total1 << "\n";

    vector<int> v2 = {4, 1, 3, 2};
    auto [sorted2, total2] = task_scheduling(v2, static_cast<int>(v2.size()));
    cout << "Teste 2: " << (total2 == 20 ? "OK" : "FALHOU") << " -> ";
    printVector(sorted2);
    cout << "Soma total: " << total2 << "\n";
}

int main() {
    IOFAST();
    runLocalTests();  // <- local testing mode
    // onlineJudge(); // <- online judge mode

    return 0;
}