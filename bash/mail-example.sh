#!/bin/bash
SUBJECT="mail de prueba"
TO="smnicolas@gmail.com"
MESSAGE="./message.txt"



/usr/bin/mail -s "$SUBJECT" "$TO" < $MESSAGE
