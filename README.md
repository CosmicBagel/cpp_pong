# cpp\_pong

it pong, wow

### Setup
```bash
git submodule update --init
cp CMakeUserPresets.sample.json CMakeUserPresets.json
cmake --preset Debug_x64
# or 
cmake --preset Release_x64
```

### Build
```bash
cd build/Debug_x64 # or Release_x64
make
```

### Running
Memory leaks can be spammy, to disable them
```bash
# inside debug build folder
EXPORT ASAN_OPTIONS=detect_leaks=0
./cpp_pong
```

### Lint
```bash
./lint.sh
```

