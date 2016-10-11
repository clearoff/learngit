#!/usr/bin/env python2
# -*- coding: utf-8 -*-


'''
class Student(object):


    def __init__(self,name='leap',score=99):
        self.__name=name
        self.__score=score
    def Print(self):
        print ("%s:%d" %( self.__name,self.__score))

obj=Student()
print hasattr(obj,'Print')
print hasattr(obj,'init')
fn=getattr(obj,'Print')
#   fn(obj,'hehe',33)    error
setattr(obj,'y',100)
print obj.y

'''


'''
class People(object):
    pass

leap=People()
leap.name="Leap"
print leap.name                                     #给实例绑定成员变量

def Set_age(self,x):
    self.age=x

from types import MethodType
leap.Set_age=MethodType(Set_age,leap,People)          #给实例绑定成员方法
leap.Set_age(20)
print leap.age
'''


'''
class People(object):
    pass

leap=People()
leap.name="Leap"
print leap.name                                     #给实例绑定成员变量

def Set_age(self,x):
    self.age=x

from types import MethodType
People.Set_age=MethodType(Set_age,None,People)       #为类的所有实例绑定成员方法
leap.Set_age(20)
print leap.age

He=People()
He.Set_age(25)
print He.age
'''


'''
class Student(object):
    @property
    def score(self):
        return self._score

    @score.setter
    def score(self,value):
        if not isinstance(value,int):
            raise ValueError("score must be int!")
        if (value<0 or value>100):
            raise ValueError("score must between 0 ~ 100!")
        self._score=value                    #注意缩进




Leap=Student()
Leap.name='leap'
Leap.score=60
print ( " %s:%d"%(Leap.name,Leap.score) )
'''

'''
class People(object):

   __slots__=("__name","__age")       #slots变量只在当前的类中有效，在继承的类中无效
   def __init__(self,name,age):
       self.__name=name               #成员名字前面加上双下划线表示该成员具有私有属性
       self.__age=age
   def Get_name(self):
        return self.__name
   def Get_age(self):
        return self.__age
   def Set_age(self,age):
        self.__age=age
#私有属性不嫩在类外进行访问
leap=People("Leap",18)
print leap.Get_name()
print leap.Get_age()
leap.__name="He"                     #这里虽然没有进行报错，但是leap.__name和类中的__ name 不是同一个成员变量
print leap.Get_name()               #在这里相当于又给实例Leap中添加了__name成员
print leap.__name
'''

#多重继承
class Animal(object):
    pass

class Running(object):
    def Run(self):
        print "Running"
class Flying(object):
    def Fly(self):
        print "Flying"

class Bird(Animal,Flying):
    pass
class Rabbit(Animal,Running):
    pass



pipi=Bird()
pipi.Fly()


