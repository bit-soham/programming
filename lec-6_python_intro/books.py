# creating a list of dictionaries

import csv
books = []

for i in range(3):

    title = input("book_title: ") # here they are just stored in variable it
    author = input("book_author: ") # could be called zoo for all i care

    book = {'Title': title, 'Author': author} # here the variablesa are allocated to the respective titles
    books.append(book)  # two keys
    # or
    Book = {}
    # this is how to modify input from the user
    Book['Title'] = input('book_title: ').strip().capitalize() #we can do this to modify the users input to become organized
    Book['Author'] = input('book_author: ').strip().capitalize() # we can do this in the above book dict also

    books.append(Book)



print(books)

