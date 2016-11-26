##Minesweeper
Minesweeper is a popular puzzle game distributed with Windows OS.

###Objective
Reveal the blocks without detonating the mines.

###How to play
Number on each block indicates the number of mines in the surrounding blocks.

The numbers are used as hints to determine if a block contains a mine or not.

You can flag the blocks that you suspect to contain mines to help you keep track of mines.

You win the game when you've revealed all the safe blocks on board.

##About this clone
This is a clone of minesweeper made for educational purposes. It's written in C and based on ncurses. It's built in a modular way. Each modules works with others to make the whole system work.

##Modules
Each module does a specific job and communicates with other modules to keep the system running. Modules communicate with each other by calling and/or passing data.

List of modules:

- render_board
- generate_map
- keyboard_listener
- generate_mines
- make\_map\_visible
- reveal_block
- in_map
- unrevealed\_good\_blocks
- number_blocks
- randon_number
- new_game_options
- new_game

###render_board
It draws the board on the screen. It provides an interface for the user to play the game. It's called whenever the board is updated. It's because the changes are buffered and rendering works absolutely, not relatively.

###generate_map
A `map object` is created which holds info about the board.

#####Map object
The object is used to store info about the board.

It stores the following attributes:

- Flag
	- `0/1`
- Visibility
	- `0/1`
- Number
	- `0` nothing
	- `1-8` number of mines
- Mine
	- `0/1`
 
###generate_mines
Random locations are picked and mines are placed there.
###keyboard_listener
It listens to the keyboard for commands.

| Key         	| Command     					|
| ---------------|---------------------------------|
| WASD     		| Movement of selector	       	|
| Q     			| Flag					       	|
| E     			| Reveal block			       	|
###make_map\_visible
It makes the entire map visible. It's called when the user clicks on a mine and the game ends.
###reveal_block
It reveals a specific block along with nearby blank blocks (not numbered). It's recursive which means it calls itself, passing the blank blocks in the surrounding in each call. This module is responsible for making large part of the board visible (giving you that smile).
###in_map
It determines if a given location is within the board.
###unrevealed_good\_blocks
It counts the blocks in the map which are good (hold no mine) and unrevealed.
###number_blocks
It goes through every single block on board and numbers them. Number equals the mine count in the surrounding (8 max).
###random_number
Generate a random int, simple as that!
###new_game
It prepares and sets up the stage so the user can play.
###new_game_options
It provides an UI for options of the new game.

##Board UI

| Block         | Character     			|
| ------------- |-------------------------|
| Invisible     | x			          	|
| Blank         | [empty_space]		  	|
| Numbered      | 1-9					  	|
| Flagged       | !					  	|
| Mine          | *					  	|

##Game options
You can choose between 4 options:

1. Beginner
2. Intermediate
3. Expert
4. Custom

###Easy
It'll present a 20x10 board with 30 mines.
###Intermediate
It'll present a 40x20 board with 300 mines.
###Expert
It'll present a 80x40 board with 600 mines.
###Custom
You get to choose the dimensions of the board along with the mine quantity.