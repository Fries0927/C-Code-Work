import os , random , time
gameblock = [[0] * 4 ,
             [0] * 4 ,
             [0] * 4 , 
             [0] * 4 ]
#印出4x4
def printgame():
    for i in range(21):
        print("-",end="")
    print("")    
    for i in gameblock:
        for o in i:
            if o == 0:
                print("|    ",end="")
            elif o == 2:
                print(f"|{o: ^4}",end="")
            elif o == 4:
                print(f"|\033[33m{o: ^4}\033[39m",end="")
            elif o == 8:
                print(f"|\033[32m{o: ^4}\033[39m",end="")
            elif o == 16:
                print(f"|\033[36m{o: ^4}\033[39m",end="")
            elif o == 32:
                print(f"|\033[34m{o: ^4}\033[39m",end="")
            elif o == 64:
                print(f"|\033[35m{o: ^4}\033[39m",end="")
            elif o == 128:
                print(f"|\033[31m{o: ^4}\033[39m",end="")
            elif o == 256:
                print(f"|\033[31;1m{o: ^4}\033[0m",end="")
            elif o >= 512:
                print(f"|\033[31;4;1m{o: ^4}\033[0m",end="")
        print("|")
        for i in range(21):
            print("-",end="")
        print("")

#隨機生成數字
def placenumber():
    counter = 0
    while 1:
        i = random.choice([2,4])
        o = random.randint(0,3)
        u = random.randint(0,3)
        if gameblock[o][u] == 0:
            gameblock[o][u] = i
            counter += 1
        if counter == 1:
            return

def default():
    os.system("cls")
    for i in range(2):
        placenumber()

#移動
def move():
    a = input("""
       w = 向上
       s = 向下
       a = 向左
       d = 向右 """)
    counter = 0
    if a == "w":
        for o in range(0,4):
            merged = [0] * 4
            for i in range(0,3):
                for a in range(1,4-i):      
                    if gameblock[i+a][o] != 0 and gameblock[i][o] == 0:
                        gameblock[i][o] = gameblock [i+a][o]
                        gameblock[i+a][o] = 0
                        counter += 1

            for i in range(0,3):
                if gameblock[i][o] == gameblock[i+1][o] and merged[i] == 0 and gameblock[i][o] != 0 :
                    gameblock[i][o] *=2
                    gameblock[i+1][o] = 0
                    merged[i] = 1
                    counter += 1

            for i in range(0,3):
                for a in range(1,4-i):      
                    if gameblock[i+a][o] != 0 and gameblock[i][o] == 0:
                        gameblock[i][o] = gameblock [i+a][o]
                        gameblock[i+a][o] = 0
                        counter += 1

    elif a == "s":
        for o in range(0,4):
            merged = [0] * 4
            for i in range(3,0,-1):
                for a in range(1,i+1):      
                    if gameblock[i-a][o] != 0 and gameblock[i][o] == 0:
                        gameblock[i][o] = gameblock [i-a][o]
                        gameblock[i-a][o] = 0
                        counter += 1

            for i in range(3,0,-1):
                if gameblock[i][o] == gameblock[i-1][o] and merged[i] == 0 and gameblock[i][o] != 0:
                    gameblock[i][o] *=2
                    gameblock[i-1][o] = 0
                    merged[i] = 1
                    counter += 1

            for i in range(3,0,-1):
                for a in range(1,i+1):      
                    if gameblock[i-a][o] != 0 and gameblock[i][o] == 0:
                        gameblock[i][o] = gameblock [i-a][o]
                        gameblock[i-a][o] = 0
                        counter += 1
    elif a == "a":
        for i in range(0,4):
            merged = [0] * 4
            for o in range(0,3):
                for a in range(1,4-o):      
                    if gameblock[i][o+a] != 0 and gameblock[i][o] == 0:
                        gameblock[i][o] = gameblock [i][o+a]
                        gameblock[i][o+a] = 0
                        counter += 1

            for o in range(0,3):
                if gameblock[i][o] == gameblock[i][o+1] and merged[i] == 0 and gameblock[i][o] != 0:
                    gameblock[i][o] *=2
                    gameblock[i][o+1] = 0
                    merged[i] = 1
                    counter += 1

            for o in range(0,3):
                for a in range(1,4-o):      
                    if gameblock[i][o+a] != 0 and gameblock[i][o] == 0:
                        gameblock[i][o] = gameblock [i][o+a]
                        gameblock[i][o+a] = 0
                        counter += 1
    elif a == "d":
        for i in range(0,4):
            merged = [0] * 4
            for o in range(3,0,-1):
                for a in range(1,o+1):      
                    if gameblock[i][o-a] != 0 and gameblock[i][o] == 0:
                        gameblock[i][o] = gameblock [i][o-a]
                        gameblock[i][o-a] = 0
                        counter += 1

            for o in range(3,0,-1):
                if gameblock[i][o] == gameblock[i][o-1] and merged[i] == 0 and gameblock[i][o] != 0:
                    gameblock[i][o] *=2
                    gameblock[i][o-1] = 0
                    merged[i] = 1
                    counter += 1

            for o in range(3,0,-1):
                for a in range(1,o+1):      
                    if gameblock[i][o-a] != 0 and gameblock[i][o] == 0:
                        gameblock[i][o] = gameblock [i][o-a]
                        gameblock[i][o-a] = 0
                        counter += 1
    if counter >= 1:
        placenumber()
        decwin()

def decwin():
    for i in gameblock:
        if 2048 in i:
            print("Yon Won!")
            exit()

    counter = 0
    for i in range(0,3):
        for o in range(0,4):
            if gameblock[i][o] == gameblock[i+1][o] or gameblock[i+1][o] == 0:
                counter += 1
    for o in range(0,3):
        for i in range(0,4):
            if gameblock[i][o] == gameblock[i][o+1] or gameblock[i][o+1] == 0:
                counter += 1
    if counter == 0:
        print("You Lost!")
        exit()
#執行區

default() #初始化
while 1:    
    os.system("cls")
    printgame()
    move()
    time.sleep(0.2)