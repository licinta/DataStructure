import random


def shift_right(li, i, j):  # [i,j)
    mem = li[j-1]
    for k in range(j-1, i, -1):
        li[k] = li[k-1]
    li[i] = mem


def insert_sort(li):
    n = len(li)
    for i in range(n):
        p = i-1
        current = li[i]
        while p >= 0 and current < li[p]:  # find the inserted bit
            li[p+1] = li[p]
            p -= 1
        li[p+1] = current


def binary_insert_sort(li):
    n = len(li)
    import bisect
    for i in range(1, n):
        current = li[i]
        li.insert(bisect.bisect_left(li[:i], current), current)
        del li[i+1]


def quick_sort(li):
    n = len(li)
    if n <= 1:
        return li
    p = random.randint(0, n-1)
    mid = [li[p]]
    lef, rig = [], []
    for i in range(n):
        if i == p:
            continue
        if li[i] <= li[p]:
            lef.append(li[i])
        else:
            rig.append(li[i])
    return quick_sort(lef)+mid+quick_sort(rig)


def merge_sort(li):
    n = len(li)
    if n <= 1:
        return li
    mid = n >> 1
    l, r = merge_sort(li[:mid]), merge_sort(li[mid+1:])
    arr = []
    p, q = 0, 0
    while p < len(l) and q < len(r):
        if l[p] <= r[q]:
            arr.append(l[p])
            p += 1
        else:
            arr.append(r[q])
            q += 1
    while p < len(l):
        arr.append(l[p])
        p += 1
    while q < len(r):
        arr.append(r[q])
        q += 1
    return arr


def shell_sort(li):
    return


def cardical_sort(li):
    n = len(li)
    num = [[] for i in range(2)]
    bit = 0
    while True:
        bk = False
        while len(li):
            i = li.pop()
            num[(i >> bit) & 1].append(i)
            if len(num[(i >> bit) & 1]) == n:
                bk = True
        for i in range(2):
            for j in range(len(num[i])):
                li.append(num[i].pop())
        if bk:
            break
        else:
            bit += 1


class heap:
    def __init__(self, maxsize=100):
        self.li = [-0x3fffffff for i in range(maxsize*2+1)]
        self.p = 0

    def _up(self, idx: int) -> None:
        while idx > 1 and self.li[idx] > self.li[idx >> 1]:
            self.li[idx], self.li[idx >> 1] = self.li[idx >> 1], self.li[idx]
            idx >>= 1

    def _down(self, idx: int) -> None:
        while True:
            l, r, p = (idx << 1) | 0, (idx << 1) | 1, idx
            if idx <= self.p and self.li[p] < max(self.li[l], self.li[r]):
                if self.li[r] > self.li[l]:
                    self.li[r], self.li[p] = self.li[p], self.li[r]
                    idx = r
                else:
                    self.li[l], self.li[p] = self.li[p], self.li[l]
                    idx = l
            else:
                break

    def top(self) -> object:
        return self.li[1]

    def push(self, val: object) -> None:
        self.p += 1
        self.li[self.p] = val
        self._up(self.p)

    def pop(self) -> None:
        self.li[1] = -0x3fffffff
        self.li[1], self.li[self.p] = self.li[self.p], self.li[1]
        self.p -= 1
        self._down(1)

    def __bool__(self) -> bool:
        return self.p >= 1


def heap_sort(li):
    n = len(li)
    h = heap(maxsize=n)
    while li:
        h.push(li.pop())
    while h:
        li.append(h.top())
        h.pop()
    return li[::-1]
