#! /bin/bash

void charCheck() 
{   
    input_char=$1
    # CHECKING FOR ALPHABET 
    if [ $input_char -ge 65 ] && [ $input_char -le 90 ] || [ $input_char -ge 97 ] && [ $input_char -le 122 ] 
        then
        echo " Alphabet ";
    # CHECKING FOR DIGITS 
    elif [ $input_char -ge 48 ] && [ $input_char -le 57 ] 
        then
        echo " Digit "
           
    # OTHERWISE SPECIAL CHARACTER 
    else
        echo " Special Character "
    fi
}