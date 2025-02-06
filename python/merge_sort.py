import random
def merge(a,b):
    merged = []
    while a and b:
        if a[0] < b[0]:
            merged.append(a.pop(0))
        else:
            merged.append(b.pop(0))
    if a:
        merged.append(a.pop(0))
    else:
        merged.append(b.pop(0))
    return merged
def merge_sort(dat):
    if len(dat) == 1:
        return dat
    mid = len(dat) // 2
    return merge(merge_sort(dat[:mid]),merge_sort(dat[mid:]))
test = [random.randint(1,100) for i in range(100000)]
print(test)
print(merge_sort(test))
