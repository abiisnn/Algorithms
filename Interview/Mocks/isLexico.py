# a <= b;
def compare(a, b):
    ans = True # assume 'a' is smaller
    same = True
    for i in range(0, min(len(a), len(b))):
        if b[i] != a[i]:
            same = False
        if b[i] < a[i]:
            ans = False
    if (same):
        if len(a) <= len(b):
            return True
        else:
            return False
    
    return ans

def isLexico(listWords):
    ans = True
    for i in range(0, len(listWords) - 1):
        if not compare(listWords[i], listWords[i + 1]): # a < b
            ans = False
    return ans
    

l = ["aa", "aaa", "bb"]
print("Lexico", isLexico(l))


a = "aa"
b = "aaa"

print(a < b)
print(compare(a, b))