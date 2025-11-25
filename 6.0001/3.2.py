"""
Docstring for 6.0001.3.2

Finger Exercise: Let s be a string that contains a sequence of deciaml numbers 
separated by commas, e.g. s='1.23,2.4,3.123'. Write a programs that prints the 
sum of the numbers in s.
"""

def main():
    s='1.23,2.4,3.123'
    a=s.split(',')
    for index in range(len(a)):
        a[index]=float(a[index])
    print(sum(a))
    
if __name__=="__main__":
    main()
