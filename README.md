<div id="top"></div>

# Assembly Emulator

## About The Project
This is an Assembly Emulator written in C++ language. It supports an easier version of RISC (Reduced Instruction Set Computer) instruction set, so that it's more readable for user, and also easy to understand. Therefore, it does not support some fancier instructions or addressing modes featured by older Complex Instruction Set (CISC) designs. 

_For more information about the language used, please refer to the handouts section_

### Built With
* [C++](https://www.cplusplus.com/)

## Getting Started

If you want to set up this project locally, you should read this section

### Prerequisites
You must have g++ installed in order to run this program.
  #### Linux
  ```sh
  $ sudo apt install build-essential
  ```
  #### Windows
  Check out how to install g++ on Windows [here](https://www3.cs.stonybrook.edu/~alee/g++/g++.html)

### Installation

Clone the repo
   ```sh
   git clone https://github.com/Aiushta96/Assembly-Emulator.git
   ```

## Usage

### Compile and run
In order to compile and run the project, use the following commands:

```sh
   g++ *.cpp && ./a.out
```

### Execute an assembly file
After running the project, you'll need to test it by a file in which assembly instructions are written. I've provided some [tests](https://github.com/Aiushta96/Assembly-Emulator/tree/main/Tests) which you can also use. If you want to know what particular test file really does, you must know that almost every test file has its corresponding C file, so if you're not familiar with those instructions, you can see what C code translates into this assembly file.

## License

Distributed under the MIT License. See `LICENSE.txt` for more information.
