_This project has been created as part of the 42 curriculum by syedh._

# Description
push_swap sorts a stack of unique integers using a limited instruction set and prints the operations. Stack **a** starts filled, stack **b** starts empty. The goal is the fewest moves while respecting the 42 rules (no globals, proper errors, no leaks, Norm compliance).

## How it works (quick tour)
- **Parsing & checks**: Accepts multiple args or one space-separated string. Validates syntax, INT range, and duplicates. On any error: frees and prints `Error` to stderr.
- **Data model**: Doubly linked list nodes hold `nbr`, `index` (0-based), `above_median` (rotation hint), `push_cost`, `cheapest`, and `target_node`.
- **Small sizes**: 2 elements -> swap if needed. 3 elements -> rotate largest down, swap if top two are out of order.
- **General case (>3)**:
  1) Push two elements from **a** to **b**.
  2) While **a** has >3 unsorted: compute targets and costs, pick the cheapest node, use double-rotations when both halves match, then `pb`.
  3) Sort the remaining 3 in **a**.
  4) For each node in **b**, target the closest-bigger in **a**, align, then `pa`.
  5) Finish by rotating the minimum to the top of **a**.
- **Cost idea**: `push_cost` = moves to bring the chosen **a** node to top + moves to bring its target in **b** to top; median flags decide rotate vs reverse.

## Error handling expectations
- Non-numeric, overflow, duplicates -> `Error` to stderr and exit.
- Empty input or already-sorted input -> no output, clean exit.

# Instructions
- Build: `make`
- Clean objects: `make clean`
- Full clean: `make fclean`
- Rebuild: `make re`
- Run: `./push_swap 2 1 3 6 5 8`
- With one quoted arg: `./push_swap "2 1 3 6 5 8"`
- Validate with checker (provided by subject): `ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG`

# Resources
- 42 subject PDF for push_swap
- References: linked list basics (any C data structures primer), rotation/swap operations per subject
- AI usage: Used an AI assistant to help draft this README and summarize the algorithm; all code and logic were reviewed and understood before inclusion.
