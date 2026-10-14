# Ariadne Satisfiability

Ariadne Satisfiability is the standalone C++20 bounded real satisfiability layer used by Ariadne.

## Layout

Public headers live under `include/satisfiability`, implementations under `src`, C++ tests under `tests`, benchmarks under `benchmarks`, Python bindings and tests under `python`, and standalone examples under `tutorials`.

The umbrella header is `include/ariadne-satisfiability.hpp`.

## Dependencies

Satisfiability currently depends directly on:

- [ariadne-cps/kernel](https://github.com/ariadne-cps/kernel), included as a Git submodule.
- [ariadne-cps/configuration](https://github.com/ariadne-cps/configuration), used for shared build configuration.

The Kernel dependency is temporary while the Symbolic module is being separated. Once Symbolic is standalone, Satisfiability will depend on Symbolic instead.

## Build

```bash
git clone --recurse-submodules https://github.com/ariadne-cps/satisfiability.git
cd satisfiability
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel --target everything
ctest --test-dir build --output-on-failure
```

## License

Ariadne Satisfiability is released under the GNU General Public License v3.0.
