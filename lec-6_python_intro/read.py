import csv

books = []

# add books to your shelf by reading from books.csv
with open("books.csv") as file:
    # for normal reader it does not include keys and values it also prints the first row always
    file_reader = csv.DictReader(file) # it reads the entire file in the form of a dictionary
    for l in file_reader: #reads lines individualy as it is in the form of a dictionary
        print(l)# prints the line
        books.append(l)

print(books) # prints entire list in the list form

for z in books:
    print(z['author']) #prints the corresponding value of the key author in that line