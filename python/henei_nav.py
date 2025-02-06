import sys
sys.setrecursionlimit(2000000)
move=[]
def caltower(platenum,curtn,tartn):
    pretn=3-curtn-tartn
    if platenum == 1:
        move.append([curtn,tartn])
        return
    caltower(platenum-1,curtn,pretn)
    caltower(1,curtn,tartn)
    caltower(platenum-1,pretn,tartn)
caltower(5,0,2)
