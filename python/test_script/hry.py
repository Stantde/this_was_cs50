#this isnt a real change 12/11/2023
def special__dict__print(d):
    print("__dict__:")
    for k, v in d.items():
        print(f"  '{k}': {v}")


class Student:
    def __init__(self):
        self.name = "1"  # normal
        self._name = "2"  # semi-private (please don't access/change this from outside)
        self.__name = "3"  # "truly private" (you can't easily access/change this from outside, don't even dare to try it, please)
        self.___name = "4"  # same as __name

    def __str__(self):
        return f"{self.name}, {self._name}, {self.__name}, {self.___name}"

    def change(self):
        print("Changing inside:  a, b, c, d")
        self.name = "a"
        self._name = "b"
        self.__name = "c"
        self.___name = "d"


s = Student()
print("Initial:", s)
special__dict__print(s.__dict__)
print()

print("Normal name:", s.name)
print("Semi-private _name:", s._name)
try:
    print("Private __name:", s.__name)
except AttributeError as e:
    print("Private __name:", e)
try:
    print("Private ___name:", s.___name)
except AttributeError as e:
    print("Private ___name:", e)
print("Private? _Student__name:", s._Student__name)
print("Private? _Student___name:", s._Student___name, "\n")

print("Changing outside: 5, 6, 7, 8")
s.name = "5"
s._name = "6"
s.__name = "7"
s.___name = "8"

print(f"Changed outside?: {s.name}, {s._name}, {s.__name}, {s.___name}")
print("Changed inside?: ", s)
special__dict__print(s.__dict__)
print()

s.change()
print(f"Changed outside?: {s.name}, {s._name}, {s.__name}, {s.___name}")
print("Changed inside?: ", s)
special__dict__print(s.__dict__)
print()

print("Changing outside: w, x, y, z")
s.name = "w"
s._name = "x"
s._Student__name = "y"
s._Student___name = "z"
print(f"Changed outside?: {s.name}, {s._name}, {s._Student__name}, {s._Student___name}")
print("Changed inside?: ", s)
special__dict__print(s.__dict__)
print()
