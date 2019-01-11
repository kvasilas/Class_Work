#student1, fireman, and doctor are all parts of the human class.

class Human:
    def __init__(self,Name, Gender, Age):
        self.gender = Gender
        self.age = Age
        self.name = Name

    def run(self):
        print('{name} is running.'.format(name=self.name))

class Student1(Human):
    def study(self):
        print('%s is studying.' % self.name)

class fireman(Human):
    def fire(self):
        print('%s is fighting fire.' %self.name)

class doctor(Human):
    def docting(self):
        self.name = 'Dr. '+self.name
        print('%s is checking temperatures.' %self.name)


student = Student1('David','male',23)
a = fireman('Joe', 'male', 30)
b = doctor('Mary', 'female', 28)

print(student.gender, student.age, sep="\n")
student.run()
student.study()
a.fire()
b.docting()
