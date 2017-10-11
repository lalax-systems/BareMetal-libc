BareMetal libc
==============

An implementation of the standard C library for BareMetal.

### Building with CMake

The primary build is CMake.

To install it on Ubuntu, you can do this:

```
sudo apt install cmake
```

To build with CMake, do this:

```
mkdir build
cd build
cmake ..
cmake --build .
```

If Doxygen is installed, the documentation will be put into `html/` and `man/`.

To install Doxygen, you can do this:

```
sudo apt update
sudo apt install doxygen
sudo apt install graphviz
```

### Building with Bash

To build with Bash, use the `build.sh` and `clean.sh` scripts.

```
./build.sh
```

The file `libbaremetal.a` will be generated in the project root directory.

To remove all generated files, use the `clean.sh` script.

```
./clean.sh
```
