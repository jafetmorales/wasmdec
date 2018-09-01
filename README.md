# wasmdec
wasmdec is a program that converts WebAssembly binaries to C.

# Simple Example
wasmdec will translate this WebAssembly binary:
```wasm
(module
	(func $addTwo (param i32 i32) (result i32)
		(return
			(i32.add (get_local 0) (get_local 1))
		)
	)
	(export "addTwo" $addTwo)
)
```
To the following pseudo-C code:
```c
int fn_addTwo(int arg0, int arg1) {
	return arg0 + arg1;
}
```
# More practical examples

### [WebAssembly.org tanks demo](https://webassembly.org/demo/) (Unity project compiled to WASM)
wasmdec is capable of decompiling the entirety of [the tanks demo on the official WebAssembly site](https://webassembly.org/demo/):
* The main WebAssembly binary for the demo is avalible gzipped at https://webassembly.org/demo/Tanks/Build/tanks.wasm.code.unityweb 
* After extracting, wasmdec decompiles the entire binary and produces over 6.2 million lines of C.
* [The entire decompiled binary is avalible here](examples/tanks_decompiled.c)

### Diep.io (HTML5 web game written in C++ and compiled to WASM)
Diep.io is a real time web game written in C++ and compiled to WebAssembly via Emscripten.
* The WebAssembly binary is is always `http://static.diep.io/build_<BUILD HASH>.wasm.wasm`
* wasmdec decompiles the binary and produces ~400k lines of C
* [The decompiled binary is avalible here](examples/diep_decompiled.c)

### [WebDSP](https://github.com/shamadee/web-dsp) (a signal processing library compiled to WASM)
From the [WebDSP repository](https://github.com/shamadee/web-dsp):
```
WebDSP is a collection of highly performant algorithms, which are designed to be building blocks for web applications that aim to operate on media data. The methods are written in C++ and compiled to WASM, and exposed as simple vanilla Javascript functions developers can run on the client side.
```
* A compiled version of the library is avalible on the WebDSP demo page
* Decompiles to ~7k lines of C
* [The decompiled library is avalible here](examples/webdsp_decompiled.c)

# Applications
[A CTF write-up which uses wasmdec to reverse engineer a WASM binary](http://maroueneboubakri.blogspot.com/2018/04/nuit-du-hack-ctf-quals-2018-assemblyme.html)

# Installing with release

- Grab a release on the releases page and select the correct tarball for your OS and arch.
- Extract and run `install.sh` as root.

# Installing manually

## Getting the code
Clone the repository with
```bash
git clone https://github.com/wwwg/wasmdec.git --recursive
```
Make sure the recursive flag is set to clone all the submodules.
## Building
To build wasmdec and install all of it's dependencies, run `sudo make all` in the `wasmdec` directory. GCC 7 or higher is reccomended.

# Usage
```bash
wasmdec -o (output file) (options) input file
```
Where options is one of:
- `-e` or `--extra` : Writes extra information about the binary to output files (Obsolete when using memdump)
- `-m` or `--memdump` : Dumps the binary's memory to disk. Please note that if memdump ONLY dumps memory and doesn't perform any translation.
- `-d` or `--debug` : Print extra debug information to stdout