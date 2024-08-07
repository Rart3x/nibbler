#!/bin/sh

cmake --version;

if [[ $? == 127 ]]; then
	echo "Error: Need to install CMake first" ;
	exit ;
fi

git clone https://github.com/SFML/SFML.git
(cd SFML && cmake . && make);