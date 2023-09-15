from cs50 import get_string, get_int, get_float

x = get_int("x: ")
y = get_int("y: ")

if x < y:
    print("nice y")
elif x == y * 2:
    print("damn")
else:
    print("hmm..")
for x in range(y - x):# it does not check if y belongs is netween (0,5) it just goes in loop y -x times
    # and y -x does not chanege with change in x as it is taken as a contant variable = y - x
    #x is being increased from 0 to  y - x
    # x = 7 , y = 46
    # print for 39 time starting with when x = 0 -> print once then..
    # therfore x = 38 at the print of 39th time
    print("yeah!")
    print(f"{x}")

print(f"{x}")

# for y in [0,1,2,3,4,5]:# it does not check if y belongs is netween (0,5) it just goes in loop 5 times
#     print("that's why")
#range(x,y) -> [x, y) in maths
for x in range(x, y): #the value of x start from  [y - x to y) or [y - x, y - 1]
    # x is 38 from previous and y = 46 now printing from [38, 45] 
# here the loop couno. of loop counts starts from x and end in y - 1
    #here the value of x inside brackets change
    print("!")









