import timeit

def avg(list):
    return(sum(list) / len(list))


def test():
    x =2
    y=3
    x=x+1
    z=x+y
    return(z)
print(timeit.timeit('"-".join(str(n) for n in range(100))', number=10000))

x = timeit.repeat("test()", setup='from __main__ import test', repeat = 10)
x = avg(x)
print(x)
#print(x[1], sum(x)/len(x), sep='.\n')
#print(timeit.timeit("test()", setup='from __main__ import test'))
