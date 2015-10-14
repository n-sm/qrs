import poplib
import getpass
from email import parser

# debe activarse el acceso para aplicciones 'poco seguras'



pop_conn = poplib.POP3_SSL('pop.gmail.com')
user = raw_input("user: ")
pop_conn.user(user)
pw = getpass.getpass("Pasword: ")
pop_conn.pass_(pw)
#Get messages from server:
messages = [pop_conn.retr(i) for i in range(1, len(pop_conn.list()[1]) + 1)]
# Concat message pieces:
messages = ["\n".join(mssg[1]) for mssg in messages]
#Parse message intom an email object:
messages = [parser.Parser().parsestr(mssg) for mssg in messages]
for message in messages:
    print message['subject']
pop_conn.quit()
