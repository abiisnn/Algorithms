color1 = "\033[48;5;27m\033[38;5;15m"
color2 = "\033[48;5;196m\033[38;5;15m"
color3 = "\033[48;5;13m\033[38;5;15m"
endColor = "\033[0m"

def min(a, b):
    if(a < b):
        return a
    return b
def max(a, b):
    if(a > b):
        return a
    return b

def printList(arr, pos, l, r, color):
    mylist = arr.copy()
    mylist[pos] = color + str(mylist[pos]) + endColor
    end = min(r+1, len(arr))

    for i in range(0, max(0, l)):
        size = len(str(mylist[i]))
        mylist[i] = str(" " * size)

    for i in range(0, end):
       print(str(mylist[i]) + " \n"[1 if i + 1 == end else 0], end="")


def printListWithSpaces(arr, pos, color):
    mylist = arr.copy()
    for i in range(len(mylist)):
        mylist[i] = " " * len(str(mylist[i]))
    printList(mylist, pos, pos, len(arr), color)

arr = list(map(int, input().split()))
target = int(input())

lines = 25
print()
print("Target =", target)
print()
print("="  * lines, 1, "=" * lines)

arr = [50] + arr
arr = arr + [50]
left = 1
right = len(arr) - 2
ite = 2
while (left <= right):
    mid = left + (right - left) // 2
    printListWithSpaces(arr, left, color1)
    printList(arr, mid, left, right, color2)
    printListWithSpaces(arr, right, color3)
    print("=" * lines, ite, "=" * lines)
    if arr[mid] < target:
        left = mid + 1
    elif arr[mid] > target:
        right = mid - 1
    else:
        right = mid - 1
    ite = ite + 1

printListWithSpaces(arr, left, color1)
printList(arr, mid, 1, len(arr)-2, color2)
printListWithSpaces(arr, right, color3)
print()
print("Numero de iteraciones:", ite-1)
print(color1 + "Left:" + endColor, left, "|", color3 + "Right:" + endColor, right)

if left < len(arr) - 1:
    print("Lower bound de " + str(target) + " es " + str(arr[left]))
else:
    print("Lower bound de " + str(target) + " no existe")