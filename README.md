# GifGen

## Directory based GIF generator

This program uses the images present in a folder to generate a gif file
with customizable output and delay.

### Used Libs

- STB &lt;https://github.com/nothings/stb&gt;
- GifH &lt;https://github.com/charlietangora/gif-h&gt;

### Usage

<code>gifgen -d ./images -o ./outputs/final_gif.gif -m 500</code>

- -d | --directory &lt;frames directory&gt;
    - Define the image frames folder to generate the GIF file.
- -o | --output-path &lt;output path&gt;
    - Defines the GIF file output path.
- -m | --delay &lt;delay in ms&gt;
    - Defines the GIF frames delay in miliseconds.
- -h | --help
    - Shows the help message.
- -v | --version
    - Shows the program version, author information and licenses.

## For Devs

### How to compile

During the development of this program, the g++ 21.1.2 compiler present in llvm was used.

<code>g++ -std=c++20 -Iinclude -Ivendor src/*.cc -o bin/gifgen --static -flto -DNDEBUG -O3</code>

- g++
    - C++ compiler
- -std=c++20
    - Uses the 2020 C++ standard major revision
- -Iinclude
    - Defines the header files location
- -Ivendor
    - Does the same as -Iinclude, but reports the path to the lib headers
- src/*.cc
    - Defines the source code implementation files
- -o bin/gifgen
    - Defines the output binary file location
- --static
    - Compiles statically without dependencies
- flto
    - Uses link time optimization
- -DNDEBUG
    - Defines the NDEBUG macro, that means "no debug"
- -O3
    - Defines the max optimization pattern