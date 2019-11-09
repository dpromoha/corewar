# corewar

Corewar is a final project on algorithm branch for school 42.
This is my part of project, where I have to build a virtual machine where 'champions' written in an abstract assembly language fight over a defined memory space. Also I used a library *ncurses* for visualization.

The processes are executed sequentially within the same virtual machine and memory space. They can therefore, among other things, write and rewrite on top of each others so to corrupt one another, force the others to execute instructions that can damage them, try to rewrite on the go the coding equivalent of a Côtes du Rhône 1982 (that is one delicious French wine!), etc.

**HOW TO USE:**

make

./corewar players/Octobre_Rouge_V4.2.cor  players/toto.cor players/maxidef.cor players/slider2.cor

*(or use another champion in directory players/)*


**USAGE:**

![Снимок экрана 2019-11-09 в 21 15 32](https://user-images.githubusercontent.com/46355522/68533831-3b865c80-0336-11ea-8b52-c10c936ae405.png)


**VISUALIZATION:**

![ezgif com-video-to-gif](https://user-images.githubusercontent.com/46355522/68534426-3b3d8f80-033d-11ea-91bf-3d9bacb5cb48.gif)

