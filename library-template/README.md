_TODO: simple project description_

> [!TIP]
> Latest development/pull requests will be committed into `main` branch.  
> Each stable release have their dedicated branch:
> - `1.0.x`: branch `dev/1.0`
> - `1.1.x`: branch `dev/1.1`
> - etc...

**Table of contents :**
- [1. Requirements](#1-requirements)
  - [1.1. C++ Standards](#11-c-standards)
  - [1.2. Dependencies](#12-dependencies)
- [2. How to build](#2-how-to-build)
- [3. How to use](#3-how-to-use)
  - [3.1. A custom section](#31-a-custom-section)
  - [3.2. Library version](#32-library-version)
    - [3.2.1. Compilation time](#321-compilation-time)
    - [3.2.2. Runtime](#322-runtime)
- [4. Library details](#4-library-details)
- [5. Documentation](#5-documentation)
- [6. License](#6-license)

# 1. Requirements
## 1.1. C++ Standards

This library requires at least **C++ 11** standard

## 1.2. Dependencies

Below, list of required dependencies:

| Dependencies | VCPKG package | Comments |
|:-:|:-:|:-:|
| [Qt][qt-official] | / | Library built with **Qt framework** |
| [Google Tests][gtest-repo] | `gtest` | Only needed to run unit-tests |

> Dependency manager [VCPKG][vcpkg-tutorial] is not mandatory, this is only a note to be able to list needed packages

# 2. How to build

This library can be use as an _embedded library_ in a subdirectory of your project (like a _git submodule_ for example) :
1. In the **root** CMakeLists, add instructions :
```cmake
add_subdirectory(MyLibrary) # Or if library is put in a folder "dependencies" : add_subdirectory(dependencies/MyLibrary)
```

1. In the **application/library** CMakeLists, add instructions :
```cmake
# Link needed libraries
target_link_libraries(${PROJECT_NAME} PRIVATE mylibrary)
```

# 3. How to use
## 3.1. A custom section

_TODO: Describe how to use library_

## 3.2. Library version
### 3.2.1. Compilation time

In order to easily check at compilation time library version (to manage compatibility between multiple versions for example), macro `LIBRARYNAME_VERSION_ENCODE` (defined inside _libraryglobal.h_ file) can be used:
```cpp
#if LIBRARYNAME_VERSION >= LIBRARYNAME_VERSION_ENCODE(2,0,0)
    // Do stuff for version 2.0.0 or higher
#else
    // Do stuff for earlier versions
#endif
```

### 3.2.2. Runtime

At runtime, it is recommended to use the static method:
```cpp
#include "libname/myclass.h"

const QVersionNumber &libSemver = libnamespace::MyClass::getLibraryVersion();
```

# 4. Library details

_TODO: Sections that can be described are: implementation/tips and tricks/alternatives_

# 5. Documentation

All classes/methods has been documented with [Doxygen][doxygen-official] utility and automatically generated at [online website documentation][example-doc-web].

To generate documentation locally, we can use:
```shell
# Run documentation generation
doxygen ./Doxyfile

# Under Windows OS, maybe doxygen is not added to the $PATH
"C:\Program Files\doxygen\bin\doxygen.exe" ./Doxyfile
```
> [!TIP]
> You can also load the _Doxyfile_ into _Doxywizard_ (Doxygen GUI) and run generation.

# 6. License

This library is licensed under [MIT license][repo-license].

<!-- Links of this repository -->
[repo-license]: LICENSE

<!-- External links -->
[doxygen-official]: https://www.doxygen.nl/index.html
[example-doc-web]: https://www.google.com/
[gtest-repo]: https://github.com/google/googletest

[qt-official]: https://www.qt.io/
[qt-installer]: https://www.qt.io/download-qt-installer

[vcpkg-tutorial]: https://github.com/legerch/develop-memo/tree/master/Toolchains/Build%20systems/VCPKG