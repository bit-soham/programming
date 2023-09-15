# # for a dictionary
# people = dict()

# #or

# people = {}



# people = list()

# #or

# people = []



people = { # inputing into a dictionary
    "soham": "8585007278",
    "carter": "9783287289"
}

name = input("Name: ")
if name in people: #this code checks through the first column of the dictionary and assumes it to be the key and links it to 'name'
    print(f"Number: {people[name]}") #it prints the corresponding value
# here [ ] signifies that what is inside is the key therefore return the corresponding value of the string


phone_number = input('Phone number: ')
if phone_number in people.values(): #with this it checks the second column of the dict and assigns them as values linking them to the name 'phone_number
    # but it does not read the keys
#### print(f"{people[phone_number]}")   # but you cannot print the corresponding key with this
    #this will show error
    print(f"hello {phone_number}")
else:
    print()


phone_No = input("Phone_no. : ")
for name, No in people.items(): # this will read both columns and form tuples then we can read them when they are linked
    if No == phone_number:  # here for loop has to be used
        print(f"hello, {name}") # now we can acces the key if value is provided
