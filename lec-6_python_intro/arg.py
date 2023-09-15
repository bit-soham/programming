from sys import argv

for i in argv:
    print(i,'\n')
# to remove argv[0]
for a in argv[1:]: #we tell it to start from argv[1]
    print(a)