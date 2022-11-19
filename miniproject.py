import random
import datetime

# List Declaration

rooms=[]
names = []
phones = []
addresses=[]
global r


#Home Function
def Home():
    print("-------- WELCOME TO HOTEL RAJMAHAL--------\n")
    print("what would you like to do today?")
    print("1. Room Booking\n")
    print("2. Food Order\n")
    print("3. Room Cancellation\n")
    print("4. Room Info\n")
    print("5. Search customer\n")
    print("6. Feedback\n")
    print("7. Exit")
    ch=int(input("Enter your choice:"))
	
    if ch == 1:
        RoomBooking()
	
    if ch == 2:
        FoodOrder()
	
    if ch ==3:
        RoomCancellation()
	
    if ch == 4:
        RoomInfo()

    if ch == 5:
        Search()

    if ch == 6:
        Feedback()

    if ch==7:
        exit()
	
# RoomBooking

def RoomBooking():

    print("----ROOM BOOKING---- ")
    name = input("Enter your Name: ")
    phone= int(input("Enter your Phone No.: "))
    address= input("Enter your Address: ")
    room=int(input("enter room number"))
    
    if room not in rooms:
        rooms.append(room)
        names.append(name)
        phones.append(phone)
        addresses.append(address)
        print("Room booked successfully\n\n\n")
    else:
        print("Room already booked!\n\n\n ")
    Home()

 
# RoomCancellation
def RoomCancellation():
    r=int(input("Enter your room no.\n"))
    if r in rooms:
        i=rooms.index(r)
        names.pop(i)
        addresses.pop(i)
        phones.pop(i)
        rooms.pop(i)
        print("Room cancelled successfully\n\n\n")
    else:
        print("Room not booked!!\n\n\n")
    Home()

# RoomInfo
def RoomInfo():

    print(" -----Room Info-----\n")
    if len(rooms)!=0:
        for i in range(len(rooms)):
            print("Room No.=",rooms[i],"; Name=",names[i],"; Phone No.=",phones[i],"; Address=",addresses[i])
            print("----------------------------------------------------------------")
    else:
        print("No Rooms booked!!!\n\n\n")
    Home()

#Search Coustomer
def Search():
    n=input("Enter your Name:")
    if n in names:
        i=names.index(n)
        print("Name=",names[i]," Room No.=",rooms[i]," Phone No.=",phones[i]," Address=",addresses[i])
    else:
        print("No entry of name ",n)
# MenuCard
def MenuCard():
        
	print("-----Menu Card-----\n\n\n")
	print(" 1 Regular Tea............. 20.00")
	print(" 2 Masala Tea.............. 25.00")
	print(" 3 Coffee.................. 25.00")
	print(" 4 Cold Drink.............. 25.00")
	print(" 5 Bread Butter............ 30.00")
	print(" 6 Bread Jam............... 30.00")
	print(" 7 Veg. Sandwich........... 50.00")
	print(" 8 Veg. Toast Sandwich..... 50.00")
	print(" 9 Cheese Toast Sandwich... 70.00")
	print(" 10 Grilled Sandwich........70.00")
	print(" 11 Tomato Soup............ 100.00")
	print(" 12 Hot & Sour............. 100.00")
	print(" 13 Veg. Noodle Soup....... 100.00")
	print(" 14 Sweet Corn............. 100.00")
	print(" 15 Veg. Munchow........... 100.00")
	print(" 16 Shahi Paneer........... 100.00")
	print(" 17 Kadai Paneer........... 100.00")
	print(" 18 Handi Paneer........... 120.00")
	print(" 19 Palak Paneer........... 120.00")
	print(" 20 Chilli Paneer.......... 120.00\n\n")
	return (0)

#Food Order
def FoodOrder():
              MenuCard()
              ch=1
              r=0
              while ch!=0:
                  ch=int(input("Enter item no. or else enter 0:"))
                  if ch==1:
                      rs=20
                      r=r+rs
                  elif ch<=4 and ch>=2:
                      rs=25
                      r=r+rs
                  elif ch<=6 and ch>=5:
                      rs=30
                      r=r+rs
                  elif ch<=8 and ch>=7:
                      rs=50
                      r=r+rs
                  elif ch<=10 and ch>=9:
                      rs=70
                      r=r+rs
                  elif ch<=17 and ch>=11:
                      rs=100
                      r=r+rs
                  elif ch<=20 and ch>=18:
                      rs=120
                      r=r+rs
                  elif ch==0:
                      print("Total Bill: ",r)
                      Discount(r)
                  else:
                      print("Wrong Choice..!!")
              

#Discount
def Discount(r):
    if r>=200:
        print("Congratulations!!! you get 10% discount.")
        d=10
    elif r>=100:
        print("Congratulations!!! you get 5% discount.")
        d=5
    else:
        d=0
    BillGenerate(r,d)

#BillGenerate
def BillGenerate(r,d):
    print("\n---Bill Generate---")
    name = input("Enter your Name: ")
    phone= int(input("Enter your Phone No.: "))
    print("\n-------HOTEL RAJMAHAL--------")
    print("Sudama Nagar, Indore")
    print("contact no.- 123456\n\n")
    print(datetime.datetime.now())
    print("Bill no.=",random.randrange(40)+300)
    print("\nName-",name)
    print("phone-",phone)
    print("\nyour total bill is Rs. ",r)
    dis=r*d/100
    print("discount=",dis)
    print("amount payble: Rs. ",r-dis)
    print("\nThank you!!!!\nVisit again!!!")
    exit()
    
#Feedback
def Feedback():
    print("\nHow many stars would you give to Hotel Rajmahal(out of 5)")
    ch=int(input("\nEnter your rating"))
    if ch>5:
        print("Please give rating out of 5")
        Feedback()
    else:
        print("your rating is: ")
        for i in range(ch):
            print("*",end=' ')

    
#Main
Home()
