# 👾 Conway_Game_of_Life ![Static Badge](https://img.shields.io/badge/Original-blue?style=for-the-badge)

![Static Badge](https://img.shields.io/badge/c-grey?style=flat&logo=c)
![Static Badge](https://img.shields.io/badge/Makefile-green?style=flat&logo=AnkerMake)
![Static Badge](https://img.shields.io/badge/status-completed-green?style=flat)

A simple simulation of the Conway's Game of Life using 42 School's Libft and Minilibx

## How to use it
Firstly, copy the repository into you computer directory

```bash
git clone https://github.com/alexpg7/Conway_Game_of_Life.git Conway_Game_of_Life
```

Once copied, just execute the `make` command

```bash
make
```

> [!WARNING]
> The **mlx_linux/configure** file can lead to some problems during the compilation.
> 
> To solve them, execute
> ```bash
> chmod 777 mlx_linux/configure
> ```
> And make sure to execute `make` multiple times until the executable **Conway** is created. (These errors are a minilibx issue, which was not programmed by me)

Finally, execute the program inputing **two parameters**

```bash
./Conway [grid] [resolution]
```

**[grid]** stands for the number of cells your simulation will have.

**[resolution]** stands for the resolution in pixels the window will have.


Once executed, the program should display a window with the simultaion, which cells have been generated randomply with a 60% chance each one.

To run the simulation you will have to press **S** for each step.

The simultaion stops when all the cells are killed or the window is closed.

## Example

As an example, the following command should display the following simultaion:

```bash
./Conway 100 800
```
![til](https://github.com/alexpg7/Images/blob/main/Conway/Simulation.gif)
