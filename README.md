# so_long

A small 2D game written in **C** using the **MiniLibX** graphics library, developed as part of the 42 Lisboa curriculum.

## 🎮 About the Game

The goal is simple: collect all the collectibles (`C`) and reach the exit (`E`) without walking into walls (`1`).

The game uses a side-view platform style with pixel-art graphics and real-time keyboard controls.

## 📦 Requirements

Before compiling, make sure you **extract the `minilibx-linux` folder** from the archive if it's zipped (e.g., `minilibx-linux.zip`).

The `Makefile` expects the MiniLibX source code to be inside a folder named `minilibx-linux/`.

## 🧠 Features

- Loads and validates `.ber` maps
- Verifies map structure and path validity
- Renders a tile-based world with textures
- Handles keyboard input (`W`, `A`, `S`, `D`)
- Detects collisions and movement restrictions
- Tracks moves and prints them to the terminal
- Gracefully exits the game

## 🎮 Controls

- `W`, `A`, `S`, `D` – Move the player
- `ESC` – Quit the game

## 📜 Map Rules

- Must be rectangular
- Must be fully surrounded by walls (`1`)
- Must contain:
  - One player start position (`P`)
  - At least one exit (`E`)
  - At least one collectible (`C`)
- Only valid characters: `0`, `1`, `P`, `E`, `C`

### Example:

111111
1P0C01
1000E1
111111


## 🧱 Project Structure

.
├── src/ # Source code
├── inc/ # Header files
├── maps/ # .ber map files
├── assets/ # Sprites and textures
├── minilibx-linux/ # MiniLibX graphics library (must be extracted)
├── Makefile
└── README.md

## 🛠️ Build

```bash
make

🚀 Run

./so_long maps/map01.ber

✅ Built With

    gcc with -Wall -Wextra -Werror

    MiniLibX (Linux version)

    Tested on Unix-based systems (Ubuntu)

Made with love and low-level memory management 🧠💾
