
# Overview

This project provides a command-line tool (`test_app`) with multiple search and utility modes:

- **Entry Mode (`-m entry`)**  
  Efficiently searches for multiple substring matches using the **Aho-Corasick algorithm**.  
  - **Time complexity:**  
    - Preprocessing: `O(S)`, where `S` is the total length of all tokens.  
    - Search: `O(N)`, where `N` is the length of the input text.  
  - **Benefits:**  
    Performs simultaneous search for multiple tokens in a single pass over the input, making it ideal for large-scale pattern matching.

- **Word Mode (`-m words`)**  
  Counts the exact number of complete word matches (tokens separated by spaces).

- **Checksum Mode (`-m checksum`)**  
  Computes a 32-bit checksum of the input file. Used to verify correctness of results.  
  For testing, the expected checksums are precomputed using a bash script.

- **Help (`-h`)**  
  Prints information about the program and available command-line options.

---

# Build and Test Instructions

## Add GoogleTest as a Submodule (if cloning project from GitHub):

```bash
git submodule add https://github.com/google/googletest.git contrib/googletest
git submodule update --init --recursive
```

## Alternatively, clone the repository directly (if get project from archive):

```bash
git clone https://github.com/google/googletest.git contrib/googletest
```

## Build and Run Tests

```bash
mkdir build
cd build
cmake ..
cmake --build .
ctest --verbose            # detailed output
ctest --output-on-failure  # show output only on failures
```
## Build and Run Program From CLI

```bash
mkdir build
cd build
cmake ..
cmake --build .
```
## Use Cases

```bash
# show help information
./test_app -h
# searching and prints for complete words separated by spaces
./test_app -f (--file) FILEPATH -m (--mode) words -v (--value) TOKEN1 TOKEN2 TOKEN3 ... TOKENN
# searching and prints for occurrences of words using Aho-Corasick
./test_app -f (--file) FILEPATH -m (--mode) entry -v (--value) TOKEN1 TOKEN2 TOKEN3 ... TOKENN
# prints a 32-bit checksum
./test_app -f (--file) FILEPATH -m (--mode) checksum
