This repository contains a template used when creating new C++ library. Multiple _type_ of libraries are available:
- Native
- Qt compatible

> [Quick link][repo-lib-header-macros] to interesting macros

**Table of contents:**
- [1. Files to set](#1-files-to-set)
- [2. Tools version used](#2-tools-version-used)
- [3. Library helper](#3-library-helper)

# 1. Files to set

This is only a template repository, multiple files need to be _adjusted_:
- `README.md` (available via `README_library.md`)
- `LICENSE.md`
- `Doxyfile`
- `CHANGELOG.md`
- `CMakeLists`: project name, subdirectories to use, etc...
- `libname/`: rename it to library name
  - `CMakeLists.txt`: choose between native and Qt, then set project name, dependencies, etc...
  - `libraryglobal.h`: better to rename to **actual** library name, choose native/Qt, set macros to better library names
- `tests/`:
  - `CMakeLists.txt`: choose between native and Qt, then set tests name, dependencies, etc...
  - `main.cpp`: File not needed if no custom test main loop is needed
  - `testshelper.cpp`: Set macro used to get path of external tests ressources

# 2. Tools version used

Tools minimal versions set are:
- Minimum C++ standard: _C++ 17_
- Standard used (main `CMakeList`): _C++ 17_
- CMake: `3.19`
- Google tests: `1.11.0`

# 3. Library helper

Those _helpers_ can also be useful when creating new C++ library:
- [AbstractLogger][repo-helper-abstract-logger]: Abstract logger implementation example that allow to have a logging behaviour inside of a library without being tied to a specific logging library API, allowing application developpers to use **their** logging behaviour/dependencies.
- [Doxygen tutorial][tutorial-doxygen]

<!-- Links of this reposiory -->
[repo-lib-header-macros]: libname/libraryglobal_native.h

<!-- External links -->
[repo-helper-abstract-logger]: https://github.com/legerch/AbstractLogger
[tutorial-doxygen]: https://github.com/legerch/develop-memo/tree/master/Documentation
