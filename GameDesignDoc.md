# Game Design Document
----

My game follows the adventure of a little pig who has learned how to fly. 
You control his flight with mouse clicks. YOU MUST CLICK ON THE PIG. 
If you do not click on the Pig initially, the game will start but the pig will not move. This will be a very boring and very quick game. 
Rather, the way to play the game is by clicking on the Pig. The first click will start the pig moving upwards. To get the pig to move back downwards, click again. Etc. 

Your pig is not alone in the sky though. There are obstacles, which are the '5 things' which he is supposed to avoid or go towards. 

Here is an image of the pig 
![Flying Pig](piggy.png "Flying Pig")

## 5 things
----
`1.` **Apple** The apple moves with the Background to the left at the same speed so that it seems that it is side scrolling with the background. This will give the Player 100 extra points. ![Apple](apple.png "Apple")
`2.` **Airplane** The Airplane moves very quickly but only in the x direction towards the left. Avoid the Airplane or else lose a life. ![Airplane](airplane.png "Airplane")
`3.` **Balloon** The Balloon's movement is slowly floating upwards and to the left. A collision withe Balloon will also lose a life. ![Balloon](balloon.png "Balloon")
`4.` **Hot Air Balloon** Similar to the Balloon but opposite, the Hot Air Balloon's movement is from the top to downwards and left. Avoid the Hot Air Balloon. ![Hot Air](hotair.png "Hot Air")
`5.` **Buildings** These are on the Bottom of the screen. They move only to the left but because they move at the same speed as the background, they do not seem exactly to be moving but rather to be scrolling with the background. Do not crash into the Buildings. ![Building 1](building1.png "Building 1")![Building 2](building2.png "Building 2")
`6.` **Bird** These are one of the tracking objects. It starts moving towards the Pig when it approaches a certain distance from the pig. ![Bird](bird.png "bird") 
`7.` **Jet** These move quickly in the x direction only. It tracks the Pig's original y direction and then charges towards it. ![Jet](jet.png "jet")
## Score Changes 
----

The score increases proportionately with the distance that the pig has travelled. Apples can get also increase the score. 
The score never goes down, only increases. 

## Lives 
----

The pig starts off with 3 lives. Every time he crashes into an obstacle, he loses a life. The game immediately ends when all his lives are gone. 

## Levels 
----

There are 3 levels in the game 
The first level generates only Apples, Airplanes, Balloons, Hot Air Balloons, and Buildings. 
The second level generates Apples, Airplanes, Balloons, Hot Air Balloons, Buildings, and Birds. 
The third level generates Apples, Airplanes, Balloons, Hot Air Balloons, Buildings, Birds, and Jets. 

With each progressive level, items move faster and are generated quicker. Also, there is more of a chance of an item being randomly generated. 

## Layout 
----
[Link to basic sketch](http://i.imgur.com/Y0la1TY.jpg?1?2180) 

## License 
----
GNU General Public License
[License](/LICENSE.txt) 

