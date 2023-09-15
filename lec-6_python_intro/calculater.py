
# x = input("x: ")# input function always returns a string
# y = input("y: ")

# print(f"{x + y}")
# #or
# print(x + y)
# # is same as
# print("hello" + y)





x = int(input("x: "))
y = int(input("y: "))

print(f"{x + y}")# f means formating something in ()
#or
print(x + y)
print(x/y)

# here floating point imprecition occurs after 15/16 decimal points
print(f"{x/y:.50f}")# f is just like % in c which allows here to finetune no. of decimal digits
# .50 means 50 digits after decimal  and f means data type will be float

