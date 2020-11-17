# libshim-demo
Example usage of libshim to prevent runtime errors

### Building
```bash
export CC=/usr/bin/clang
export CXX=/usr/bin/clang++

mkdir -p build && cd build
cmake ..
make VERBOSE=1

LD_PRELOAD=./injector/libinjector.so ./binary/binary
```

### Output with symbols map (see [injector/shim_demo](https://github.com/Frago9876543210/libshim-demo/blob/master/injector/shim_demo))
```
injected into process

string_wrapper::string_wrapper("custom string from injector.so", 31)
custom string from injector.so
injector.so called string_wrapper::getBuffer(): "This data would be copied into heap"
string_wrapper::~string_wrapper()

string_wrapper::string_wrapper("regular string from this executable", 36)
regular string from this executable
binary called string_wrapper::getBuffer(): "This data would be copied into heap"
string_wrapper::~string_wrapper()
```

### Output without it (empty file)
```
injected into process

./binary/binary: symbol lookup error: ./injector/libinjector.so: undefined symbol: _ZN14string_wrapperC1EPcm
```
