from tkinter import*
from tkinter import ttk
from tkinter import messagebox
from tracemalloc import start
root=Tk()
style=ttk.Style()
style.theme_use("classic")
Active_player=0
p1=[]
p2=[]
first=0
second=0
new1=0
new2=0
idd =2
idd2=2
#making buttons
b1=ttk.Button(root,text=" ")
b1.grid(row=0,column=0,ipadx=40,ipady=40)
b1.config(command=lambda:click(1))

b2=ttk.Button(root,text=" ")
b2.grid(row=0,column=1,ipadx=40,ipady=40)
b2.config(command=lambda:click(2))

b3=ttk.Button(root,text=" ")
b3.grid(row=0,column=2,ipadx=40,ipady=40)
b3.config(command=lambda:click(3))

b4=ttk.Button(root,text=" ")
b4.grid(row=0,column=3,ipadx=40,ipady=40)
b4.config(command=lambda:click(4))

b5=ttk.Button(root,text=" ")
b5.grid(row=1,column=0,ipadx=40,ipady=40)
b5.config(command=lambda:click(5))

b6=ttk.Button(root,text=" ")
b6.grid(row=1,column=1,ipadx=40,ipady=40)
b6.config(command=lambda:click(6))

b7=ttk.Button(root,text=" ")
b7.grid(row=1,column=2,ipadx=40,ipady=40)
b7.config(command=lambda:click(7))

b8=ttk.Button(root,text=" ")
b8.grid(row=1,column=3,ipadx=40,ipady=40)
b8.config(command=lambda:click(8))

b9=ttk.Button(root,text=" ")
b9.grid(row=2,column=0,ipadx=40,ipady=40)
b9.config(command=lambda:click(9))

b10=ttk.Button(root,text=" ")
b10.grid(row=2,column=1,ipadx=40,ipady=40)
b10.config(command=lambda:click(10))

b11=ttk.Button(root,text=" ")
b11.grid(row=2,column=2,ipadx=40,ipady=40)
b11.config(command=lambda:click(11))

b12=ttk.Button(root,text=" ")
b12.grid(row=2,column=3,ipadx=40,ipady=40)
b12.config(command=lambda:click(12))

b13=ttk.Button(root,text=" ")
b13.grid(row=3,column=0,ipadx=40,ipady=40)
b13.config(command=lambda:click(13))

b14=ttk.Button(root,text=" ")
b14.grid(row=3,column=1,ipadx=40,ipady=40)
b14.config(command=lambda:click(14))

b15=ttk.Button(root,text=" ")
b15.grid(row=3,column=2,ipadx=40,ipady=40)
b15.config(command=lambda:click(15))

b16=ttk.Button(root,text=" ")
b16.grid(row=3,column=3,ipadx=40,ipady=40)
b16.config(command=lambda:click(16))










#the turn of the player
def click(id):
    global Active_player
    global p1
    global p2
    global idd
    global idd2
    if Active_player == 0 or Active_player == 1 :
        p1.append(id)
        root.title("please player1 play your turn at any rectangle ")
        Active_player+=1
        print("P1{}".format(p1))
        print(len(p1))
        printing (id,"X")
        
            
    elif Active_player == 2 or Active_player == 3 :
        p2.append(id)
        root.title("please player2 play your turn at any rectangle ")
        Active_player+=1
        print("P2{}".format(p2)) 
        printing (id,"X")
    else :
        p1.append(id)
        root.title("please player1 play your turn at any rectangle ")
        Active_player=1
        print("P1{}".format(p1))  
        printing (id,"X")
    rules()
