# cpp-playground
# Advent of Code 2025 C++ Solutions

This repository is a C++ playground and contains solutions and experiments for the [Advent of Code 2025](https://adventofcode.com/) challenges. It also showcases modern C++ features and idioms, such as ranges, pipes, shared pointers, and more.

## Features

- **Advent of Code 2025 solutions:**  
  Implementation of daily puzzles (e.g., day 5 and day 6 shown).
- **Modern C++ usage:**  
  - Use of `std::ranges` and views for easy and efficient data transformation.  
  - Pipes for composable stream-like operations.  
  - Shared and unique pointers for resource management.
- **Build system:**  
  Uses [Bazel](https://bazel.build/) for building and running tests efficiently.

## Project Structure

```
adventofcode2025/
  day5/
    code.cpp   # Example: interval tree for range/interval queries.
    code.hpp   # Declarations for day 5 challenge.
    in.txt     # Sample or actual puzzle input.
  day6/
    code.cpp   # Example: parsing and operating on tabular input using ranges.
```

## Example Highlights

- **Interval Tree:**  
  Efficiently insert and query intervals (see `adventofcode2025/day5/code.cpp`).
- **Parsing with Ranges:**  
  Use C++20 ranges and views to trim, split, and transform inputs with ease (see `adventofcode2025/day6/code.cpp`).

## Building and Running

You need [Bazel](https://bazel.build/) and a modern C++ compiler (supporting C++20).

To build everything:
```
bazel build //...
```

To run a specific binary or test (example for day 5):
```
bazel run //adventofcode2025/day5:code
```

## Notes

- Only ASCII characters are used for maximum compatibility.
- Input files are located with each day's code (e.g., `day5/in.txt`).
- This repository is a learning playground in addition to being a set of puzzle solutions.

## License

MIT License. See [LICENSE](LICENSE) for details.

