# How to build webcrab

CONAN-CLI:
1. create CMakeLists.txt
2. append conanfile.txt
3. run: conan profile list & conan profile path default (profile default existed)
> or
   conan profile detect --force (first conan)
4. run: conan install . --output-folder=build --build=missing --profile=default
5. modify CMakeLists.txt

Windows:
1. cd build
>   #assuming Visual Studio 17 2022 is your VS version and that it matches your default profile
2. cmake .. -G "Visual Studio 17 2022" -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake
>   ...
>   -- Configuring done
>   -- Generating done
3. cmake --build . --config Release
>   ...
>   webcrab.vcxproj -> D:\Projects\webcrab\build\Release\webcrab.exe
4. Release\webcrab.exe

Linux and macOS:
1. cd build
2. cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
>   ...
>   -- Configuring done
>   -- Generating done
3. cmake --build .
>   ...
>   [100%] Built target webcrab
4. ./webcrab
