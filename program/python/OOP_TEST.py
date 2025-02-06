class Creature:
    def __init__(self,age,name):
        print("Creature_initialized")
        print("name:"+name)
        print("age:"+str(age))
        self.__age = age
        self.__name = name
    def get_age(self):
        return self.__age
    def get_name(self):
        return self.__name
class Gura(Creature):
    def __init__(self,age):
        self.age = age
        Creature.__init__(self,age,"Gura")
gura = Gura(9000)

