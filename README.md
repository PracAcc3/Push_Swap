This project has been created as part of the 42 curriculum by <synoshah>.

# push_swap

`push_swap` takes a list of unique integers and prints a sequence of operations(like `sa`, `pb`, `ra`) that will sort them.

- Stack **a** starts with my numbers.
- Stack **b** starts empty.
- Goal: sort **a** in ascending order using only the allowed operations, with as few moves as possible.

## Build & run

- Build: `make`
- Clean objects: `make clean`
- Full clean: `make fclean`
- Rebuild: `make re`

Run with many arguments:

- `./push_swap 2 1 3 6 5 8`

Or Run with one string:

- `./push_swap "2 1 3 6 5 8"`

Validate with the checker:

- `ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG`

## Input rules

Acceptable format:
- `./push_swap 3 2 1`
- `./push_swap "3 2 1"`

Rejected inputs:
- non-numeric tokens
- numbers outside `int` range
- duplicates

On any invalid input, the program prints `Error` to stderr and exits.

## How the algorithm works (human overview)

This project uses a greedy “cheapest move” approach.

- For 2 numbers: swap if needed.
- For 3 numbers: a small special-case sorter.
- For bigger inputs:
  1) Push a couple of elements from **a** to **b**.
  2) While **a** still has more than 3 elements:
     - For every node in **a**, compute where it should land in **b** (its `target_node`).
     - Compute the cost in rotations to bring both the node and its target to the top.
     - Pick the cheapest node, use `rr` / `rrr` when both stacks rotate the same way, then `pb`.
  3) Sort the last 3 in **a**.
  4) Push everything back from **b** to **a**, always aligning the target first.
  5) Finish with a final rotate so the minimum value is on top.

## Behavior notes

- Empty input or already-sorted input: prints nothing and exits cleanly.
