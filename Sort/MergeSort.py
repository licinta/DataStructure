import random
import threading
import sys
import time
sys.setrecursionlimit(100006)


def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left_arr = arr[:mid]
        right_arr = arr[mid:]
        # 创建两个线程分别对左右两个子数组进行归并排序
        left_thread = threading.Thread(target=merge_sort, args=(left_arr,))
        right_thread = threading.Thread(target=merge_sort, args=(right_arr,))
        left_thread.start()
        right_thread.start()
        # 等待两个线程结束
        left_thread.join()
        right_thread.join()
        # 合并两个有序子数组
        i = j = k = 0
        while i < len(left_arr) and j < len(right_arr):
            if left_arr[i] < right_arr[j]:
                arr[k] = left_arr[i]
                i += 1
            else:
                arr[k] = right_arr[j]
                j += 1
            k += 1

        while i < len(left_arr):
            arr[k] = left_arr[i]
            i += 1
            k += 1

        while j < len(right_arr):
            arr[k] = right_arr[j]
            j += 1
            k += 1


def merge_sort_multithreaded(arr):
    # 创建一个线程对整个数组进行归并排序
    thread = threading.Thread(target=merge_sort, args=(arr,))
    thread.start()
    thread.join()
    return arr


arr = [random.randint(1, 10000) for i in range(1000)]
a = time.time()
sorted_arr = merge_sort_multithreaded(arr)
b = time.time()
print(b-a)  # 输出 [1, 2, 3, 4, 5, 6, 7, 8]

a = time.time()
sorted_arr = sorted(arr)
b = time.time()
print(b-a)  # 输出 [1, 2, 3, 4, 5, 6, 7, 8]
