"""
Docstring for 6.0001.3.1

Finger Exercise: Write a program that asks the user to enter an integer and 
prints two integers, root and pwr, such that 0 < pwr < 6 and root**pwr is equal 
to the integer entered by the user. If no such pair of integer exists, it 
should print a message to that effect.
"""

def main():
    LOWER_BOUNDARY=0
    UPPER_BOUNDARY=6
    integer=int(input('Please input an integer: '))
    root=-1
    pair_exists=False

    while root < integer and pair_exists==False: # Does not work for negative numbers. Should I adjust for them?
        root+=1
        for pwr in range(LOWER_BOUNDARY, UPPER_BOUNDARY):
            if (root)**pwr == integer:
                pair_exists=True
                break
    if pair_exists:
        print(f"{root}**{pwr}={integer}.")
    else:
        print("No such pair exists!")

if __name__=="__main__":
    main()
