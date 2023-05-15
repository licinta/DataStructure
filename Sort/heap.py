class heap:
    def __init__(self, maxsize=100):
        self.li = [0 for i in range(maxsize*2+1)]
        self.p = 0

    def _up(self, idx: int) -> void:
        while idx > 1:
            if self.li[idx] > self.li[idx >> 1]:
                self.li[idx], self.li[idx >> 1] = self.li[idx >> 1], self.li[idx]
            idx >>= 1

    def _down(self, idx: int) -> void:
        while True:
            l, r, p = (idx << 1) | 0, (idx << 1) | 1, idx
            if idx <= self.p and self.li[p] < max(self.li[l], self.li[r]):
                if self.li[l] > self.li[r]:
                    self.li[l], self.li[p] = self.li[p], self.li[l]
                    idx = l
                else:
                    self.li[r], self.li[p] = self.li[p], self.li[r]
                    idx = r
            else:
                break

    def top(self) -> object:
        return self.li[1]

    def push(self, val: object) -> void:
        self.p += 1
        self.li[self.p] = val
        self._up(self.p)

    def pop(self) -> void:
        self.li[1], self.li[self.p] = self.li[self.p], self.li[1]
        self.p -= 1
        self._down(1)
