# Build Instructions

## Generation

The Top-Level CMakeLists file includes a submodule (cpp-build-tools), which includes all the CMake modules and helper files that I use. You can change it to fullfil your needs.

When you're ready, run:

```bash
cmake -S . -B ./build
```

## Compilation

CMake will generate the required files for the build tools/system to compile and link your project. It may generate a Makefile, a Ninja file, a Visual Studio solution or other. Whatever it was generated, you can simply run:

```bash
cmake --build ./build
```
