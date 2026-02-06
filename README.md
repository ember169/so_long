__This project has been created as part of the 42 curriculum by lgervet__
# so_long - A small 2D game
This project is a small 2D game. Its purpose is to work with textures, sprites, and other basic gameplay elements.<br>
[Subject (pdf)](cdn.intra.42.fr/pdf/pdf/185033/en.subject.pdf)<br>

## Description
2D top-down game developed as part of the 42 Common Core curriculum. The goal is to create a basic engine using the MiniLibX library, focusing on window management, event handling (keyboard and mouse), and sprite rendering. <br>

### The game
The player must collect all items on the map and reach the exit in the shortest number of moves possible.
- **Graphics:** 2D tileset-based rendering.
- **Controls:** WASD or Arrow keys to move.
- **Mechanics:** Move counting in the terminal, wall collisions, and collectible management.

### Technical constraints
- **Library:** Developed using MiniLibX (simple graphics library for X Window System).
- **Memory Management:** Zero memory leaks allowed (checked with valgrind).
- **Error Handling:** The program must parse .ber map files and handle invalid configurations (missing exit/player/collectible, non-rectangular maps, or unreachable goals) by displaying a clean Error message.
- **Algorithm:** Includes a pathfinding check (iterative flood fill) to ensure the map is actually playable before launching.

## Instructions

### Compilation
__Building ...__

### Execution
__Building ...__

# Ressources

## Documentation
- [Stacks vs. Queues: The Dynamic Duo Behind BFS, DFS, and Flood Fill, Medium, 2025](https://mkyush.medium.com/stacks-vs-f00c85620ea5)
- [Flood fill, Wikipedia](https://en.wikipedia.org/wiki/Flood_fill)
- [Depth-first search, Wikipedia](https://en.wikipedia.org/wiki/Depth-first_search)
- [Basic Graph Theory (BFS, DFS, and Floodfill), Albert GURAL, 2011](https://activities.tjhsst.edu/sct/lectures/1112/bfsdfs100711.pdf)
- [Backtracking, Wikipedia](https://en.wikipedia.org/wiki/Backtracking)

## AI Usage
I used AI (Gemini 3 Flash) as a low-level technical advisor and logic validator. The collaboration focused on resolving build system conflicts, debugging pointer-level issues in the graphics engine, hardening and debugging a path-validation algorithm.

### Build System & Toolchain Debugging
- **Linker error resolution:** Assisted in diagnosing and fixing "multiple definition" errors in the Libft archive by identifying stale object files.
- **Makefile optimization:** Helped refine the build rules, specifically fixing path variable typos (e.g., `LIB_PATH` vs `LIBPATH`) that caused recursive compilation failures.

### Graphics Engine Logic (MiniLibX)
- **Coordinate mapping:** Identified a critical inversion between X (columns) and Y (rows) coordinates during the translation from the 2D map array to the pixel-based window display.
- **Rendering optimization:** Diagnosed a logic error where the rendering loop was drawing diagonal lines instead of filled tiles during testing phase with `mlx_pixel_put`.

### Map Validation & Algorithmic Logic
- **Iterative flood fill logic:** presented the core logic of the pathfinding algorithm to verify the reachability of all collectibles ('C') and the exit ('E').
- **Logic hardening:** Identified and corrected a major security flaw in the pathfinder that would have incorrectly validated maps with an unreachable exit.