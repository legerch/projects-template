This repository is a project templates example useful when creating C++ _libraries_ (native or Qt-based) or _applications_.

**Table of contents:**
- [1. Library template](#1-library-template)
  - [1.1. What to set](#11-what-to-set)
  - [1.2. Library helpers](#12-library-helpers)
- [Application template](#application-template)
  - [What to set](#what-to-set)

# 1. Library template

Library template is available at [library template][template-lib] folder and provide support for both _C++ native_ or _C++ Qt based_ libraries.  
It use the [_Pitchfork convention_][pitchfork-web] (see [associated repository][pitchfork-repo]) to keep separated **public API** and **private sources**

## 1.1. What to set

This is just a template folder, multiple files will have to be adjusted to the library:
- Informations files:
  - `README.md`: Complete it with library name and details
  - `CHANGELOG.md`: Set it with library details and provide proper repository links
  - `LICENSE.md`: An _MIT License_ example is available in it
  - `.gitignore`: Contains minimal files/folder to ignore, should be ready to go.
  - `metadata/`: Contains metadata files that can be used by OSes to determine libraries properties (note that for libraries, only _Windows OS_ have those metadata files)
    - `windows/infos.rc.in`:
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

# Application template

Application template is available at [application template][template-app] folder and provide support for _C++ Qt based_ applications.  

## What to set

- Informations files:
  - `README.md`: Complete it with application name and details
  - `CHANGELOG.md`: Set it with application details and provide proper repository links
  - `LICENSE.md`: An _MIT License_ example is available in it
  - `.gitignore`: Contains minimal files/folder to ignore, should be ready to go.
- Assets files:
  - `assets/icons/`: Add all used icons for this application.
  - `assets/logos/`: Application main logo to use.
  - `ressources.qrc`: This file will contains all assets ressources needed by the application
- Metadata files (`metadata/`): Contains metadata files that can be used by OSes to determine application properties
  - **Windows:** (`windows/infos.rc.in`)
    - Simply verify that macro `IS_LIBRARY` is set to `0`, all others fields will be generated automatically by _CMake_ in `windows/infos.rc` file.
    - Add application icon at `.ico` format in `assets/logos/`
  - **Mac OS:** (`macos/Infos.plist.in`)
    - All fields should be generated automatically.
    - Some additional keys can be necessary depending on your application required features, refer to [official documentation][macos-metadata-doc] for more infos. Often used can be:
      - [NSLocalNetworkUsageDescription][macos-perm-network]
      - [NSBonjourServices][macos-perm-bonjour]
      - [NSLocationUsageDescription][macos-perm-location]
    - Add application icon at `.icns` format in `assets/logos/`
- Build files:
  - `CMakelists.txt`: Allow to build the application with **CMake** build system
    - Set project properties/informations
    - Specific to _Qt framework_:
      - If not using it, simply remove all _Qt_ related lines
      - QML support is also set, disable it via option `APPNAME_USE_QML` if not using QML files
    - Set files and dependencies to use
- Application files:
  - `base/appname_global.h.in`: Contains common application macros (version, name, abstract compiler differences, etc...)
    - Choose the version for _C++ native_ or _C++ Qt based_ and rename it to `appname_global.h.in`. The final header `appname_global.h` will be generated automatically by **CMake** buildsystem.
  - `main.cpp`:
    - This file contains code for a **Qt Widget** and a **Qt QML** based application, choose the one to use and remove unnecessary (if _QML_ isn't use, remember to disable option `APPNAME_USE_QML` in the **CMake** file).

//TODO: In app section README, add:
- Link to "icon README" file to explain structure
- Talk about QLogger

<!-- Links of this reposiory -->
[template-app]: app-template/
[template-lib]: library-template/

<!-- External links -->
[macos-metadata-doc]: https://developer.apple.com/documentation/bundleresources/information-property-list?language=objc
[macos-perm-network]: https://developer.apple.com/documentation/bundleresources/information-property-list/nslocalnetworkusagedescription/
[macos-perm-bonjour]: https://developer.apple.com/documentation/bundleresources/information-property-list/nsbonjourservices
[macos-perm-location]: https://developer.apple.com/documentation/bundleresources/information-property-list/nslocationusagedescription?language=objc

[pitchfork-repo]: https://github.com/vector-of-bool/pitchfork
[pitchfork-web]: https://web.archive.org/web/20231210061404/https://api.csswg.org/bikeshed/?force=1&url=https://raw.githubusercontent.com/vector-of-bool/pitchfork/develop/data/spec.bs

[qt-class-qsignalspy]: https://doc.qt.io/qt-6/qsignalspy.html

[repo-doxy-theme-awesome]: https://github.com/jothepro/doxygen-awesome-css
[repo-gtest]: https://github.com/google/googletest
[repo-helper-abstract-logger]: https://github.com/legerch/AbstractLogger

[tuto-doxygen]: https://github.com/legerch/develop-memo/tree/master/Documentation
