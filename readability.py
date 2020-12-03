import cs50
from cs50 import get_string

text = get_string("Text: ")
ct_let = 0  # counter of letters
ct_words = 1  # counter of words
ct_sent = 0  # counter of sentences

# iterating through each character in text
for char in text:
    # counting number of letters
    if char.isalpha() == True:
        ct_let += 1
    # counting number of white spaces to find no. of words
    if char.isspace() == True:
        ct_words += 1
    # counting number of sentences
    if char == '.' or char =='!' or char == '?':
        ct_sent += 1

# Coleman-Liau Formula Application
L = float((float(ct_let) / float(ct_words)) * 100)
S = float((float(ct_sent) / float(ct_words)) * 100)
index = round((0.0588 * L) - (0.296 * S) - 15.8)  # Coleman-Liau index
# Checking index and printing appropriate grade
if index < 1:
    print("Before Grade 1")
elif index < 16:
    print(f"Grade {index}")
else:
    print("Grade 16+")