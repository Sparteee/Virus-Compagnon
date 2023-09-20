#!/bin/bash

echo "Compilation monPG1"
gcc `pkg-config --cflags gtk+-3.0` -o MonPG1 MonPG1.c `pkg-config --libs gtk+-3.0`

echo "Compilation monPG2"
gcc `pkg-config --cflags gtk+-3.0` -o MonPG2 MonPG2.c `pkg-config --libs gtk+-3.0`

echo "Compilation MediaPlayer"
gcc `pkg-config --cflags gtk+-3.0` -o MediaPlayer MediaPlayer.c `pkg-config --libs gtk+-3.0`

echo "Compilation des Programmes"
gcc -Wall MonPG3.c -o MonPG3 -lm
gcc -Wall MonPG4.c -o MonPG4
gcc -Wall MonPG5.c -o MonPG5
~                                                                               
~                                                                               
~                                                                               
~     
