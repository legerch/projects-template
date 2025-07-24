This repository is a project templates example useful when creating C++ _libraries_ (native or Qt-based) or _applications_.

**Table of contents:**
- [1. Library template](#1-library-template)
  - [1.1. What to set](#11-what-to-set)
  - [1.2. Library helpers](#12-library-helpers)

# 1. Library template

Library template is available at [library template][template-lib] folder and provide support for both _C++ native_ or _C++ Qt based_ libraries.  
It use the [_Pitchfork convention_][pitchfork-web] (see [associated repository][pitchfork-repo]) to keep separated **public API** and **private sources**

## 1.1. What to set

This is just a template folder, multiple files will have to be adjusted to the library:
- Informations files:
  - `README.md`: Complete it with library name and details
  - `CHANGELOG.md`: Set it with library details and provide proper repository links
  - `LICENSE.md`: An _MIT License_ example is available in it via the file `LICENSE_mit.md`
  - `.gitignore`: Contains minimal files/folder to ignore, should be ready to go.
  - `metadata/`: Contains metadata files that can be used by OSes to determine libraries properties (note that for libraries, only _Windows OS_ have those metadata files)
    - `windows.infos.rc.in`:
      - Simply verify that macro `IS_LIBRARY` is set to `1`, all others fields will be generated automatically by _CMake_ in `windows/infos.rc` file.
- Build files:
  - `CMakelists.txt`: Allow to build the library with **CMake** build system
    - Set project properties/informations
    - If not using _Qt framework_, simply remove all _Qt_ related lines
    - Set files and dependencies to use
- Library files:
  - `include/libname/`:
    - Rename it to the library name, this is the name that will be used when someone will include one of the headers
    - All **public APIs** files (only headers of public classes) will go inside this repository
    - `library_global.h.in`: Contains common libraries macros (version, export management, abstract compiler differences, etc...)
      - Choose the version for _C++ native_ or _C++ Qt based_ and rename it to `library_global.h.in`. The final header `library_global.h` will be generated automatically by **CMake** buildsystem.
  - `src/`: Contains all sources files (`.cpp`, `.mm`, etc...) and private headers library (`.hpp`, `.h`).
- Documentation files:
  - `themes/`: Contains current Doxygen theme (current one is based on _[Doxygen Awesome CSS theme][repo-doxy-theme-awesome]_, more informations can be found in [this tutorial][tuto-doxygen])
  - `fragments`: Contains _Doxygen_ configuration to generate documentation
    - `Doxyfile-common.in`: Set properties that **public-api** and **private-api** documentations have in common.
    - `Doxyfile-internal.in`: Set files to include or exclude to build _private-api_ documentation.
    - `Doxyfile-public-api.in`: Set files to include or exclude to build _public_-api_ documentation (so generally `include/` folder and source files of public classes).
- Test files:
  - `CMakelists.txt`:
    - Set test application needed files
    - If not using _Qt framework_ for the tests (running Qt app for tests is generally **not needed**, except if you want to test signals like with [_QSignalSpy_][qt-class-qsignalspy] for example) : 
      - Simply remove all _Qt_ related lines
      - Use `GTest::gtest_main` for linking _[Google Tests][repo-gtest]_ library
      - Delete `main.cpp` file (only needed if using custom behaviour like when using Qt framework)
  - `helpers/`: Contains classes that can be helpful during test execution
    - Class `TestRsc` is useful to manage external files: to compare an input and output files instead of harcoding those in test sources
  - `external-ressources`: Contains input/output test files, don't put headers or sources file in it, this is a ressource directory

## 1.2. Library helpers

Those _helpers_ can also be useful when creating new C++ library:
- [AbstractLogger][repo-helper-abstract-logger]: Abstract logger implementation example that allow to have a logging behaviour inside of a library without being tied to a specific logging library API, allowing application developpers to use **their** logging behaviour/dependencies.
- [Doxygen tutorial][tuto-doxygen]

<!-- Links of this reposiory -->
[template-lib]: library-template/

<!-- External links -->
[pitchfork-repo]: https://github.com/vector-of-bool/pitchfork
[pitchfork-web]: https://web.archive.org/web/20231210061404/https://api.csswg.org/bikeshed/?force=1&url=https://raw.githubusercontent.com/vector-of-bool/pitchfork/develop/data/spec.bs

[qt-class-qsignalspy]: https://doc.qt.io/qt-6/qsignalspy.html

[repo-doxy-theme-awesome]: https://github.com/jothepro/doxygen-awesome-css
[repo-gtest]: https://github.com/google/googletest
[repo-helper-abstract-logger]: https://github.com/legerch/AbstractLogger

[tuto-doxygen]: https://github.com/legerch/develop-memo/tree/master/Documentation
