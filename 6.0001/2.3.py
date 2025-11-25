"""
Docstring for 6.0001.2.3

Finger Exercise: Write a program that asks the user to input 10 integers, and 
then prints the largest odd number that was entered. If no odd number was 
entered, it should print a message to that effect.
"""

def main():
    response={}# key=integer, value=odd/even
    max = None
    for i in range(10):
        a=int(input('Please input an integer: '))
        response[a]=a%2
        if a%2==1:
            if max == None:
                max=a
            elif a > max:
                max = a
    if 1 not in response.values():
        print("No odd numbers found!")
    else:
        print("The highest odd integer eneterd was:", str(max))


if __name__=="__main__":
    main()
