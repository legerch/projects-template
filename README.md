**Table of contents :**
- [1. Description](#1-description)
- [2. Dependencies](#2-dependencies)
- [How to use](#how-to-use)
- [3. Documentation](#3-documentation)

# 1. Description

_Under construction_

# 2. Dependencies

Dependency modes:
- **VCPKG :** Via [VCPKG][vcpkg-tutorial] dependency manager (under Windows/Linux/Mac)
- **Gitmodule :** Git submodule
- **Package :** Via system dependency manager
- **Internal :** Direct import of dependency in the repository (use when no other solution !)

| Dependencies | Dependency mode | Comments |
|:-:|:-:|:-:|
| [Qt][qt-official] | / | Application built with **Qt framework** |
| [Google Tests][gtest-repo] | VCPKG | Only needed to run unit-tests |

# How to use

This library can be use as an _embedded library_ in a subdirectory of your project (like a _git submodule_ for example) :
1. In the **root** CMakeLists, add instructions :
```cmake
add_subdirectory(MyLibrary) # Or if library is put in a folder "dependencies" : add_subdirectory(dependencies/MyLibrary)
```

2. In the **application/library** CMakeLists, add instructions :
```cmake
# Link needed libraries
target_link_libraries(${PROJECT_NAME} PRIVATE mylibrary)
```

# 3. Documentation

All library files are documented, you can generated documentation with [Doxygen][doxygen-official] tool.  
A configuration file for **Doxygen** can be found in the project: `Doxyfile`

1. Download and install [**Doxygen** tool][doxygen-official]
2. Generate documentation:
```shell
# Use `Doxyfile` for the example
doxygen Doxyfile

#If $PATH doesn't have doxygen binaries
"C:\Program Files\doxygen\bin\doxygen.exe" Doxyfile
```
> **Note for developers** : When adding platform conditions (_ex : `#if defined(WIN32)`_), don't forget to add macro `USE_DOXYGEN` condition for the documentation, otherwise, some functions will not be documented.  
> _Example :_
> ```cpp
> #if defined(WIN32) || defined(USE_DOXYGEN)
>   // Do stuff
> #endif
> ```

<!-- Links of this repository -->

<!-- External links -->
[doxygen-official]: https://www.doxygen.nl/index.html
[gtest-repo]: https://github.com/google/googletest

[qt-official]: https://www.qt.io/
[qt-installer]: https://www.qt.io/download-qt-installer

[vcpkg-tutorial]: https://github.com/legerch/develop-memo/tree/master/Toolchains/Build%20systems/VCPKG