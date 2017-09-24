# __System Requirements Specification__

![](http://training-course-material.com/images/5/57/HowProjectsReallyWork.png)

## Functionality
1. Allows a user to play a game of hearts/crazy eights.
2. Allows 4 people to play.
3. AI can fill in empty player slots. (Ability to play alone).
4. Maintains active game state.
    * Keeps track of players' hands
    * Keeps track of game history
    * Keeps track of game play
5. Ability to follow the rules of the game as outlined (See Appendix A).
    * (i.e. Shuffle, Deal, etc) 
6. Allows players to choose different AI levels.
7. Allows players to check player rankings.
8. Allows players to restart the game.
9. A lobby which allows players to see available games. 


> ### Out of Scope
> * AI vs AI
> * ELO Ratings
> * Voice Activation
> * Mods
> * Multilingual support
> * Offline Play

## Usability
1. Play Area.
* Rules accessible through Help Menu.
* Allows a player to see how many cards in other players hand.
* Allows a player to see game history.
* Allows a player to see all the cards in play.
* Allows players to create profiles.
* Allows players to log in to profiles.
* Help Menu.


## Reliability 
1. On connection loss fill in players with AI.
* Infrastructural consistency of Amazon Web Services.
* Can predictably connect to server.

## Performance
System Requirements
> * Operating Systems: Windows 8.1+, Debian and Derivatives, Mac OS
> * RAM: 2GB
> * Network Card
> * Screen
> * Processor (functioning)


## Supportability
1. Support will continue until December 2016
* Supported Countries: USA
* Will run on all supported operating systems (See Performance).
* Will run software tests.

## Verification Method

Test Number|Test performed|Acceptable Criteria 
---|---|---
F.02|Four clients connect to the server|All four can play
F.03|Human Client disconnects|AI fills empty player slot
F.06|User designates AI Level|AI level is set
F.07|User clicks "Ranking"|Ranking is shown
F.08|User clicks "Restart"| Game restarts
F.09|Player enters lobby|a wild lobby appears
U.01|User Clicks Game Menu > New Game|a wild play area appears
U.02|User clicks help menu -> rules|Wild rules appear
U.03|User Clicks Game Menu > New Game|The number of cards in each players hands are visible
U.04|User clicks on History|a wild history appears
U.05|User Clicks Game Menu > New Game|User can see all cards in play
U.06|User Clicks "Create Profile"|Profile is created
U.07|User Clicks "Login"|Client Login Successful
U.07|User Clicks Game Menu > Help|Help menu is shown
R.01|User disconnects|AI connects|
R.03|User attempts to connect to|User successfully connects|
P.01|User Runs Game Program | Program runs
S.01|User posts report on github | devs respond|
S.02|User connects in US|Program works|
S.03|Tests conducted on supported platforms|Tests pass|
