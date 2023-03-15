
# Name: Parvez Hossen
# ID:   174049

"""
Solve the cryptarithmetic problem using Constraint Satisfaction Problem.  Assign Minimum Remaining Valued variables first.
Variables: F T U W R O X1 X2 X3
Domains: {0,1,2,3,4,5,6,7,8,9}
Constraints: Alldiff (F,T,U,W,R,O).
O + O = R + 10 · X1
X1 + W + W = U + 10 · X2
X2 + T + T = O + 10 · X3
X3 = F
T > 5, F ≠ 0
"""

var={
    'o':-1,'w':-1,'t':-1,'r':-1,'u':-1,'f':-1
}

st1="two"
st2="two"
sm="four"

carry=0
res={}

# This problem was solved using Backtraing algorithm
def bt(d,ind,c,visit):
    print(d,visit)

    if ind==len(st1):
        res=d.copy() #res contain final variable
        return

    st1ind=len(st1)-1-ind #traverse input string from right to left
    smind=len(sm)-1-ind
    if d[st1[st1ind]]==-1:
        for i in range(1,10):
            crry=(i+i+c)//10 # carry after summing two digit
            val=(i+i+c)%10 # value for result
            if val!=i and (i not in visit) and ((val not in visit) or d[sm[smind]]==val) and (d[sm[smind]]==-1 or d[sm[smind]]==val): # required condition for backtracking
                d[st1[st1ind]]=i #assign digit for specific character
                d[sm[smind]]=val
                bt(d,ind+1,crry,visit+[i]+[val]) # if condition true then call function recursively
                d[st1[st1ind]]=-1
                d[sm[smind]]=-1


bt(var,0,0,[])
print("res",res)

#---------------------------------------Output-----------------------------------------------
#         { 'o':4,'w':3,'t':7,'r':8,'u':6,'f':1 }


