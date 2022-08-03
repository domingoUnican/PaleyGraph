# PaleyGraph
Algorithms to find the longest clique in a Paley Graph (or the complementary of the Paley Graph)
by using the library [Cliquer](https://users.aalto.fi/~pat/cliquer.html)

## Usage

The command to compile the executables is 
```
make clean && make
```

To execute the program for Paley graphs, type the following command:
```
./Paley <exponent> <modulo1> <modulo2> ...
```
For the complementary of Paley graphs, i.e. the undirect graph whose set of edges is the complementary set of edges, type the following command:
```
./CoPaley <exponent> <modulo1> <modulo2> ...
```

Previous attempts of algorithms have the same syntax and they are called previous1, previous2, etc.
