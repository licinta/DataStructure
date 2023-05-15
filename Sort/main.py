import random
import Sort as s


def prt(li, name: str):
    print(name.rjust(8), ":", end=' ')
    for i in li:
        print(f"{i:3d}", end=' ')
    print()


li = [random.randint(0, 20) for i in range(5)]
prt(li, "list")
standard = li[:]
standard.sort()
prt(standard, "sort")
insert = li[:]
s.insert_sort(insert)
prt(insert, "insert")
binsert = li[:]
s.binary_insert_sort(binsert)
prt(binsert, "binsert")
quick = li[:]
quick = s.quick_sort(quick)
prt(quick, "quick")
merge = li[:]
merge = s.quick_sort(merge)
prt(merge, "merge")
cardic = li[:]
s.cardical_sort(cardic)
prt(cardic, "cardic")
heap = li[:]
heap = s.heap_sort(heap)
prt(heap, "heap")
