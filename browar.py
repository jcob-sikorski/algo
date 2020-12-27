n = 6
data = [(1, 2), (2, 3), (1, 2), (5, 2), (1, 10), (2, 3)]

SUMA = float("inf")

for i in range(1, len(data)+1):
    start_right = []
    start_left = []

    # optimal = []


    # loop from right
    d = 0

    for j in range(i, len(data)): #
        d += data[j-1][1]

        z = data[j][0]

        # koszt do j-tego miasta
        start_right.append(((d, z), j))

    if i != 1:
        # calculate for cycle connecting node
        d += data[len(data)-1][1]
        z = data[0][0]

        # koszt do j-tego miasta
        start_right.append(((d, z), 0))

    # completes the cycle
    for j in range(1, i-1):
        d += data[j-1][1]

        z = data[j][0]

        # koszt do j-tego
        start_right.append(((d, z), j))



    # loop from left
    d = 0

    # completes the cycle
    for j in reversed(range(1, i)):
        d += data[j-1][1]

        z = data[j-1][0]

        # koszt do j-tego miasta
        start_left.append(((d, z), j-1))

    if i != len(data):
        # calculate for cycle connecting node
        d += data[len(data)-1][1]
        z = data[1][0]

        # koszt do j-tego miasta
        start_left.append(((d, z), len(data)-1))

    for j in reversed(range(i+1, len(data))):
        d += data[j-1][1]

        z = data[j-1][0]

        # koszt do j-tego miasta
        start_left.append(((d, z), j-1))

    suma = 0

    start_left.reverse()

    print("________________________________")
    print(f"right {start_right}")
    # print(f"left {start_left}")

    # for i in range(len(data)-1):
    #     r = start_right[i][0]
    #     l = start_left[i][0]
    #     optimal.append(min(r, l))
    #     suma += optimal[i]
    
    # SUMA = min(SUMA, suma)
    # print(f"suma = {suma}")

print(f"#suma = {SUMA}")
