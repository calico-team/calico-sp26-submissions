# region
#imports
from collections import defaultdict
import math
import functools
import collections
import itertools
import re

#functions
def rrr(num, decimal_places = 0):
    num *= pow(10, decimal_places)
    decimal = abs(num) - abs(num) // 1
    if (num >= 0) == (decimal >= 0.5):
        return (num // 1 + 1) / pow(10, decimal_places)
    else:
        return (num // 1) / pow(10, decimal_places)

def input_string(): return input().rstrip()
def input_float(): return float(input_string())
def input_int(): return int(input_string())
#_iterables
def input_interable_float(sep = " "): return map(float, input_string().split(sep))
def input_interable_int(sep = " "): return map(int, input_string().split(sep))
def input_interable(sep = " "): return input_string().split(sep)
def string_format_float(v, decimal_places, total_length, round = True):
    if round:
        v = rrr(num=v, decimal_places=decimal_places)
    return f"{v:0{total_length}.{decimal_places}f}"
def str_is_int(s):
    try:
        int(s)
        return True
    except ValueError:
        return False

def rad(a):
        return a / 360 * 2 * math.pi
def deg(a):
    return a * 360 / (2 * math.pi)
def mag(v):
    return (v[0] ** 2 + v[1] ** 2) ** 0.5
def rd(num, decimal_places=0):
    p = pow(10, decimal_places)
    num *= p
    if math.ceil(num) - num < num - math.floor(num):
        return math.ceil(num) / p
    return math.floor(num) / p
# #core

# def core(
        
# ):
#     outputs = []
#     return outputs

#endregion

#input cycle
def main():
    for _ in range(input_int()):
        a = list(input_string())
        b = list(input_string())
        o = list("#" for i in a)
        for i in range(len(a)):
            if not b:
                break
            if b[0] == a[i]:
                b.pop(0)
                o[i] = a[i]
        print(''.join(o))
    return
if __name__ == "__main__":
    main()