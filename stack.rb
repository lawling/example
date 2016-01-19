#!/usr/bin/ruby

class Stack
@arr=[]
def add x
arr.append x
end

def print
p arr
end

s = Stack.new()

s.add 1
s.print
