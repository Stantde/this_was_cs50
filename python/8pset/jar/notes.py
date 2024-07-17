

class Student:
    def __init__(self, name, house):
       if not name:
          raise ValueError("Missing name")
       self.name = name
       self._house = house

    def __str__(self):
       return f'{self.name} from {self.house}'

    @property
    def house(self): #Think of this as a funciton, named house
        return self._house #instance variable is _house

    @house.setter
    def house(self, house):
        if house not in ['Gryffindor', 'Ravenclaw', 'Hufflepuff', 'Slytherin']:
           raise ValueError('Invalid House')
        self._house = house


def main():
    student = get_student()
    student.house = "Number Four, Privet Drive"
    print(student)

def get_student():
   name = input("Name: ")
   house = input("House: ")
   return Student(name, house)

if __name__ == "__main__":
   main()
