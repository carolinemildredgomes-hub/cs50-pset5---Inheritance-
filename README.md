# CS50 Pset: Inheritance

Simulate inheritance of blood types across a family tree (CS50 Harvard, Problem Set: Inheritance).

## What this does
- Builds a family tree with `N` generations (default 3).
- Oldest generation gets random alleles (`A`, `B`, or `O`).
- Each younger person inherits one allele from each parent (randomly chosen).
- Prints the family tree with blood types and frees allocated memory.

## Files
- `inheritance.c` — C implementation (complete).
- `README.md` — this file.

## Run locally (cs50.dev)
```bash
# in your home dir
wget https://cdn.cs50.net/2024/fall/psets/5/inheritance.zip
unzip inheritance.zip
cd inheritance
# replace inheritance.c with the provided one (or edit)
make inheritance
./inheritance

Alternatively compile directly:

gcc -o inheritance inheritance.c -std=gnu11 -Wall -Werror
./inheritance

Change number of generations

Edit the #define GENERATIONS 3 in inheritance.c to the desired value, or compile with:

gcc -DGENERATIONS=4 -o inheritance inheritance.c -std=gnu11 -Wall -Werror

Troubleshooting
malloc failure: unlikely in this small program; check available memory.

segmentation fault: ensure you did not manually alter the parent/allele logic incorrectly.

make fails: compile with gcc (see direct compile command above).

Memory leaks: run valgrind --leak-check=full ./inheritance if available.
