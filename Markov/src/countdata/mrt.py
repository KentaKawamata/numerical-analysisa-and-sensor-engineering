with open('sortcharactor.txt', 'r') as fp:

    text = fp.read()
    moji = " & "
    text = text.replace(" ", moji)
    text = text.replace("\n", "\\\\\n")

with open("latchar.txt", "w") as fp:
    fp.write(text)
