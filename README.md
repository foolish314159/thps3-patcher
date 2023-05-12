# thps3-patcher
Simple command line patcher for Tony Hawk's Pro Skater 3.

Fixes the backwards manual glitch and removes the 251 multiplier limit.

## Build

Make sure to change the value of `THPS3_EXE` if your THPS3 executable isn't called `THPS3.exe`. Usually this will be `Skate3.exe` unless you are using [PARTYMOD for THPS3](https://github.com/PARTYMANX/partymod-thps3).

Build from command line using your favorite compiler.

### GCC
```console
g++ thps3_patch.cpp -o thps3_patch.exe
```

### Clang
```console
clang thps3_patch.cpp -p thps3_patch.exe
```

### MSVC
```console
cl thps3_patch.cpp
```

### CMake
```console
mkdir build
cd build
cmake ..
cmake --build .
```

## Run

Execute the patch while THPS3 is running.
