from cs50 import get_string


#printf -> print
print("hello,world")

answer = get_string("What's your name? ")

print("hello, " + answer) # here it is concatinating each string in both side of plus
print("hello,", answer) # here the print fxn gives you a  free space separating each of the variable

#f indicates that the curly braces are not to be printed literally or it is like a pointer
print(f"hello, {answer}")
