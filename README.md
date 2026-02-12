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
- [MLX events, 42 Docs](https://harm-smits.github.io/42docs/libs/minilibx/events.html)
- [At Least I Know How to Manipulate an MLX Image, Medium, 2025](https://medium.com/@efinda/at-least-i-know-how-to-manipulate-an-mlx-image-%EF%B8%8F-c2a74ff7b0e5)

## AI Usage (Gemini 3 Flash)
Technical advisor for build system debugging, memory optimization, and algorithmic hardening.

### Build & Graphics
- **Linker Fix:** Resolved "multiple definition" errors by diagnosing stale object files in `libft.a`.
- **Makefile:** Fixed recursive build failures caused by path variable typos (`LIB_PATH` vs `LIBPATH`).
- **Coordinate Mapping:** Corrected Row/Column inversion during 2D-to-pixel translation.
- **Rendering:** Fixed diagonal-line artifacts by refactoring the `mlx_pixel_put` loop logic.

### Logic & Validation
- **Geometry:** Removed incorrect `row_nb == col_nb` restriction (rectangles include squares).
- **Pathfinding:** Hardened flood-fill logic to prevent false positives on unreachable exits/collectibles.
- **Memory:** Refactored assets from heap-allocated pointers to stack-allocated structures.
- **Layering:** Solved XPM transparency issues via a background-first (floor-under-all) rendering pass.

### Data Architecture
- **Structural Encapsulation:** Implemented a top-level `t_game` container to unify window, map, and asset structures. This simplifies event handling by allowing a single reference pointer to be passed through MiniLibX hooks.
- **Pointer Type Correction:** Refactored MLX resource pointers from `int *` to `void *` to ensure alignment with library specifications and prevent undefined behavior.

## Game assets
All game assets credit goes to [Robert (0x72)](https://0x72.itch.io/16x16-dungeon-tileset).