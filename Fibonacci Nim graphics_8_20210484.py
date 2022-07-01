from tkinter import*
from tkinter import ttk 
root=Tk() # creat a window
root.geometry('1000x600+280+100') # the size of the window 
style=ttk.Style()
style.theme_use("classic") # style of window 
L1=Label(root,text="Fibonaacci Nim Game",font=('Helvatical bold',50,'underline'),fg='blue').place(x=180,y=0)# heading
L2=Label(root,text="Please player1 enter a numper",font=('Helvatical bold',21),fg='green').place(x=40,y=250)# heading for player 1
L3=Label(root,text="Please player2 enter a numper",font=('Helvatical bold',21),fg='brown').place(x=590,y=250)# heading for player2
L4=Label(root,text="please enter the num of coins",font=('Helvatical bold',25),fg='red').place(x=290,y=120)#heading for the number of coins
def coin ():#get the number of coins
        global coins
        global player1
        global player2
        coins =int(c.get())
        L4=Label(root,text=f"the num of coins is : {coins}",font=('Helvatical bold',40),fg='red').place(x=220,y=470)
        player1=0
        player2=0
def game_player1():#player1 turn
        global coins
        global player1
        global player2
        if coins >= 0 :
            player1=int(a.get())
            if (player1 >(player2*2)) and (player2!=0):
                L5= Label(root,text="invalid num",font=('Helvatical bold',20),fg='red',bg='yellow').place(x=440 ,y=300) 
            else:    
                L4=Label(root,text=f"the num of coins is : {coins}",font=('Helvatical bold',40),fg='#f0f0f0').place(x=220,y=470)
                L5= Label(root,text="invalid num",font=('Helvatical bold',20),fg='#f0f0f0',bg='#f0f0f0').place(x=440 ,y=300)
                coins=coins-player1   
                L4=Label(root,text=f"the num of coins is : {coins}",font=('Helvatical bold',40),fg='red').place(x=220,y=470) 
            if coins <= 0 :
                    L4=Label(root,text=f"the num of coins is : {coins}",font=('Helvatical bold',40),fg='#f0f0f0').place(x=220,y=470)
                    L5= Label(root,text="congratulation player1 you are the winner!!",font=('Helvatical bold',30),fg='green').place(x=140 ,y=470)
def game_player2():#player 2 turn
        global coins
        global player1
        global player2
        if coins >= 0 :
            player2=int(b.get())
            if player2 >(player1*2):
                L5= Label(root,text="invalid num",font=('Helvatical bold',20),fg='red',bg='yellow').place(x=440 ,y=300)
            else:
                L4=Label(root,text=f"the num of coins is : {coins}",font=('Helvatical bold',40),fg='#f0f0f0').place(x=220,y=470)
                L5= Label(root,text="invalid num",font=('Helvatical bold',20),fg='#f0f0f0',bg='#f0f0f0').place(x=440 ,y=300)    
                coins=coins-player2    
                L4=Label(root,text=f"the num of coins is : {coins}",font=('Helvatical bold',40),fg='red').place(x=220,y=470) 
            if coins <= 0 :
                    L4=Label(root,text=f"the num of coins is : {coins}",font=('Helvatical bold',40),fg='#f0f0f0').place(x=220,y=470)
                    L5= Label(root,text="congratulation player2 you are the winner!!",font=('Helvatical bold',30),fg='brown').place(x=140 ,y=470)                 
                
# entry and buttons        
Button1=Button(text='player1',fg='yellow',bg='green',font=('Helvatical bold',25),command=game_player1,cursor='hand2').place(x=160,y=350,width=130,height=45)
a=StringVar()        
text=Entry(textvariable=a, font=("Arial",20)).place(x=50,y=300,height=40,width=370)
Button2=Button(text='player2',fg='yellow',bg='brown',font=('Helvatical bold',25),command=game_player2,cursor='hand2').place(x=715,y=350,width=130,height=45)
b=StringVar()        
text=Entry(textvariable=b, font=("Arial",20)).place(x=600,y=300,height=40,width=370)  
Button3=Button(text='Enter',fg='red',bg='yellow',font=('Helvatical bold',20),command=coin,cursor='hand2').place(x=710,y=172,width=130,height=35)
c=StringVar()        
text=Entry(textvariable=c, font=("Arial",20)).place(x=310,y=170,height=40,width=370)               
        
   
            
root.mainloop()