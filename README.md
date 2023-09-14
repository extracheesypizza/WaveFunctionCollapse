# Wave Function Collapse Visualization
![](res/preview.gif)

This neat little application allows users to behold the power of the Wave Function Collapse algorithm by creating random generative pictures of [mostly not functional] PCBs.

## How to build
1. ```git clone``` the repository
2. Run  ```git submodule init && git submodule update``` to download the SFML Library (it will take some time and may seem stuck, but be patient)
3. For Windows run ```cmake -S . -B build/ -G "MinGW Makefiles" -DBUILD_SHARED_LIBS=OFF && cd build && make && .\WFC```
4. For MacOS/Linux run ```cmake -S . -B build/ -DBUILD_SHARED_LIBS=OFF && cd build && make && ./WFC```

## How to use:
- Wait for the algorithm to finish its sketch
- Press "Backspace" to start over