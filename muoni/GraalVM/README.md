# Hadron

Hadron ~~is~~ will be a scripting language for scientific and mathematical programming. It runs on the GraalVM.

This is my fifth attempt at an implementation of the interpreter. The other four can be found in [this repo](https://github.com/JoelCourtney/muon).

## Installation and building

Install the GraalVM using the instructions [here](https://www.graalvm.org/docs/getting-started/). Be sure to set the PATH and JAVA_HOME env. variables correctly.

```bash
git clone https://github.com/JoelCourtney/hadron
cd hadron
mvn package
```

The build may take a while. To shorten it significantly, use:

```bash
export HADRON_BUILD_NATIVE=false
```

before running `mvn package`.

## Running

From the root of the repo, run:

```bash
./hadron <your file here>.hn
```

There is currently no REPL mode.

