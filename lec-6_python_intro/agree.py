s = input("Do you agree? ")

# if s == "Y" or s == "y" or s == .....:

# # OR

# if s in ['Y', 'y', 'Yes', 'yes', .....]

# best
s = s.lower()
if s in ['y', 'yes']:
    print("agreed.")
elif s in ['n', 'no']:
    print('Not agreed.')
