# ED2 — Sorting Applications — List 02

Practice exercises for **Data Structures II** — Applications of sorting algorithms (pre-check with `is_sorted`, stability, median finding, sorted insertion, task scheduling).

> Federal Institute of Triângulo Mineiro — Campus Patrocínio
> 
> Course: Systems Analysis and Development Technology — 4th Term
> 
> Professor: Júnio Moreira
> 
> Assigned: 08/20/2026 · **Due: 09/02/2026**
> 
> Aluno: Pedro Henrique da Silva Bazilio

---

## 📁 Project Structure

```
ed2-sorting-applications-list02-cpp/
├── CMakeLists.txt
├── main.cpp
├── README.md
├── .gitignore
└── src/
    ├── Exer01_IsSorted.cpp
    ├── Exer02_InsertionSortStableStudents.cpp
    ├── Exer03_InsertionSortMedian.cpp
    ├── Exer04_InsertSorted.cpp
    └── Exer05_SelectionSortTaskScheduling.cpp
```

> **Note:** `main.cpp` at the project root is the default file created by CLion when the project is initialized. It is **not part of the exercises** — each `ExerNN_*.cpp` inside `src/` has its own `main()` and is registered as an independent executable in `CMakeLists.txt`.

Each `Exer*.cpp` file is **self-contained** (has its own `main()`) and is compiled as an independent executable. They all follow the same three-block pattern:

| Block | Responsibility |
|---|---|
| **Pure logic** | Implements the algorithm itself, using STL (`vector`, `string`, etc). No `cin`/`cout`. |
| `onlineJudge()` | Adapter: reads input with `cin`, calls the pure logic, prints with `cout`. |
| `runExer...()` | Runs the examples from the problem statement locally and compares against the expected output (`[PASSED]` / `[FAILED]`). |

---

## 📝 Exercises

| # | File | Problem | Technique | Complexity |
|---|---|---|---|---|
| 1 | `Exer01_IsSorted.cpp` | Check whether an array is already sorted | Linear scan with early return | O(n) |
| 2 | `Exer02_InsertionSortStableStudents.cpp` | Sort student records by grade, preserving input order for ties | Insertion Sort (stable) | O(n²) |
| 3 | `Exer03_InsertionSortMedian.cpp` | Sort an array and return the median | Insertion Sort | O(n²) |
| 4 | `Exer04_InsertSorted.cpp` | Insert a new value into an already sorted array | Insertion Sort (single step) | O(n) |
| 5 | `Exer05_SelectionSortTaskScheduling.cpp` | Sort task durations and compute total completion time | Selection Sort | O(n²) |

<details>
<summary><strong>Details for each exercise (input, output, and example)</strong></summary>

### 1. Pre-check with `is_sorted`
**Input:** N and the array `array`.
**Output:** `SORTED` if the array is in non-decreasing order, `UNSORTED` otherwise. **Must stop (early return) at the first out-of-order pair found.**

```
Input            Output
5                SORTED
10 20 20 35 50
```

### 2. Stable Sorting of Structs with Insertion Sort
**Input:** N, followed by N lines with `id` and `grade` pairs.
**Output:** N lines with `id` and `grade`, sorted ascending by `grade`. Students with equal grades must **keep their original relative order** (strict `>` comparison when shifting, never `>=`).

```
Input            Output
4                104 50
101 80           102 60
102 60           101 80
103 80           103 80
104 50
```

### 3. Median Calculation via Insertion Sort
**Input:** N and N distinct integers.
**Output:** the median — the element at index ⌊(N − 1) / 2⌋ after sorting. **Must sort using Insertion Sort.**

```
Input            Output
5                8
99 2 51 1 8
```

### 4. Sorted Insertion with Shifting (`insert_sorted`)
**Input:** N and `key` on the first line; N sorted integers on the second line.
**Output:** the N + 1 elements after inserting `key` in its correct position, keeping ascending order. **Only shift elements greater than `key` — don't re-sort the whole array.**

