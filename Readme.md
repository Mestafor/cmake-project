# Instalation Windows
1. `choco install cmake`
2. `choco install mingw`
3. `cmake -S . -B ./build -G "Ninja"`
4. `cmake --build build`
5. `./build/bin/cmake_test.exe`

# Instalation Linux(Ubuntu)
1. `sudo apt-get install build-essential gdb`
2. `cmake -S . -B ./build`
3. `cmake --build build`
4. `./build/bin/cmake_test`

# Submodule
1. `git submodule add git@github.com:glfw/glfw.git external/glfw`

## Usefull
1. `cmake --help` to check available generators
2. https://code.visualstudio.com/docs/cpp/config-mingw