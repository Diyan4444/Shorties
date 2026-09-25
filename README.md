# Shorties ⚡

### I thought to make a small repo related to some basic programs in cpp just for fun, because WHY NOT!

A collection of lightweight C++ programs, small console utilities, and logic drills.

---

## 📁 Repository Structure

```text
Shorties/
├── cpp/       # Source code files (.cpp)
└── exe/       # Compiled binary executables (.exe)
```

### 📂 cpp/ — Source Code
Contains the source code files for the C++ programs.

- **grade.cpp**: Student management console utility to add/remove student records, add marks for 5 subjects, and compute final grades.

### 📂 exe/ — Executables
The `exe` folder signifies the executable format for the compiled C++ code. It contains the generated Windows binaries so you can run the programs directly without needing to recompile them each time.

---

## 🚀 How to Run

### 1. Run Pre-compiled Binaries (Windows)
Navigate to the `exe/` folder and execute the binary directly:

```powershell
cd exe
.\grade.exe
```

### 2. Compile and Run from Source
If you want to compile the code yourself using a C++ compiler like `g++`:

1. Move to the source folder:
   ```bash
   cd cpp
   ```

2. Compile the file (outputting into the `exe/` directory):
   ```bash
   g++ grade.cpp -o name.exe
   ```

3. Run the compiled program:
   ```powershell
   .\name.exe
   ```