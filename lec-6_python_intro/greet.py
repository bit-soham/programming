from sys import argv   # to use command line argument

if len(argv) == 2: #argc = len(argv)
    print(f"hello, {argv[1]}")
else:
    print("hello, world")