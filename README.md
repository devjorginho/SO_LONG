# so_long

so_long is a simple 2D game project made with C and MiniLibX as part of the 42 curriculum.

## 🚀 How to Run

1. Clone this repository.
2. Extract the `minilibx-linux` archive (if present) or clone it manually.
3. Run `make` to compile the game.
4. Start the game by running `./so_long [map_file.ber]`

Example:

```bash
./so_long maps/map.ber
```

## 📜 Map Rules

- Must be rectangular
- Must be fully surrounded by walls (`1`)
- Must contain:
  - One player start position (`P`)
  - At least one exit (`E`)
  - At least one collectible (`C`)
- Only valid characters: `0`, `1`, `P`, `E`, `C`

### Example:

```
111111
1P0C01
1000E1
111111
```

## 🛠️ Dependencies

- `minilibx-linux` (must be extracted before running `make`)
- X11 libraries (Xext, X11, etc)

## 🎮 Controls

- `WASD` to move
- Collect all items and reach the exit to win the game

## 🧠 Notes

This project is part of the 42 school curriculum and is intended to teach basic graphics and game loop concepts using C.
