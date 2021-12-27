# push_swap_42
The Push_swap project is a very simple and highly effective algorithm project: data will need to be sorted. You have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks.
You can see full list of available commands I could use in this project in attached pdf, but here are commands I ended up using in that project:
###### **PUSH**
- pa && pb -> move first element to second stack
###### **SWAP**
- sa && sb -> swap first 2 elements with each other in the according stack
###### **ROTATIONS**
- ra && rb -> rotate according stack clockwise
- rra && rrb -> rotate according stack anticlockwise

###### How to run:
Run **make** in your terminal and then ./push_swap "Your_numbers i.e. : 007 -21 +42".

***Final greade: 9 / 10:***
*It sorts 100 numbers in  less than 700 moves (5 / 5) and 500 numbers in less than 7000 moves (4 / 5)
P.S. I am pretty sure that I have optimised every step in my algorithm, but unfortinutly it looks like for large set I simply had to use different algorithm in order to det maximum greade.*

#### My programm contains 3 main sections:
1. Parse and check arguments, initialise structures
<img width="600" alt="Screen Shot 2021-12-06 at 8 19 59 PM" src="https://user-images.githubusercontent.com/96373933/147481258-e8c6b70d-8163-49cf-9ec3-40f0e0965464.png">
2. Presort elements and move them from stack A to B
<img width="600" alt="Screen Shot 2021-12-06 at 8 22 45 PM" src="https://user-images.githubusercontent.com/96373933/147481279-18d371d4-6e07-454b-89a9-feb5ec976795.png">
3. Move all elements from B to A, making sure that A is sorted
<img width="600" alt="Screen Shot 2021-12-06 at 8 25 02 PM" src="https://user-images.githubusercontent.com/96373933/147481294-0a1b0dcd-172d-425c-8c33-1c012bd98c5c.png">

#### How my sorting algorithm works:
#### ***Presort -> move all elements smaller than "mid" to stack B***
  My mid value is set in advance and it takes from 20% to 50% of the values, depending on how many numbers I have in stack A (i.e. for more than 250 numbers in stack A it will take 20% smallest numbers, and when A contains 5 numbers 50% will be pushed). My program calculates how many numbers I need to push to B each iteration and then it rotates stack A clockwise until 2 numbers remain. Then I calculate how many ras and rras I need to do in order to move remaining numbers and move them with the minimum amount of moves it takes. This process is repeated until I have 2 values in stack A or A is sorted.
#### ***Final sort -> move all elements back to stack A and sort them***
  My goal is to make sure that stack A is always sorted at this point or 1 step away from being sorted. Each iteration I search for two highest numbers in stack B. Then I calculate the amount of moves it takes me to move each of them using clockwise and anticlockwise rotations. Then I move the number for which amount of rotations is minimum and move it to stack A. If that was max number I search for the next pair, if not I move max number and perform sa afrer in order to make stack A sorted again.
