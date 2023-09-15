from cs50 import get_float
from math import floor

# global variable
c = 0


def main():
    change = get_change()
    
    if change > 0:
        quarters = no_of_quarters(change)
    else:
        quarters = 0

    if c > 0:
        dimes = no_of_dimes()
    else:
        dimes = 0

    if c > 0:
        nickels = no_of_nickels()
    else:
        nickels = 0
    if c > 0:
        pennies = no_of_pennies()
    else:
        pennies = 0

    print(f"{quarters + dimes + nickels + pennies:.0f}")

# get change till proper value given


def get_change():
    while True:
        change = get_float("Change owed: ")
        if change > 0:
            change *= 100
            change = round(change)
            return change


def no_of_quarters(n):
    global c
    quarters = floor(n / 25)
    c = n - quarters * 25
    return quarters


def no_of_dimes():
    global c
    dimes = floor(c / 10)
    c -= dimes * 10
    return dimes


def no_of_nickels():
    global c
    nickels = floor((c) / 5)  # floor functon 3.9 -> 3
    c -= nickels * 5

    return nickels


def no_of_pennies():
    return c


main()