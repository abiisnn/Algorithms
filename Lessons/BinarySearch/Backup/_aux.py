# python3 aux.py
beginRed = "\033[48;5;197m\033[38;5;15m"
endColor = "\033[0m"

beginBlue = "\033[48;5;21m\033[38;5;15m"
beginYellow = "\033[48;5;100m\033[38;5;15m"


def toColoredList(arr):
    mid = (len(arr) - 1) // 2
    ans = str(arr)
    pos = (mid + 1) * 3 - 2
    ans = ans[:pos] + beginRed + ans[pos] + endColor + ans[pos + 1:]
    return ans

arr = list(map(int, "0 1 2 3 3 3 3 5 6 7 8 0".split()))
e = 4

# arr = list(map(int, input().split()))
# e = int(input())

l = 1; r = len(arr) - 2;
while (l <= r):
    mid = l + (r - l) // 2
    print(("   " * (l + 1))[:-1] + beginBlue + "l" + endColor)
    print("   " * l, toColoredList(arr[l:r + 1]), "size =", r - l + 1)
    print(("   " * (r + 1))[:-1] + beginYellow + "r" + endColor)
    print("=====================================================")
    if (arr[mid] < e):
        l = mid + 1
    elif (arr[mid] > e):
        r = mid - 1
    else:
        r = mid - 1


print(("   " * (l + 1))[:-1] + beginBlue + "l" + endColor)
print("   ", arr[1:len(arr) - 1])
print(("   " * (r + 1))[:-1] + beginYellow + "r" + endColor)

print(r, l)

'''

busco: 5

lista: 1 2 2 3 3 3 4 4 4 4 5 6 6 6 6 6


'''
