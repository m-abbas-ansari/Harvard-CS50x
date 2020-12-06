# TODO
import csv
import cs50
from sys import argv
# Checking for valid command line args
if len(argv) != 2:
    print("Error")
    exit()

# Opening database
db = cs50.SQL("sqlite:///students.db")

# Storing SQL query in a dictionary called query{}
query = {}
query = db.execute("SELECT first,middle,last,birth FROM students WHERE house = ? ORDER BY last, first", argv[1])

# iterating through dictionary
for row in query:
    first = row["first"]
    middle = row["middle"]
    last = row["last"]
    birth = row["birth"]
    # Check for middle name
    if middle == None:
        print(f"{first} {last}, born {birth}")
    else:
        print(f"{first} {middle} {last}, born {birth}")