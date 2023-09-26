# How to build webcrab

CONAN-CLI:
1. create CMakeLists.txt
2. append conanfile.txt
3. run: conan profile list & conan profile path default (profile default existed) / conan profile detect --force (first conan)
4. run: conan install . --output-folder=build --build=missing
5. modify CMakeLists.txt

Windows:
$ cd build
assuming Visual Studio 17 2022 is your VS version and that it matches your default profile
$ cmake .. -G "Visual Studio 17 2022" -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake
$ cmake --build . --config Release
...
$ Release\webcrab.exe

Linux and macOS:
$ cd build
$ cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
$ cmake --build .
...
[100%] Built target webcrab
$ ./webcrab
