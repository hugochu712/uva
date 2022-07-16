
input()
try :
    while True :
        str = input()
        sum = 0
        for part in str.split() :
            temp = (ord(part[0]) - 48) << 1
            sum += temp
            if (temp > 9) :
                sum -= 9

            sum += ord(part[1]) - 48

            temp = (ord(part[2]) - 48) << 1
            sum += temp
            if (temp > 9) :
                sum -= 9

            sum += ord(part[3]) - 48

        if sum % 10 :
            print("Invalid\n")
        else :
            print("Valid\n")
except :
    pass