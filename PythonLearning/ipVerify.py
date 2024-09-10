import ipaddress as ip


a = '10.12.22.55'
b = '10.0.2.22'
c = '10.f.2.22'

aa = ip.ip_address(a)
bb = ip.ip_address(b)
cc = ip.ip_address(c)
print(aa)
print(bb)
print(cc)
