"""
Docstring for 6.0001.2.2

Finger Exercise: Replace the comment in the following code with a while loop.
"""

def main():
    numXs = int(input('How many times should I print the letter X? '))
    toPrint = ''
    # concatenate X to toPrint numXs times
    if numXs > 0:
        while numXs != 0:
            toPrint+='X'
            numXs-=1
    print(toPrint)

if __name__=="__main__":
    main()
