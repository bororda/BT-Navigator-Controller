# Intro

This is a Bluetooth based smartphone controller for the comfortable interactions with your navigation (not limited to but mainly with OsmAnd, Locus Map and Rally Roadbook Reader app) while riding your bike.

Current models are designed to be mounted over the grips, i.e. no manipulation with the handlebar setup is required other than just securing the controller on the left hand grip.

Right now there're two versions:
1. **V1** which is quite wide and eats up a lot of grip space, plus it's looking rather basic. Still functioning well, and if printed out of nylon is rigit as hell.
2. **V2 aka Slim** redesigned controller. Also exploring the options to switch to a smaller board to improve the size of the board and battery box. Practically this is the second iteration.

# How to get one
1. Get the list of components listed in [MAC Parts](controller/Reference/parts.numbers) or [Excel Parts but w/o pics](controller/Reference/parts.xlsx)
2. Order the 3D prints. Models located [here](controller/Reference/casing) - you gotta chose between the tested V1 and V2 Slim which is still in dev.
3. Flash the board. V1 is based on ESP32 Wroom - a bigger board, but the wiring and the code should work fine. V2 yet to come.
4. Assemble the project. You'll need a soldering iron!
5. Turn the device on and connect it to your smartphone
6. Configure the apps on the phone to react to the keys properly

# Outro
This project was inspired by another free project [rallyrampage](https://www.rallyrampage.com/product/bluetooth-navigation-handlebar-controller-version-1-7-3-6b/)
You cannot reinvent something so simple, but i did put some efforts to make the controller look just a bit nicer and reduce the costs of the components.
