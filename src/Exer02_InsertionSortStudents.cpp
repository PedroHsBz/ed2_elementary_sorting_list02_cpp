//
// Created by Juninho Moreira on 20/08/26.
// dev by Pedro
// Question 2 - Stable Struct Sorting with Insertion Sort
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

struct Student {
    int id;
    int grade;

    bool operator==(const Student& other) const {
        return id == other.id && grade == other.grade;
    }
};

// Helper function to print students in terminal
void printStudents(const vector<Student>& v) {
    for (const auto& s : v) {
        cout << s.id << " " << s.grade << "\n";
    }
}

// 1. PURE LOGIC
vector<Student> insertion_sort_students(vector<Student> array, int n) {
    // Stable Insertion Sort by grade (ascending): strict '>' in the shift condition
    // preserves relative order of students with equal grades.
    for (int i = 1; i < n; i++) {
        Student key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j].grade > key.grade) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
    return array;
}

// 2. ONLINE JUDGE ADAPTER
void onlineJudge() {
    int n;
    cin >> n;
    vector<Student> array(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i].id >> array[i].grade;
    }

    vector<Student> sorted = insertion_sort_students(array, n);
    printStudents(sorted);
}

// 3. LOCAL TESTS
void runLocalTests() {
    vector<Student> v1 = {{101, 80}, {102, 60}, {103, 80}, {104, 50}};
    vector<Student> expected1 = {{104, 50}, {102, 60}, {101, 80}, {103, 80}};
    vector<Student> got1 = insertion_sort_students(v1, static_cast<int>(v1.size()));
    cout << "Teste 1: " << (got1 == expected1 ? "OK" : "FALHOU") << "\n";
    printStudents(got1);

    vector<Student> v2 = {{10, 75}, {20, 75}, {30, 75}};
    vector<Student> expected2 = {{10, 75}, {20, 75}, {30, 75}};
    vector<Student> got2 = insertion_sort_students(v2, static_cast<int>(v2.size()));
    cout << "Teste 2: " << (got2 == expected2 ? "OK" : "FALHOU") << "\n";
    printStudents(got2);
}

int main() {
    IOFAST();
    runLocalTests();  // <- local testing mode
    // onlineJudge(); // <- online judge mode

    return 0;
}