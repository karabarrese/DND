# 🎲 DND Mini-Game

A terminal-based mini-game written in C (Winter 2023), made for a friend's D&D campaign. The idea was to visualize a Zelda-style puzzle where you move a piece and all the other characters on the board move at the same time, some mirroring your direction, some doing the opposite. The goal is to solve the puzzle without any two pieces landing on the same square.

**Note: This project is unfinished.**

## How to Run

```bash
gcc Dnd-minigame.c -o dnd-minigame
./dnd-minigame
```

> Uses `fpurge(stdin)`, which is macOS-specific and may not compile on Linux.

## 🕹️ How It Works

1. Create a board by specifying its dimensions
2. Place characters on it with a symbol, starting position, direction, and behavior (follows your input or does the opposite)
3. Navigate with `W/A/S/D` all characters move simultaneously
4. You lose if two characters end up on the same square

## 📁 Project Structure
```
├── Dnd-minigame.c          # Main game logic
├── Executing version/      # Compiled version
├── Website/                # Companion web interface
└── examples/               # Example boards
```
