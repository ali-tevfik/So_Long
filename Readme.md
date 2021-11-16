# So_long

The idea is to create a 2D game with the help of the minilibX and X11 graphic server. The player has to collect the "collectibles" before he can leave the map through the exit(s). The map is a file ".ber" loaded as an argument of the executable. The number of moves are counted and the goal is to join the exit with the minimum number of moves.

This project only works on Linux and WSL, make sur you have installed the required elements to run the minilibX. For more information, check : [https://github.com/42Paris/minilibx-linux](https://github.com/42Paris/minilibx-linux)

![gif](https://user-images.githubusercontent.com/25388772/142031348-110f40c6-0da6-4d4a-add8-da01a1b9af43.gif)


| Character | Object |
| --- | --- |
| 1 | Wall |
| 0 | Empty |
| C | Collectible |
| E | Exit |
| P | Player |

### **Control of play**

You can use `AWSD` to move `UP`, `DOWN`, `LEFT`, `RIGHT`.For restart the game press `ESC` or click on the red cross of window. If you touch the enemy you loose the game. To win the game its necessary pick up all collectible and pass for the exit.

### Play

- Make
- ./So_long maps/[any .ber map respecting the criterias]
