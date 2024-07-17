'''
[TODO] Your project must be implemented in Python.
[TODO] Your project must have a main function and three or more additional functions. At least three of
those additional functions must be accompanied by tests that can be executed with pytest.
Your main function must be in a file called project.py, which should be in the “root” (i.e.,
top-level folder) of your project.
Your 3 required custom functions other than main must also be in project.py and defined at the same
indentation level as main (i.e., not nested under any classes or functions).
Your test functions must be in a file called test_project.py, which should also be in the “root” of
your project. Be sure they have the same name as your custom functions, prepended with test_
(test_custom_function, for example, where custom_function is a function you’ve implemented in
project.py).
You are welcome to implement additional classes and functions as you see fit beyond the minimum
requirement.
Implementing your project should entail more time and effort than is required by each of the
course’s problem sets.
Any pip-installable libraries that your project requires must be listed, one per line, in a file
called requirements.txt in the root of your project.

'''
import argparse
import book
import os
import sys
'''
Version 1: Make a journal lol
Version 1.5: Add some entries
Version 2: Load journal for viewing
Version 3: add security
'''

'''
Version 1
'''
'''
Ask user to open or create journal
    if create
        ask for all to pass to book
        next ask for first entry
        next ask to review , new entyr, new(book?)
    if open
        find it
        if pwd
            check pwd
                pass open
                fail reject
'''

def main():
    #Starts main loop
    #11/20/2023 this just opens the journal. The main loop is adding pages? Work on structure later.
    notebook_creation_loop = True
    while notebook_creation_loop:
        print_create_load_or_exit()
        answer = input('Please make choice from the above, then press enter.\n\t').strip().upper()
        create_open_exit = start(answer, 0)
        if create_open_exit == 'X':
            print("Exiting program")
            sys.exit(1)
        elif create_open_exit == 'C':
            active_journal = create_new_journal()
        elif create_open_exit == 'O':
            # Load existing journal and set to active journal
            ...
        elif create_open_exit == 'E':
            # Exit program
            if active_journal:
                print(f"Saving changes to {active_journal}")
            # Save book then exit
            print("Closing program")
            sys.exit(0)
        #add_page()

        '''
        # Add first entry
            # Choose random writing prompt
            # writing_prompt=
            entry_body = input("What's on your mind today?")
        '''
        print(active_journal)
        notebook_creation_loop = False
        ...
    page_creation_loop = True
    while page_creation_loop:
        page_creation_loop = False
        ...

def print_create_load_or_exit():
    starting_options = ['(C)reate a new journal', '(O)pen an existing journal',
                        '(E)xit']
    for _ in starting_options:
        print(_)
    return None

# Recursively validate entry is C, O, E. If not, ask for user response. If user does not cooperate
# by third attempt, return 'X' (code to exit program).
def start(user_answer, count):
    expanded_options = ['C', 'O', 'E']
    if len(user_answer) > 1:
        user_answer = user_answer.lstrip('(')[0]
    if user_answer in expanded_options:
        return user_answer
    print("Invalid selection")
    if count < 2:
        print_create_load_or_exit()
        user_answer = input('Please make choice from the above, then press enter.\n').strip().upper()
        start(user_answer, count + 1)
    return 'X'

def create_new_journal():
    affirmative_answers = ['y', 'yes']
    # Create new journal
    if input('Would you like to specificy a location to store your new journal? \
            \nEnter "y" or "yes".\n\t').lower().strip() in affirmative_answers:
        default_filepath = input('Please enter the desired filepath: \n\t')
    else:
        default_filepath = ''
    journal_name = input('What would you like to call your journal? \n\t')
    answer = input('Would you like to secure your new journal? \
                   \nEnter "y" or "yes" to secure.\n\t').lower()
    if answer in affirmative_answers:
        password = input('Please enter a password: ')
    else:
        password = None
    return book.Notebook(fp=default_filepath, name=journal_name, pwd=password)


if __name__ == '__main__':
    main()
