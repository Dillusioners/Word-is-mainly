import json
import random
import os

print("########################## BHOLA CABS #########################")
#Function to register data
def register():
    name = input("Please enter your name:")
    age = int(input("Please enter your age:"))
    password = input("Please enter your password:")
    phone = input("Please enter your phone number:")
    email = input("Please enter your email:")
    #Bunch of loggers
    if age < 18 or age > 100:
        print("You are not eligible to register")
        return False
    elif len(password) < 8:
        print("Password must be at least 8 characters long")
        return False
    elif len(phone) != 10:
        print("Phone number must be 10 digits long")
        return False
    elif "@" not in email:
        print("Email must contain @")
        return False
    else:
        id = ""
        for i in range(1,10):
            noob = random.randint(1,9)
            rand = str(noob)
            id = id + rand

        filename = "ids/" + id + ".json"
        print("Your ID is: " + id + "\n")
    #Making data in json
        data = {
            "name": name,
            "age": age,
            "password": password,
            "id": id,
            'fares': 0,
        }
    #Dumping data
        jsonObj = json.dumps(data)
        with open(filename, "w") as f:
            f.write(jsonObj)
#function to login
def login():
    #Getting id and password
    try:
        id = input("Please enter your ID:")
        password = input("Please enter your password:")
        filename = "ids/" + id + ".json"
        #Loggers
        with open(filename, "r") as f:
            data = json.load(f)
            if data["password"] == password:
                print("Welcome " + data["name"] + "!")
                return True
            else:
                print("Wrong password")
                return False
    except Exception as e:
        print("Error: " + str(e))
#Logout function
def logout():
    print("Logout successful!")
#Login Function
def exit():
    print("Goodbye!")
#menu display function
def menu():
    print("1. Register")
    print("2. Login")
    print("3. Book Fare")
    print("4. Cancel Fare")
    print("5. Logout")
    print("6. Exit")
#Book Ticket function to book tickets
def bookTicket():
    #Getting user data
    number = int(input("Enter the number of people you want to take along with you: "))
    dist = int(input("Enter distance to travel : "))
    fare = int(input("Type 1 to book a normal car or 2 to book a bugatti : "))
    #Analysing data 
    while fare != 1 and fare != 2:
        fare = int(input("Type 1 to book a normal car or 2 to book a bugatti : "))
    if fare == 1:
        price = number * 50 * dist
        print("The total price will be ", str(number), " * 50 = ", str(price), ".")
        fee_for_1 = 50
        premium = False
    elif fare == 2:
        price = number * 100 * dist
        print("The total price will be ", str(number), " * 100 = ", str(price), ".")
        fee_for_1 = 100
        premium = True
    #Getting transaction id
    transaction = ""
    seats = []
    for i in range(1, 10):
        randomnum = random.randint(1, 9)
        rand = str(randomnum)
        transaction = transaction + rand

    for i in range(1, number):
        randomnum2 = random.randint(1, 30)
        for j in range(0, len(seats)):
            if randomnum2 != j:
                seats.append(randomnum2)
            else:
                i = i - 1

    #Transforming data
    data = {
        "number": number,
        "fee_for_1": fee_for_1,
        "transaction": transaction,
        'premium': premium,
        'seats': seats,
    }
    #Dumping data in json file
    filename = "Fare/" + transaction + ".json"
    print("Your transaction ID is: " + transaction + "\n")
    jsonObj = json.dumps(data)
    with open(filename, "w") as f:
        f.write(jsonObj)

#Cancel ticket function to cancel tickets
def cancelTicket():
    id = int(input("Enter the transaction id:- "))
    # Some more loggers
    try:
        if os.path.exists('ids'):
            if os.path.exists('Fare/' + id + '.json'):
                os.remove('Fare/' + id + '.json')
                print("Cancelled the fare.")
        else:
            main()
    except Exception as e:
        print("Deleted the fare")
#Main function
def main():
    while True:
        menu()
        choice = int(input("Please enter your choice:"))
        if choice == 1:
            register()
        elif choice == 2:
            if login():
                while True:
                    menu()
                    choice = int(input("Please enter your choice:"))
                    if choice == 3:
                        bookTicket()
                    if choice == 4:
                        cancelTicket()
                    elif choice == 5:
                        logout()
                    else:
                        print("Invalid choice!")
            else:
                print("Invalid ID or password!")
        elif choice == 6:
            exit()
            break
        else:
            print("Please login or register if you do not have an account.")
#Execute function for creating directories and calling main method
def execute():
    try:
        if not os.path.exists('ids'):
            os.makedirs('ids')
            if not os.path.exists('Fare'):
                os.makedirs('Fare')
                main()
        else:
            main()
    except Exception as e:
        print("Error: " + str(e))

execute()