```
Input            Output
5 25             10 20 25 30 40 50
10 20 30 40 50
```

### 5. Task Scheduling with Selection Sort
**Input:** N and the array of task `duration`s.
**Output:** first line with durations sorted ascending (via Selection Sort); second line with the sum of every task's completion time (each completion time = sum of all durations up to and including that task).

```
Input            Output
3                2 5 8
5 2 8            24
```

</details>

---

## 🚀 How to Run in CLion

1. Open the project and reload CMake (**Reload CMake Project**, the sync icon that appears after editing `CMakeLists.txt`).
2. In the run target selector (top of the window), choose the desired exercise.
3. Click **Run** (▶) or **Debug** (🐞).

> **Tip:** each file toggles between two modes inside `int main()`:
> - **Local test mode** (default): runs `runExer...()` with the examples from the problem statement.
> - **Online judge mode**: comment out the `runExer...()` call and uncomment `onlineJudge()` before submitting to the judge.

```cpp
int main() {
    runExer01IsSorted();  // <- local test mode (active)
    // onlineJudge();      // <- online judge mode (commented out)
    return 0;
}
```

---

## 💻 How to Run from the Terminal (without CLion)

If you prefer to compile manually with `g++`:

```bash
g++ -std=c++17 -Wall -Wextra -o exer01 src/Exer01_IsSorted.cpp
./exer01
```

To test online judge mode from the terminal, redirect an input file:

```bash
echo "5
10 20 20 35 50" | ./exer01
```

---

## 🙈 What's Inside `.gitignore`

The repository ignores files automatically generated by the IDE and the build process — they shouldn't be tracked in version control because they're regenerated locally on every build and vary from machine to machine.

```gitignore
# CMake / CLion build directories
cmake-build-*/
.cmake/

# JetBrains / CLion IDE internal files
.idea/
*.iws
*.iml

# Compiled binaries and executables
*.exe
*.out
*.app
*.o
*.obj
*.dylib
*.so
*.dll

# Operating system files
.DS_Store
Thumbs.db
```

| Pattern | What it prevents from being tracked |
|---|---|
| `cmake-build-*/`, `.cmake/` | The build folder generated by CLion/CMake on every compilation |
| `.idea/`, `*.iws`, `*.iml` | Local JetBrains IDE settings (specific to your machine) |
| `*.exe`, `*.out`, `*.app`, `*.o`, `*.obj`, `*.dylib`, `*.so`, `*.dll` | Compiled binaries and object files (Windows, Linux, and macOS) |
| `.DS_Store`, `Thumbs.db` | Metadata files automatically created by Finder (macOS) and Explorer (Windows) |

> If any of these files show up as "untracked" when running `git status`, check that `.gitignore` is in the **root** of the repository and that the pattern exactly matches the generated file/folder.

---

## ⚠️ Read the Problem Statement Carefully

- **Exercise 1** requires an **early return**: stop scanning as soon as the first out-of-order pair is found — don't scan the whole array regardless.
- **Exercise 2** requires **stability**: use a strict `>` comparison (never `>=`) when deciding whether to shift a `Student` during insertion, so records with equal `grade` keep their original relative order. Don't use `std::stable_sort` — implement Insertion Sort manually, as requested.
- **Exercise 3** must find the median **by actually running Insertion Sort** on the array (not `std::sort`), then read the element at index `(n - 1) / 2`.
- **Exercise 4** only performs a **single insertion step** — shift elements greater than `key` one position to the right and place `key` in the gap. Don't re-sort the entire array from scratch.
- **Exercise 5** must sort using **Selection Sort** (not `std::sort`), then compute completion times as a running sum: `completion[i] = completion[i-1] + duration[i]`.

---

## ✅ Requirements

- C++17 compiler or newer (GCC, Clang, or MSVC)
- CMake ≥ 3.20
- CLion (recommended) or any IDE/editor of your choice

---

## 📚 Reference

Original exercise list: *Practice Exercises — Data Structures II* (08/20/2026 · due 09/02/2026).
