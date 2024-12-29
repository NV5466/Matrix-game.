# Matrix-game.


Basically I want to design a turn based dnd type game on the terminal or beyond.
I have NO graphical knowledge. This so far has been purely output onto VSS. I have barely any knowledge of VSS.
But we ballin.


What I want.

I desire a system which will allow a set of randomly generated matricies that correspond to rooms in a video game. Each matrix will use values of:

0-empty space.
1-walls

The location of the numbers of course will follow procedural generation. Yet I currently have not determined how to do this with matricies.

NEXT, rotation, movement, and sight... 

Rotational values:
2-Default
3-up
4-right
5-down
6-left

Imagine you generate a random position on a matrix, it will appear on the matrix as the number 2, signifying a default rotational value. The reason for a default rotational value is simple. My current build sees that if you move up, the position moves up and the rotational value changes to up or 3. Now I have a working movement system. But what about sight? Sight will be a generated value that determines how far the player character or npc/s(enemy/s) can see. 

To allow a generated npc to not be spawned within 2 nanonmeters to avoid instant combat, I use taxicab distance < 2, to maximize the game time. 
Taxicab dist = abs(y2-y1)+abs(x2-x1)
  
  0 1 2 3 4 5
0 
