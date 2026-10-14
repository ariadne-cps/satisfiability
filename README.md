# Ariadne Satisfiability

Ariadne Satisfiability is the standalone C++20 bounded real satisfiability layer used by Ariadne.

## Layout

Public headers live under `include/satisfiability`, implementations under `src`, C++ tests under `tests`, benchmarks under `benchmarks`, Python bindings and tests under `python`, and standalone examples under `tutorials`.

The umbrella header is `include/ariadne-satisfiability.hpp`.

## Dependencies

Satisfiability depends directly on:

- [ariadne-cps/symbolic](https://github.com/ariadne-cps/symbolic), included as a Git submodule.
- [ariadne-cps/configuration](https://github.com/ariadne-cps/configuration), used for shared build configuration.


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
