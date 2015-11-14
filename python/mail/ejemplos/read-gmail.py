#!/usr/bin/env python

import sys, getopt
import smtplib
import getpass



gmail_user = sys.argv[-1]
if (gmail_user == 'read-gmail.py'):
    print "El usuario debe darse como parametro.\n"
    exit(0)

gmail_pwd = getpass.getpass('Password: ')
FROM = gmail_user+'@gmail.com'

#rta = ''
#preg = 'Seguro que quiere enviar a '

#while ( rta != 'S'):
recipient = raw_input('RECIPIENT: ')
#    rta = raw_input('%s"%s"? (S/n): ' % (preg, recipient))

TO = recipient if type(recipient) is list else [recipient]

#rta = ''
#preg = 'Es correcto el asunto '
#while ( rta != 'S'):
SUBJECT = raw_input('SUBJECT: ')
#    rta = raw_input('%s"%s"? (S/n): ' % (preg, SUBJECT))

#rta = ''
#preg = 'Es correcto el texto:\n'
#while ( rta != 'S' ):
TEXT = raw_input('BODY:')
#    rta = raw_input('%s\n"%s"\n? (S/n): ' % (preg, TEXT))    

#print "\nDATOS\n"
#print("From: %s\t\tTo: %s" % (FROM, TO))
#print("Subject: %s" % SUBJECT)
#print("TEXT:\n%s"% TEXT)

if (raw_input("Is ok? (S/n) ") != 'S'): exit(0)

# Prepare actual message
message = """\From: %s\nTo: %s\nSubject: %s\n\n%s
""" % (FROM, ", ".join(TO), SUBJECT, TEXT)
try:
    server = smtplib.SMTP("smtp.gmail.com", 587)
    server.ehlo()
    server.starttls()
    server.login(gmail_user, gmail_pwd)
    server.sendmail(FROM, TO, message)
    server.close()
    print 'successfully sent the mail'
except:
    print "failed to send mail"


