# creating the board
size = int(input("enter the size of the ChessBoard"))
data  = []
for i in range(size):
    list = []
    for i in range(size):
        list.append(0)
    data.append(list)

for x in data:
    print(x)


def check_place(data,row,row_check,size):
    print("row = ", row)
    print("row_check = ", row_check)
    if row_check >= size:
        print("returning")
        return True
    position = data[row].index(1)
    if(data[row_check].index(1) == position):
        print("vertical")
        return False
    if(row == row_check):
        print("horizontal")
        return False
    row_difference = row_check - row
    diagonal = abs(position - data[row_check].index(1))
    if(diagonal == row_difference):
        print("diagonal")
        return False
    return check_place(data,row,row_check + 1,size)

def Queens(data,size):
    num_queens = 0
    row = size - 1
    location = 0
    while num_queens != size:
        data[row][location] = 1
        for x in data:
            print(x)
        correct = check_place(data,row,row + 1,size)
        print(correct)
        if(correct):
            print("going up row")
            row -= 1
            location = 0
            num_queens += 1
        else:
            if(location == size - 1):
                if (row == size):
                    print("there is no answer")
                    return
                print("checking row")
                print("going backwards")
                print("row = ",row)
                print("location = ", location)
                data[row][location] = 0
                print(data[row])
                row += 1
                print("row = ", row)
                location = data[row].index(1)
                print("location = ", location)
                num_queens -= 1
                while(location == size - 1):
                    data[row][location] = 0
                    print("going backwards")
                    print("row = ", row)
                    print("location = ", location)
                    data[row][location] = 0
                    print(data[row])
                    row += 1
                    if (row == size):
                        print("there is no answer")
                        return
                    print("row = ", row)
                    location = data[row].index(1)
                    print("location = ", location)
                    num_queens -= 1
            data[row][location] = 0
            location += 1

Queens(data,size)
print("answer")
for x in data:
    print(x)

