import csv

with open('favourites.csv', 'r') as file: # opened in o's and 1's
    reader = csv.DictReader(file) # converts it to csv form
        # when using the reader function the first row which may mention the title is also printed
        # to remove this we use next(row)
    ## Friends, The_Office, Game_of_Thrones, Stranger_Things, Brooklyn_Nine_Nine = 0, 0, 0, 0, 0

    counts = {}
    for row in reader: # each row is given to us as a list not as a string when reader is used
        #when DictReader is used insted of row[0,1,2,...]
        # you have to mention row['fieldname'] as it is read as a dictionary whose key will be afield name and you can then get the values

        favourite_movie = row["title"].lower()  # here now if we just change the title field to genres it will show the most popular genre # only one change will be needed


        ## f = favourite_movie.lower()
        ## if f == 'friends':
        ##     Friends += 1
        ## elif f == 'the office'
        ## .....
        ## ... this would get tiring so lets use list of dictionaries to count fo each movie that would be easier
        if favourite_movie in counts:
            counts[favourite_movie] += 1 # this is not going to create a key with the name of the movie in the counts  dictionary it is going to go to that key and increase the key's corresponding value by 1
        else:
            counts[favourite_movie] = 1

        # if reader is used
        # the second data in the row will be printed on using row[1]
        # this method could be unstable as the columndata could get switched but row[1] will represent the same
        # therefore dictreader is better
    for i in sorted(counts):   # here in aloop over a dictionary which has been sorted the variable goes over each of the keys int the dictionary
        if counts[i] > 10:
            # print(f"{i.upper()} : {counts[i]}")
            break

        elif counts[i] > 1:
             # print(f"{i} : {counts[i]}") # i is the name of that key
             break

    sorted(counts, reverse=True) # here dictionarry is sorted in reverse order


    # but these sortinds are innefficient in sorting for most liked movies
    # as the defualt key to sorting is the alphabetical order for dict it is of the title
    # so to sort according to the value of the movie name
    for i in sorted(counts, key = lambda x : counts[x], reverse=True): #the lamba fxn is passed on to the sorted fxn where it is called again and again and
    # lambda x : counts[x] means
    # def function(x):
    #     return counts[x]
    # and we sort the dictionary according to the No.s we give it in reverse order
        print(f"{i} : {counts[i]}")

    favourite = input("Favourite: ")
    if favourite.lower() in counts:
        print(f"Wow! {counts[favourite]} other people have watched {favourite.capitalize()}")
    else:
        print(f"Congratulations! you are the first to watch {favourite.capitalize()}")

