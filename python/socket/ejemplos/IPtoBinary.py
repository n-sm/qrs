#! /usr/bin/env python
#
# esta funcion o hace mas que:
# ' '.join(format(int(x)), '08b' for x in ip.split('.'))

def ip2bin(ip):
    ipbytes=ip.split('.')
    ipbin=[]
    for x in ipbytes:
        ipbin.append(format(int(x), '08b'))
    return ' '.join(ipbin)

def ipand(ip1, ip2):
    if len(ip1) != len(ip2):
        print("ip1 y ip2 deben tener igual length")
        return 
    else:
        ipbytes1=ip1.split('.')
        ipbytes2=ip2.split('.')
        ret=[]
        for x, y in zip(ipbytes1, ipbytes2):
            ret.append(int(x) & int(y))
        return ret
