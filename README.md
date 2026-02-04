*This project has been created as part of the 42 curriculum by analaphi*

## Description

Minitalk is a short project that introduce the use of UNIX signals, the goal is to have two executable named server and client, where you can write whatever you want in it and it is supposed to be recievied by the server who will write it down too. You'll need to encrypt the message because the server cannot receive ASCII character directly, so I processed with a encryption via bit shifting. 

## Instruction

In order to execute both of the programms, you'll need to open two different terminal. One where you will use the basic commands of Makefile to compile with **make**, and execute the server executable with **./server**. If the syntax is not good, I left some help in the terminal that will make this process more easy.
This will give you the unique server PID needed to send messages with the client. The PID will change randomly at every launch of the server, assuring security to it.

When this is done, you can execute the client in the other terminal with **./client PID TEXT**, and enjoy ! Not much more to say, again if the syntax is not good my program will tell you with some errors how to use it.

## Ressources

