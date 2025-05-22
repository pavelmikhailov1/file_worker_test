
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
# searching and prints for occurrences of words
./test_app -f (--file) FILEPATH -m (--mode) entry -v (--value) TOKEN1 TOKEN2 TOKEN3 ... TOKENN
# prints a 32-bit checksum
./test_app -f (--file) FILEPATH -m (--mode) checksum
