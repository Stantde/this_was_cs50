"""
Home Federal Savings Bank

In season 7, episode 24 of Seinfeld, Kramer visits a bank that promises to give $100 to anyone who
isn’t greeted with a “hello.” Kramer is instead greeted with a “hey,” which he insists isn’t a
“hello,” and so he asks for $100. The bank’s manager proposes a compromise: “You got a greeting
that starts with an ‘h,’ how does $20 sound?” Kramer accepts.

In a file called bank.py, implement a program that prompts the user for a greeting. If the greeting
starts with “hello”, output $0. If the greeting starts with an “h” (but not “hello”), output $20.
Otherwise, output $100. Ignore any leading whitespace in the user’s greeting, and treat the user’s
greeting case-insensitively.

Hints
Demo

Before You Begin
Log into cs50.dev using your GitHub account.
Click inside the terminal window and execute cd.
Execute wget https://cdn.cs50.net/2022/fall/labs/6/bank.zip followed by Enter in order to download
a zip called bank.zip in your codespace. Take care not to overlook the space between wget and the
following URL, or any other character for that matter!
Now execute unzip bank.zip to create a folder called bank.
You no longer need the ZIP file, so you can execute rm bank.zip and respond with “y” followed by
Enter at the prompt.
How to Test
Here’s how to test your code manually:

Run your program with python bank.py. Type Hello and press Enter. Your program should output:
$0
Run your program with python bank.py. Type Hello, Newman and press Enter. Your program should
output:
$0
Run your program with python bank.py. Type How you doing? and press Enter. Your program should output
$20
Run your program with python bank.py. Type What's happening? and press Enter. Your program should output
$100
You can execute the below to check your code using check50, a program that CS50 will use to test your code when you submit. But be sure to test it yourself as well!

check50 cs50/problems/2022/python/bank
Green smilies mean your program has passed a test! Red frownies will indicate your program output something unexpected. Visit the URL that check50 outputs to see the input check50 handed to your program, what output it expected, and what output your program actually gave.

How to Submit
No need to submit! This is a practice problem.
"""
'''
def main():
    # Prompts the user for a greeting. If the greeting
    greeting = prompt_user().lower()
    if "hello" in greeting:
        # Output $0
        print(f"$0")
    elif greeting.lstrip().startswith('h'):
        # Output $20

        print(f"$20")
    else:
        # Output $100
        print(f"$100")


def prompt_user():
    # Ask user for a greeting
    user_response = input("Please input a greeting. ")
    # Return the user's input
    return user_response


main()
'''
def main():
    greeting = prompt_user().lower()
    money = value(greeting)
    print(money)
    ...


def value(greeting):

    if "hello" in greeting:
        # Output $0
        return f"$0"
    elif greeting.lstrip().startswith('h'):
        # Output $20

        return f"$20"
    else:
        # Output $100
        return f"$100"

def prompt_user():
    # Ask user for a greeting
    user_response = input("Please input a greeting. ")
    # Return the user's input
    return user_response


if __name__ == "__main__":
    main()