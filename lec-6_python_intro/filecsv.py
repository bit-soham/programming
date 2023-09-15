import csv

with open("filecsv.csv", "a") as file: #append mode means we want to write row wise or line wise

    name = input("Name: ")
    number = input("Number: ")

    # to write rows to a csv file
    writer = csv.writer(file) # this says python to treat this as a csv file
    writer.writerow([name,  number]) # write in a row



    # instead of the above 2 lines  which fixes name to the write and number to the left we can use
    #here it is in a format of a csv dictionary
    #where we write field names of the file like this one key and another value
    writer = csv.DictWriter(file, fieldnames = ["name", "number"])
    # then we input and specify which field it belongs to
    writer.writerow({"name": name, "number": number})











# file.close()
# # close is a function present in data structure of file