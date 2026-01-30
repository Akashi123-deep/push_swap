
*This project has been created as part of the 42 curriculum by mel-yazi*

---

## 📖 Description

The goal of **push_swap** is to sort a random stack of integers using two stacks (`a` and `b`) and a limited set of operations. You must develop an optimized algorithm to sort the data with the **minimum number of moves** possible.

---

## 🛠️ Instructions

### Build

| Command | Description |
|---------|-------------|
| `make` | Compile and create the `push_swap` executable |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and executable |
| `make bonus` | Compile the bonus checker program |

### Usage

```bash
./push_swap 3 2 1 5 0
```
```bash
./push_swap "3 2 1 5 0"
```
```bash
./push_swap "4 3 2" "44" 0 "9"
```

---

## 📚 Allowed Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first two elements of stack A |
| `sb` | Swap the first two elements of stack B |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push the top element of B onto A |
| `pb` | Push the top element of A onto B |
| `ra` | Rotate stack A (first element becomes last) |
| `rb` | Rotate stack B (first element becomes last) |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack A (last element becomes first) |
| `rrb` | Reverse rotate stack B (last element becomes first) |
| `rrr` | `rra` and `rrb` at the same time |

---

## 🧠 Algorithm

| Stack Size | Approach |
|------------|----------|
| 3 elements | Hardcoded simple logic |
| 100–500+ elements | **Turk sorting algorithm** (on indexed values) |

---

## 🔗 Resources

- 📖 [Push Swap Explained (Medium)](https://medium.com/@simonzerisenay/push-swap-mastering-sorting-algorithms-with-42-37e9ab4f9a40)
- 🎨 [Visualizer Tool](https://push-swap42-visualizer.vercel.app/)

---

## 🤖 AI Disclosure

> AI tools were used to help explain and understand the sorting algorithm used in this project. We did not ask AI for the final answers or the main code.

---