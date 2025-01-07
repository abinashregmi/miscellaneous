import random
random.randint

lst=['rock','paper', 'scissor']
alish=random.choice(lst)

# print('Alish Rai won', alish)

anup=random.choice(lst)
# print('Anup won', anup)

bimal=random.choice(lst)
# print('Bimal won', bimal)

if alish== "rock" and anup =="scissor" and bimal == "paper":
    print('anup won')
    
elif alish== "rock" and anup == "paper" and bimal == "scissor":
        print('bimal won')
elif alish== "rock" and anup == "rock" and bimal == "rock":
      print("Tie")

elif alish== "paper"and anup=="rock"and bimal=="scissor":
      print('bimal won')

else:
      print('bimal won ')
