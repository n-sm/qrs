#!/usr/local/sin/env python

import os

net = '192.168.1.'
ipsT=[net + str(ip) for ip in range(255)]
outFile = 'test.txt'

#response = os.system("ping " + hostname)

output = []
for ip in ipsT:
    res = os.popen("ping " + str(ip)).read()
    output.append(red)

with open(outFile, 'w') as f:
    for out in output:
        f.write(out)
        
