#!/usr/bin/env python
# encoding: utf-8

class Matrix4():

    """Docstring for Matrix4. """

    def __init__(self,x1,x2,y1,y2):
        self.x1=x1
        self.x2=x2
        self.y1=y1
        self.y2=y2

    def __mul__(self, m):
        M = Matrix4(self.x1* m.x1 + self.x2* m.y1, self.x1*m.x2+self.x2*m.y2,self.y1*m.x1+self.y2*m.y1,self.y1*m.x2+self.y2*m.y2)
        return M


def pow_for_matrix4(count, m):
    M = Matrix4(1, 0, 0, 1)
    N = m
    while count != 0:
        if count & 1 == 1:
            M *= N
        N *= N
        count >>= 1
    return M

def perimeter(n):
    s=Matrix4(1,1,1,0)
    ans = pow_for_matrix4(n+1,s)
    an = ans.y1
    an_1 = ans.y2
    return (an*2 +an_1 -1)*4

print(perimeter(5))
