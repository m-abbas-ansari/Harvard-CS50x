# TODO
import csv
import cs50
from sys import argv
# Checking valid command line argument
if len(argv) != 2:
    print("Error")
    exit()

# Opening students.db
db = cs50.SQL("sqlite:///students.db")

# Reading csv file
with open(argv[1], 'r') as read:
    characters = csv.DictReader(read)

    # iterating through each row in dictionary
    for row in characters:
        # setting name
        name = row["name"].split(" ")
        first = name[0]
        if len(name) == 2:  # if no middle name
            last = name[1]
            middle = None
        else:
            middle = name[1]
            last = name[2]
        house = row["house"]
        birth = int(row["birth"])

        # Inserting row into database
        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?,?,?,?,?)", first, middle, last, house, birth)