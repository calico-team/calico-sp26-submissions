import sys
def solve () :
    data=sys.stdin.read().strip().split()
    t=int(data[0])
    idx=1
    res=[ ]
    for _ in range (t):
        L= int(data[idx]); W =int(data[idx+1]);E=int(data[idx+2]);R=int(data[idx+3])
        idx +=4
        rec_area = 2*(L+W)
        laps = E //(rec_area *R)
        res.append( str ( laps ) )
    sys.stdout.write("\n".join( res ))
def read_your_input( ):
    solve( )
if __name__=="__main__" :
    solve( )