# Design

The final design is comprised of a client file main.cc, which has the main function and connects with the interface file to create the game. The interface file asks the user to input the race of the player. Then the floor is created which adds in all the items including the potion and treasure as well as the characters including enemies and players. After all of this has been created, player movement including attacking and picking up items, is expected or the player can also choose to quit or restart the game. The game is played throughout this way until the user finishes the last floor, HP is 0 or if the player restarts the game. 

#Design Techniques
We have used inheritance, factory pattern and singleton to implement the program. 

#Inheritance:
Inheritance is used a lot in this program because there are many classes that are very similar to one another but with its special traits. For example, all the player races such as Shade, and Vampire all inherit from Player class and all enemy races including Human and Dwarf inherit from Enemy class. Then Player and Enemy classes inherit from the character class. This is the same case with all the items in the game. All the potions such as RH, BA inherit from Potions class and all treasure such as small and normal inherit from the Treasure class. Then Treasure and Potion inherit from Item class. 

#Singleton:
We have used singleton when implementing the Player class as there should only be one Player per game.

#Factory Method:
Player, Potion, Enemy and Treasure were created through Factory Method.  There are playerfactory.cc, enemyfactory.cc and itemfactory.cc files. These files determine what specific player, enemy or item must be created and are responsible for creating it.
