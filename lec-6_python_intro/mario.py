from cs50 import get_int



def main():
    hieght = get_hieght()
    for i in range(hieght):
        print('#')


def get_hieght():
    while True:
        try:     ##try to do this
            n = int(input("Hieght: "))
            if n > 0:
                return n
        except ValueError: # if a value error occurs then do this
            print("Not a integer")
            # after this it will loop back to line
        else:
            break


main()