def printing (id,Text) :#printing x in the button
    global Active_player
    global idd
    global idd2
    global first 
    global second
    global new1
    global new2
    global p1
    global p2
    if (len(p1)%2==0) and (len(p1)!= 0) and (first==0):
             if ((p1[first]==p1[first+1]-1) or (p1[first]==p1[first+1]-4) or  (p1[first]==p1[first+1]+4) or (p1[first]==p1[first+1]+1)) and (first==0)  :
                    if id == 1 :
                        b1.config(text=Text)
                        b1.state(["disabled"])
                        first+=1
                    if id == 2 :
                        b2.config(text=Text)
                        b2.state(["disabled"])
                        first+=1
                    if id == 3 :
                        b3.config(text=Text)    
                        b3.state(["disabled"])
                        first+=1
                    if id == 4 :
                        b4.config(text=Text)
                        b4.state(["disabled"])
                        first+=1
                    if id == 5 :
                        b5.config(text=Text)
                        b5.state(["disabled"])
                        first+=1
                    if id == 6 :
                        b6.config(text=Text)
                        b6.state(["disabled"])
                        first+=1
                    if id == 7 :
                        b7.config(text=Text)
                        b7.state(["disabled"])
                        first+=1
                    if id == 8 :
                        b8.config(text=Text)
                        b8.state(["disabled"])
                        first+=1
                    if id == 9 :
                        b9.config(text=Text)    
                        b9.state(["disabled"])
                        first+=1
                    if id == 10 :
                        b10.config(text=Text)    
                        b10.state(["disabled"])
                        first+=1
                    if id == 11 :
                        b11.config(text=Text)    
                        b11.state(["disabled"])
                        first+=1
                    if id == 12 :
                        b12.config(text=Text)    
                        b12.state(["disabled"])
                        first+=1
                    if id == 13 :
                        b13.config(text=Text)    
                        b13.state(["disabled"])
                        first+=1
                    if id == 14 :
                        b14.config(text=Text)    
                        b14.state(["disabled"])
                        first+=1         
                    if id == 15 :
                        b15.config(text=Text)    
                        b15.state(["disabled"]) 
                        first+=1
                    if id == 16 :
                        b16.config(text=Text)    
                        b16.state(["disabled"]) 
                        first+=1   
                    start()    
             else:
                 messagebox.showinfo(title="wrong",message="please player 1 make a rectangle")
                 p1.pop()
                 Active_player-=1
                 start() 
    elif(new1==0):#to play the first play correctly
        new1+=1
        if id == 1 :
            b1.config(text=Text)
            b1.state(["disabled"])
        if id == 2 :
            b2.config(text=Text)
            b2.state(["disabled"])
        if id == 3 :
            b3.config(text=Text)    
            b3.state(["disabled"])
        if id == 4 :
            b4.config(text=Text)
            b4.state(["disabled"])
        if id == 5 :
            b5.config(text=Text)
            b5.state(["disabled"])
        if id == 6 :
            b6.config(text=Text)
            b6.state(["disabled"])
        if id == 7 :
            b7.config(text=Text)
            b7.state(["disabled"])
        if id == 8 :
            b8.config(text=Text)
            b8.state(["disabled"])
        if id == 9 :
            b9.config(text=Text)    
            b9.state(["disabled"])
        if id == 10 :
            b10.config(text=Text)    
            b10.state(["disabled"])
        if id == 11 :
            b11.config(text=Text)    
            b11.state(["disabled"])
        if id == 12 :
            b12.config(text=Text)    
            b12.state(["disabled"])
        if id == 13 :
            b13.config(text=Text)    
            b13.state(["disabled"])
        if id == 14 :
            b14.config(text=Text)    
            b14.state(["disabled"])      
        if id == 15 :
            b15.config(text=Text)    
            b15.state(["disabled"]) 
        if id == 16 :
            b16.config(text=Text)    
            b16.state(["disabled"]) 
        start()   
    elif(len(p1)%2==1):#to pllay at any place if the length of list is odd
        if id == 1 :
            b1.config(text=Text)
            b1.state(["disabled"])
        if id == 2 :
            b2.config(text=Text)
            b2.state(["disabled"])
        if id == 3 :
            b3.config(text=Text)    
            b3.state(["disabled"])
        if id == 4 :
            b4.config(text=Text)
            b4.state(["disabled"])
        if id == 5 :
            b5.config(text=Text)
            b5.state(["disabled"])
        if id == 6 :
            b6.config(text=Text)
            b6.state(["disabled"])
        if id == 7 :
            b7.config(text=Text)
            b7.state(["disabled"])
        if id == 8 :
            b8.config(text=Text)
            b8.state(["disabled"])
        if id == 9 :
            b9.config(text=Text)    
            b9.state(["disabled"])
        if id == 10 :
            b10.config(text=Text)    
            b10.state(["disabled"])
        if id == 11 :
            b11.config(text=Text)    
            b11.state(["disabled"])
        if id == 12 :
            b12.config(text=Text)    
            b12.state(["disabled"])
        if id == 13 :
            b13.config(text=Text)    
            b13.state(["disabled"])
        if id == 14 :
            b14.config(text=Text)    
            b14.state(["disabled"])      
        if id == 15 :
            b15.config(text=Text)    
            b15.state(["disabled"]) 
        if id == 16 :
            b16.config(text=Text)    
            b16.state(["disabled"]) 
        start()   
                        
    if (first!=0 and len(p1)%2==0 and len(p1)>=3 and len(p1)==len(p2)+2):#to play the second game in a rectangle
        if ((p1[idd]==p1[idd+1]-1) or (p1[idd]==p1[idd+1]-4) or  (p1[idd]==p1[idd+1]+4) or (p1[idd]==p1[idd+1]+1)) and idd>=2 and (first!=0) :
            if id == 1 :
                b1.config(text=Text)
                b1.state(["disabled"])
                idd+=2
            if id == 2 :
                b2.config(text=Text)
                b2.state(["disabled"])
                idd+=2
            if id == 3 :
                b3.config(text=Text)    
                b3.state(["disabled"])
                idd+=2
            if id == 4 :
                b4.config(text=Text)
                b4.state(["disabled"])
                idd+=2
            if id == 5 :
                b5.config(text=Text)
                b5.state(["disabled"])
                idd+=2
            if id == 6 :
                b6.config(text=Text)
                b6.state(["disabled"])
                idd+=2
            if id == 7 :
                b7.config(text=Text)
                b7.state(["disabled"])
                idd+=2
            if id == 8 :
                b8.config(text=Text)
                b8.state(["disabled"])
                idd+=2
            if id == 9 :
                b9.config(text=Text)    
                b9.state(["disabled"])
                idd+=2
            if id == 10 :
                b10.config(text=Text)    
                b10.state(["disabled"])
                idd+=2
            if id == 11 :
                b11.config(text=Text)    
                b11.state(["disabled"])
                idd+=2
            if id == 12 :
                b12.config(text=Text)    
                b12.state(["disabled"])
                idd+=2
            if id == 13 :
                b13.config(text=Text)    
                b13.state(["disabled"])
                idd+=2
            if id == 14 :
                b14.config(text=Text)    
                b14.state(["disabled"]) 
                idd+=2     
            if id == 15 :
                b15.config(text=Text)    
                b15.state(["disabled"])
                idd+=2
            if id == 16 :
                b16.config(text=Text)    
                b16.state(["disabled"])
                idd+=2
            start()    
            
        else:
            messagebox.showinfo(title="wrong",message="please player 1 make a rectangle")
            p1.pop()
            Active_player-=1
            start()    
                
    if (len (p2)%2==0 and len(p2)!= 0 and second==0): #to make player play in a rectangle 
             if ((p2[second]==p2[second+1]-1) or (p2[second]==p2[second+1]-4) or  (p2[second]==p2[second+1]+4) or (p2[second]==p2[second+1]+1)) and (second==0) :
                    if id == 1 :
                        b1.config(text=Text)
                        b1.state(["disabled"])
                        first+=1
                        second+=1
                    if id == 2 :
                        b2.config(text=Text)
                        b2.state(["disabled"])
                        first+=1
                        second+=1
                    if id == 3 :
                        b3.config(text=Text)    
                        b3.state(["disabled"])
                        first+=1
                        second+=1
                    if id == 4 :
                        b4.config(text=Text)
                        b4.state(["disabled"])
                        first+=1
                        second+=1
                    if id == 5 :
                        b5.config(text=Text)
                        b5.state(["disabled"])
                        first+=1
                        second+=1
                    if id == 6 :
                        b6.config(text=Text)
                        b6.state(["disabled"])
                        first+=1
                        second+=1
                    if id == 7 :
                        b7.config(text=Text)
                        b7.state(["disabled"])
                        first+=1
                        second+=1
                    if id == 8 :
                        b8.config(text=Text)
                        b8.state(["disabled"])
                        first+=1
                        second+=1
                    if id == 9 :
                        b9.config(text=Text)    
                        b9.state(["disabled"])
                        first+=1
                        second+=1
                    if id == 10 :
                        b10.config(text=Text)    
                        b10.state(["disabled"])
                        first+=1
                        second+=1
                    if id == 11 :
                        b11.config(text=Text)    
                        b11.state(["disabled"])
                        first+=1
                        second+=1
                    if id == 12 :
                        b12.config(text=Text)    
                        b12.state(["disabled"])
                        first+=1
                        second+=1
                    if id == 13 :
                        b13.config(text=Text)    
                        b13.state(["disabled"])
                        first+=1
                        second+=1
                    if id == 14 :
                        b14.config(text=Text)    
                        b14.state(["disabled"])
                        first+=1 
                        second+=1        
                    if id == 15 :
                        b15.config(text=Text)    
                        b15.state(["disabled"]) 
                        first+=1
                        second+=1
                    if id == 16 :
                        b16.config(text=Text)    
                        b16.state(["disabled"]) 
                        first+=1 
                        second+=1
                    start()    
             else:   
                 messagebox.showinfo(title="wrong",message="please player 2 make a rectangle")
                 Active_player-=1 
                 p2.pop()
                 start() 
    elif(new2==0):#to play the first play correctly 
        new2+=1
        if id == 1 :
            b1.config(text=Text )
            b1.state(["disabled"])
        if id == 2 :
            b2.config(text=Text)
            b2.state(["disabled"])
        if id == 3 :
            b3.config(text=Text)    
            b3.state(["disabled"])
        if id == 4 :
            b4.config(text=Text)
            b4.state(["disabled"])
        if id == 5 :
            b5.config(text=Text)
            b5.state(["disabled"])
        if id == 6 :
            b6.config(text=Text)
            b6.state(["disabled"])
        if id == 7 :
            b7.config(text=Text)
            b7.state(["disabled"])
        if id == 8 :
            b8.config(text=Text)
            b8.state(["disabled"])
        if id == 9 :
            b9.config(text=Text)    
            b9.state(["disabled"])
        if id == 10 :
            b10.config(text=Text)    
            b10.state(["disabled"])
        if id == 11 :
            b11.config(text=Text)    
            b11.state(["disabled"])
        if id == 12 :
            b12.config(text=Text)    
            b12.state(["disabled"])
        if id == 13 :
            b13.config(text=Text)    
            b13.state(["disabled"])
        if id == 14 :
            b14.config(text=Text)    
            b14.state(["disabled"])      
        if id == 15 :
            b15.config(text=Text)    
            b15.state(["disabled"]) 
        if id == 16 :
            b16.config(text=Text)    
            b16.state(["disabled"]) 
        start()             
    elif(len(p2)%2==1):# to play correctle if the length of list is odd
        if id == 1 :
            b1.config(text=Text)
            b1.state(["disabled"])
        if id == 2 :
            b2.config(text=Text)
            b2.state(["disabled"])
        if id == 3 :
            b3.config(text=Text)    
            b3.state(["disabled"])
        if id == 4 :
            b4.config(text=Text)
            b4.state(["disabled"])
        if id == 5 :
            b5.config(text=Text)
            b5.state(["disabled"])
        if id == 6 :
            b6.config(text=Text)
            b6.state(["disabled"])
        if id == 7 :
            b7.config(text=Text)
            b7.state(["disabled"])
        if id == 8 :
            b8.config(text=Text)
            b8.state(["disabled"])
        if id == 9 :
            b9.config(text=Text)    
            b9.state(["disabled"])
        if id == 10 :
            b10.config(text=Text)    
            b10.state(["disabled"])
        if id == 11 :
            b11.config(text=Text)    
            b11.state(["disabled"])
        if id == 12 :
            b12.config(text=Text)    
            b12.state(["disabled"])
        if id == 13 :
            b13.config(text=Text)    
            b13.state(["disabled"])
        if id == 14 :
            b14.config(text=Text)    
            b14.state(["disabled"])      
        if id == 15 :
            b15.config(text=Text)    
            b15.state(["disabled"]) 
        if id == 16 :
            b16.config(text=Text)    
            b16.state(["disabled"]) 
        start()                   
    elif(second!=0 and len(p2)%2==0 and len(p2)>=3 and len(p2)==len(p1)) :#to make player play in a rectangle
        
                if ((p2[idd2]==p2[idd2+1]-1) or (p2[idd2]==p2[idd2+1]-4) or  (p2[idd2]==p2[idd2+1]+4) or (p2[idd2]==p2[idd2+1]+1)) and (idd2>=2) and (second!=0) :
                    if id == 1 :
                        b1.config(text=Text)
                        b1.state(["disabled"])
                        idd2+=2
                    if id == 2 :
                        b2.config(text=Text)
                        b2.state(["disabled"])
                        idd2+=2
                    if id == 3 :
                        b3.config(text=Text)    
                        b3.state(["disabled"])
                        idd2+=2
                    if id == 4 :
                        b4.config(text=Text)
                        b4.state(["disabled"])
                        idd2+=2
                    if id == 5 :
                        b5.config(text=Text)
                        b5.state(["disabled"])
                        idd2+=2
                    if id == 6 :
                        b6.config(text=Text)
                        b6.state(["disabled"])
                        idd2+=2
                    if id == 7 :
                        b7.config(text=Text)
                        b7.state(["disabled"])
                        idd2+=2
                    if id == 8 :
                        b8.config(text=Text)
                        b8.state(["disabled"])
                        idd2+=2
                    if id == 9 :
                        b9.config(text=Text)    
                        b9.state(["disabled"])
                        idd2+=2
                    if id == 10 :
                        b10.config(text=Text)    
                        b10.state(["disabled"])
                        idd2+=2
                    if id == 11 :
                        b11.config(text=Text)    
                        b11.state(["disabled"])
                        idd2+=2
                    if id == 12 :
                        b12.config(text=Text)    
                        b12.state(["disabled"])
                        idd2+=2
                    if id == 13 :
                        b13.config(text=Text)    
                        b13.state(["disabled"])
                        idd2+=2
                    if id == 14 :
                        b14.config(text=Text)    
                        b14.state(["disabled"])
                        idd2+=2      
                    if id == 15 :
                        b15.config(text=Text)    
                        b15.state(["disabled"]) 
                        idd2+=2
                    if id == 16 :
                        b16.config(text=Text)    
                        b16.state(["disabled"]) 
                        idd2+=2
                    start()    
                else:
                 messagebox.showinfo(title="wrong",message="please player 2 make a rectangle")
                 Active_player-=1   
                 p2.pop()
                 start()
                 

