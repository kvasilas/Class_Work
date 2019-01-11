# A simple example:

class Complex:
    '''
    This is a class for complex numbers
    '''
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def conjugate(self):
        return Complex(self.a, -self.b)

    def modulus(self):
        return pow(self.a**2+self.b**2, 0.5)


    def __repr__(self):
        '''
        Representation
        '''
        return '{a}+{b}i'.format(a=self.a,b=self.b)

    # (a+bi)+(c+di) = (a+c)+(b+d)i
    def __add__(self, cplx):
        '''
        Adding operator (+)
        '''
        tmp_a = self.a + cplx.a
        tmp_b = self.b + cplx.b
        return Complex(tmp_a, tmp_b)

    # (a+bi)*(c+di) = (ac-bd)+(bc+ad)i
    def __mul__(self, other):
        '''
        multiply operator (*)
        '''
        a, b = self.a, self.b
        c, d = other.a, other.b
        return Complex(a*c-b*d, b*c+a*d)

#--------------------------------------------------------
c1 = Complex(1,2)
c2 = Complex(4,5)
c1.a, c1.b
print(c1)
print(c2)
c3 = c1*c2

print(c3.a, c3.b)
