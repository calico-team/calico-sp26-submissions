# region
#imports
from collections import defaultdict
import math
import functools
import collections
import itertools
import re

def gcd(a,b,stepOperation = None):
    a, b = min(a,b), max(a,b)
    return g(a,b,stepOperation)
def g(a,b,stepOperation = None):
    if a == 0:
        return b
    if stepOperation:
        stepOperation()
    return g(b % a, a, stepOperation)
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
class Node:
    def __init__(self, children, is_sink):
        self.children = children
        self.is_sink = is_sink
    def __repr__(self):        
        return f"Node()"
def main():
    for _ in range(input_int()):
        h, w = input_interable_int()
        factory = []
        for i in range(h):
            factory.append(list(input_string()))
        dirs = [(0,1),(1,0),(0,-1),(-1,0)]
        def add_vector(a, b):
            return (a[0]+b[0], a[1]+b[1])
        def string_to_dir_index(s):
            if s == ">":
                return 0
            elif s == "v":
                return 1
            elif s == "<":
                return 2
            elif s == "^":
                return 3
        def get(l):
            if l[0] < 0 or l[0] >= h or l[1] < 0 or l[1] >= w:
                return None
            return factory[l[0]][l[1]]
        # visited = set()


        def make_tree(loc, dir_index) -> Node:
            v_head = get(loc)
            # print(f"make_tree({loc}, {dir_index}), v_head={v_head}")
            if not v_head: #this is for out of bounds
                return Node([], False)
            if v_head == "X":
                return Node([], True)
            if v_head == "S":
                node = Node([], False)
                for i,v in enumerate(dirs):
                    next_loc = add_vector(loc, v)
                    #validity check
                    if (i + 2) % 4 == dir_index:
                        continue
                    if get(next_loc) == ".": continue
                    node.children.append(make_tree(next_loc, i))
                return node
            #otherwise, it's a direction
            dir_index = string_to_dir_index(v_head)
            next_loc = add_vector(loc, dirs[dir_index])
            return make_tree(next_loc, dir_index)
        
        def add_flow(flow1, flow2):
            g = gcd(flow1[1], flow2[1])
            new_bottom = flow1[1] * flow2[1] // g
            print(f"add_flow({flow1}, {flow2}), new_bottom={new_bottom}")
            return (flow1[0] * (flow2[1] // g) + flow2[0] * (flow1[1] // g), new_bottom)
        def split_flow(flow, num_children):
            return (flow[0], flow[1] * num_children)
        outflows = (0,1)
        tree = make_tree((0,0), 0)
        def dfs(node, flow_rate=(1,1)):
            nonlocal outflows
            # print(f"dfs({node}, {flow_rate})")
            if not node.children:
                if not node.is_sink:
                    outflows = add_flow(outflows, flow_rate)
                return
            for child in node.children:
                new_flow_rate = split_flow(flow_rate, len(node.children))
                dfs(child, new_flow_rate)
        dfs(tree)
        g = gcd(outflows[0], outflows[1])
        outflows = (outflows[0] // g, outflows[1] // g)
        print(" ".join(str(x) for x in outflows))
    return
if __name__ == "__main__":
    main()