# Cpp Clippy

[![Cpp Clippy Test](https://github.com/cpp-clippy/cpp-clippy/actions/workflows/cpp-clippy.yml/badge.svg?branch=main)](https://github.com/ismaelJimenez/cpp-clippy/actions)
[![License: MIT OR Apache-2.0](https://img.shields.io/crates/l/clippy.svg)](#license)

A collection of lints to catch common mistakes and improve your C++ code.

More to come, please [file an issue](https://github.com/cpp-clippy/cpp-clippy/issues) if you have ideas!

Table of contents:

*   [Usage instructions](#usage)
*   [Configuration](#configuration)
*   [Contributing](#contributing)
*   [License](#license)

## Usage

Below are instructions on how to use Cpp Clippy as a terminal command.

### Step 1: Install Cpp Clippy

```terminal
$ git clone https://github.com/cpp-clippy/cpp-clippy.git
$ cd cpp-clippy
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build .
```

### Step 2: Run Cpp Clippy

Each check has a name and the checks to run can be chosen using the -checks= option, which specifies a comma-separated list of positive and negative (prefixed with -) globs. Positive globs add subsets of checks, and negative globs remove them. For example,

```terminal
$ cpp-clippy test.cpp -checks=-*,critical-*
```

## Configuration

## Contributing

If you want to contribute to Clippy, you can find more information in [CONTRIBUTING.md](https://github.com/cpp-clippy/cpp-clippy/blob/master/CONTRIBUTING.md).

## License

Copyright 2022 The Cpp Clippy Project Developers

Licensed under the Apache License, Version 2.0 <LICENSE-APACHE or
[https://www.apache.org/licenses/LICENSE-2.0](https://www.apache.org/licenses/LICENSE-2.0)>. Files in the project may not be
copied, modified, or distributed except according to those terms.
