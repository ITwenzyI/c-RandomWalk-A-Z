# Random Walk (A–Z) on a 10x10 Grid

This C program performs a **random walk** on a 10×10 grid, attempting to fill the grid from **A to Z** using a simple pathfinding method.  
The walk starts at the top-left corner (0,0) and continues until either **Z** is reached or the walker is **boxed in**.

## Features

- 10x10 grid filled with dots (`.`) initially
- Randomized movement in **four directions**: up, down, left, right
- The walker fills grid cells with sequential letters: A, B, C, ...
- Walk ends when:
  - Letter `Z` is placed
  - No valid adjacent cells are left


## Logic Overview

- The `pitch` is a 10x10 2D char array.
- A random direction is chosen at each step.
- If the next cell in that direction is within bounds and not visited (`'.'`), the letter is placed.
- If all directions are blocked, the walk stops.
- The grid is displayed before and after the walk.

## File Structure

- `fillpitch_points()`: Initializes grid with `.`
- `showpitch()`: Displays the current grid state
- `main()`: Handles the walk logic, direction checking, and loop control

## Author

Created by **Kilian**
