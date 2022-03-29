# OatppStartDemo

An oatpp demo using MSVC and CMake as build tools.

Refer to the following links:

[oatpp-starter](https://github.com/oatpp/oatpp-starter)

### Project-layout

```plainText
│  .gitignore
│  CMakeLists.txt
│  README.md
│
├─.vscode
│     settings.json
│
├─src
│  │  App.cpp
│  │  AppComponent.hpp
│  │
│  ├─controller
│  │  MyController.cpp
│  │  MyController.hpp
│  │
│  └─dto
│     DTOs.hpp
│
├─test
│  │  MyControllerTest.cpp
│  │  MyControllerTest.hpp
│  │  tests.cpp
│  │
│  └─app
│     MyApiTestClient.hpp
│     TestComponent.hpp
│
└─utility
      install-oatpp-modules.sh
```

### Build and Run

You must build oatpp library first. Then replace the variable `OATPP_PATH` to the location on your computer.

```bash
> mkdir build & cd build
> cmake...
> make
>./OatppServerDemo.exe
```