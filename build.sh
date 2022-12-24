#! /bin/bash
cd $1 && make
if [ "$2" == "-i" ]
    then
        echo "Installing $1"
        sudo make install
fi