def rules () : #the rules of the game 
    winner = -1
    for i in (1,2,3,4,5,6,7,8,10,11,12,15,16) :
        if((i and 13) not in p1) and (len(p1)==8 and len(p2)==6) :
            winner =1 
    for i in (1,2,3,4,5,6,7,8,9,11,12,14,16) :
        if((i and 14) not in p1) and (len(p1)==8 and len(p2)==6) :
            winner =1 
    for i in (1,2,3,4,5,6,7,8,9,10,12,13,15) :
        if((i and 15) not in p1) and (len(p1)==8 and len(p2)==6) :
            winner =1 
    for i in (1,2,3,4,5,6,7,8,9,10,11,13,14,16) :
        if((i and 16) not in p1) and (len(p1)==8 and len(p2)==6) :
            winner =1 
    for i in (1,2,3,4,6,7,8,9,11,12,14,15,16) :
        if((i and 9) not in p1) and (len(p1)==8 and len(p2)==6) :
            winner =1 
    for i in (1,2,3,4,5,7,8,10,12,13,15,16) :
        if((i and 10) not in p1) and (len(p1)==8 and len(p2)==6) :
            winner =1 
    for i in (1,2,3,4,5,6,8,9,11,13,14,16) :
        if((i and 11) not in p1) and (len(p1)==8 and len(p2)==6) :
            winner =1 
    for i in (1,2,3,4,5,6,7,9,10,12,13,14,15) :
        if((i and 12) not in p1) and (len(p1)==8 and len(p2)==6) :
            winner =1 
    for i in (1,2,3,4,5,7,8,11,12,13,14,15,16) :
        if((i and 5) not in p1) and (len(p1)==8 and len(p2)==6) :
            winner =1 
    for i in (1,3,4,6,8,9,11,12,13,14,15,16) :
        if((i and 6) not in p1) and (len(p1)==8 and len(p2)==6) :
            winner =1 
    for i in (1,2,4,5,7,9,10,12,13,14,15,16) :
        if((i and 7) not in p1) and (len(p1)==8 and len(p2)==6) :
            winner =1 
    for i in (1,2,3,5,6,8,9,10,11,13,14,15,16) :
        if((i and 8) not in p1) and (len(p1)==8 and len(p2)==6) :
            winner =1     
    for i in (1,3,4,6,7,8,9,10,11,12,13,14,15,16) :
        if((i and 1) not in p1) and (len(p1)==8 and len(p2)==6) :
            winner =1 
    for i in (2,4,5,7,8,9,10,11,12,13,14,15,16) :
        if((i and 2) not in p1) and (len(p1)==8 and len(p2)==6) :
            winner =1 
    for i in (1,3,5,6,8,9,10,11,12,13,14,15,16) :
        if((i and 3) not in p1) and (len(p1)==8 and len(p2)==6) :
            winner =1 
    for i in (1,2,4,5,6,7,9,10,11,12,13,14,15,16) :
        if((i and 4) not in p1) and (len(p1)==8 and len(p2)==6) :
            winner =1
    if ((1 not in p1) and (4 not in p1) and (13 not in p1) and (16 not in p1) and (len(p1)==6 and len(p2)==6)) :
            winner = 1
    if ((1) not in p1) and((4) not in p1) and ((9) not in p1) and ((12) not in p1) and (len(p1)==6 and len(p2)==6) :
            winner = 1            

    for i in (1,2,3,4,5,6,7,8,10,11,12,15,16) :
        if((i and 13) not in p2) and (len(p1)==6 and len(p2)==8) :
            winner =2 
    for i in (1,2,3,4,5,6,7,8,9,11,12,14,16) :
        if((i and 14) not in p2) and (len(p1)==6 and len(p2)==8) :
            winner =2 
    for i in (1,2,3,4,5,6,7,8,9,10,12,13,15) :
        if((i and 15) not in p2) and (len(p1)==6 and len(p2)==8) :
            winner =2
    for i in (1,2,3,4,5,6,7,8,9,10,11,13,14,16) :
        if((i and 16) not in p2) and (len(p1)==6 and len(p2)==8) :
            winner =2 
    for i in (1,2,3,4,6,7,8,9,11,12,14,15,16) :
        if((i and 9) not in p2) and (len(p1)==6 and len(p2)==8) :
            winner =2 
    for i in (1,2,3,4,5,7,8,10,12,13,15,16) :
        if((i and 10) not in p2) and (len(p1)==6 and len(p2)==8) :
            winner =2 
    for i in (1,2,3,4,5,6,8,9,11,13,14,16) :
        if((i and 11) not in p2) and (len(p1)==6 and len(p2)==8) :
            winner =2 
    for i in (1,2,3,4,5,6,7,9,10,12,13,14,15) :
        if((i and 12) not in p2) and (len(p1)==6 and len(p2)==8) :
            winner =2 
    for i in (1,2,3,4,5,7,8,11,12,13,14,15,16) :
        if((i and 5) not in p2) and (len(p1)==6 and len(p2)==8) :
            winner =2
    for i in (1,3,4,6,8,9,11,12,13,14,15,16) :
        if((i and 6) not in p2) and (len(p1)==6 and len(p2)==8) :
            winner =2 
    for i in (1,2,4,5,7,9,10,12,13,14,15,16) :
        if((i and 7) not in p2) and (len(p1)==6 and len(p2)==8) :
            winner =2 
    for i in (1,2,3,5,6,8,9,10,11,13,14,15,16) :
        if((i and 8) not in p2) and (len(p1)==6 and len(p2)==8) :
            winner =2     
    for i in (1,3,4,6,7,8,9,10,11,12,13,14,15,16) :
        if((i and 1) not in p2) and (len(p1)==6 and len(p2)==8) :
            winner =2 
    for i in (2,4,5,7,8,9,10,11,12,13,14,15,16) :
        if((i and 2) not in p2) and (len(p1)==6 and len(p2)==8) :
            winner =2 
    for i in (1,3,5,6,8,9,10,11,12,13,14,15,16) :
        if((i and 3) not in p2) and (len(p1)==6 and len(p2)==8) :
            winner =2 
    for i in (1,2,4,5,6,7,9,10,11,12,13,14,15,16) :
        if((i and 4) not in p2) and (len(p1)==6 and len(p2)==8) :
            winner =2 
    if ((1 not in p2) and (4 not in p2) and (13 not in p2) and (16 not in p2) and (len(p1)==6 and len(p2)==6)) :
            winner = 2
    if ((1) not in p2) and((4) not in p2) and ((9) not in p2) and ((12) not in p2) and (len(p1)==6 and len(p2)==6) :
            winner = 2         
                                                                                                                                       
        
          
     
    #check winner
    if winner==1 :    
        messagebox.showinfo(title="cong.",message="player1 is winner")
    if winner == 2 :
        messagebox.showinfo(title="cong.",message="player2 is winner")


        
root.mainloop()