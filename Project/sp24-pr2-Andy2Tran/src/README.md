# Assignment Source Code

This is where all of your source code should go for assignments. You should not be putting files anywhere else in your repo.

Here is some more information you might want to to include in your Code Style.

- your name and student ID
- the structure of your program (both file organization and high-level functional organization)
- the status of your program (e.g. it works completely, it compiles but doesn't run, it compiles and runs but doesn't work in certain cases, some features are missing etc.)
- what hardware platform(s) you tested it on.
- how to compile the program (e.g. "run 'make my-hw1-solution' using the submitted makefile") and how to run it.
- any other information that you want to communicate with the graders and other reviewers of your submission

# Project 2
- Name: An Tran
- Student ID: 110709381

## Structure
Program includes:
1. Board(.cpp/.h)
2. Cell(.cpp/.h)
3. Game(.cpp/.h)
4. GameManager(.cpp/.h)
5. GameObject(.cpp/.h)
6. Item(.cpp/.h)
7. itemBox(.cpp/.h)
8. Player(.cpp/.h)
9. Token(.cpp/.h)
10. main.cpp

I don't have time to make a UML Diagram so I'll explain it here:
- Board controls the main grid which are 2d vectors of cells
- cells are objects that hold GameObject pointers which is a base class so that all the game ojbects in the game can be hold in a cell
- GameObject is a base class with two subclasses: ItemBox and Token
- ItemBox holds a vector of items
- Token links with player to represent the physical space player takes on the grid
- Players have all of the actions they can take
- Game initalizes all of the data for a game
- GameManager manages the high level game environment such as rounds and game ending summary
- main.cpp is just the starting menu

Text Files:
1. Game-Settings.txt
2. Game-Summary.txt
3. Master-Item-List.txt

Game-Settings.txt
- Structured: key:value
Master-Item-List.txt
- Structured: name,cost,points,type

## Current Status: Complies but game doesn't run as intented
Known issues:
- I believe x and y are backwards for some inputs
- Game can read from text files but when trying to start from game settings it doesn't work
- Players should only be able to move once per turn and use one item per turn
- Powerups and debuffs aren't implemented yet
- Game-Summary.txt wasn't written to with the overall summary

## Manuel
This is Shopping Showdown (but incomplete and broken). Features of my version:
- Item Box can be used multiple times and move themselves after each open
- Game is structure in rounds where each player would get a turn
- During a players turn they are prompt with a menu where they can choose to move adjacent to themselves or use a powerup or debuff on themselves or an opponent
- Players should only be able to move once and use one item per turn (But I didn't get to that)
- The game ends when all of the rounds are over and the winner is the person with the most points

## Hardware Platforms
- Wrote and ran on my local machine
- macOS: Sonoma 14.1.2
- using c++ 14

## How to compile program
- Note that some of the paths for the text files might be different depending on how your running the program.
- Use this command in the terminal: `g++ -std=c++14 *.cpp -lpthread -o main.exe`
- Execute using `\.main.exe`
- main.cpp is the starting menu
