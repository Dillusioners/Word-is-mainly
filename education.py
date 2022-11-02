print("Welcome to Dillusioners Maths Class Test")
#Marks initalisation
marks = 0
#Answer Key
answer = [1,3,4]
#List for user answers
user = []
#Main test
try:
    q1 = int(input("1 + 1 = ?\n1. 2\n2. 1\n3. 4\n4. 5\n"))
    q2 = int(input("40 % 10 = ?\n1. 1\n2. 4\n3. 0\n4. -1\n"))
    q3 = int(input("80 * -1 + 2 = ?\n1. 2\n2. 4\n3. 80\n4. -78\n"))
    user.append(q1)
    user.append(q2)
    user.append(q3)
except ValueError as e:
    print("Oops ", e)
else:
    if answer[0] == user[0]:
        marks += 1       
    if answer[1] == user[1]:
        marks += 1
    if answer[2] == user[2]:
        marks +=1 

#Displaying Results
print("Your marks are ",marks)

    

