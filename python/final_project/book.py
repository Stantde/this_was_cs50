'''
book.py contains the outline of a journal. It contains methods for constructing the book-type,
adding pages to the book, loading pages into memory for review, saving books. When the book
constructor is called
an object with a unique identifier visible to the system only, a name established by the user, the
journal's filepath for data persistence, a size which reflects the number of associated pages, and
a password for securing the data is created.
'''
MAGIC_NUMBER = 1

class Notebook:
    def __init__(self, fp ='', id=None, name='Default Journal Name', size=0, pwd = None):
        '''
        The creation of Journal will be handled through the class's __init__ function.
        __init__ will take as it arguments:
        fp, the filepath for the journal to allow data persistence.
        id , a unique id assigned to every journal.
        name, a name for the journal determined by the user.
        size, number of pages associated with book.
        (optional) pwd, a password for the journal chosen by the writer.
        '''
        # take time and date pass through hash to get 5 digit id. self.capacity = capacity
        if not id:
             self._id = self.generate_id(MAGIC_NUMBER)
        else:
             self._id = id
        self._name = name
        self._fp = fp
        self._pwd = pwd
        self._size = size
        self._entries = []

    def __str__(self):
        return self._name

    # Class methods
    def generate_id(self, input):
        # Hash the input
        # Return the hashed input
        return input


    # Creates a new entry. Entry is then added to the book.
    # Is this an entry or a page?
    def add_entry(self, input_text):
         #add input text to a dictionary object including date-time, and page number
         a = {'date-time' : now(),
              'page number' : self._size + 1,
              'entry text' : self.encrypt(input_text)}

         self._entries.append()
         ...

    #opens book to a page.
    def open_book(self, entry_number):
        ...

    #saves the notebook
    def save_book(self, n):
        ...

    def encrypt(input):
        # encrypt data with casear cipher
        return input

    def withdraw(self, n):
        if self._size - n < 0:
            raise ValueError
        else:
            self._size = self._size - n


    # Getters
    @property
    def pwd(self):
        return "That wouldn't be very secure.\nBut since you asked so nicely: \
            self._pwd = {self._pwd}" #self._pwd

    @property
    def fp(self):
        return self._fp

    @property
    def name(self):
        return self._name

    @property
    def size(self):
        return self._size

    # setters
'''
    @capacity.setter
    def capacity(self, capacity):
        # If capacity is negative, raise value error
        if capacity < 1:
            raise ValueError('The capacity value is not valid for cookies!')
        self._capacity = capacity
'''
