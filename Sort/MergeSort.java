import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class MergeSort {
    private static final int THREAD_POOL_SIZE = 4;
    private static final ExecutorService executorService = Executors.newFixedThreadPool(THREAD_POOL_SIZE);
    public static void main(String args[]) {
        List<Integer>li = new LinkedList<>();
        int []arr = new int[] {1, 5, 4, 2, 3};
        for (int i : arr) {
            li.add(i);
        }
        li = sort(li);
        for (int i = 0; i < 5; ++i) {
            System.out.print(li.get(i) + ' ');
        }
        System.out.println();

    }

    public static int getThreadPoolSize() {
        return THREAD_POOL_SIZE;
    }

    public static ExecutorService getExecutorservice() {
        return executorService;
    }

    public static <T extends Comparable<? super T>> List<T> sort(List<T> list) throws InterruptedException, ExecutionException {
        if (list.size() <= 1) {
            return list;
        }

        int mid = list.size() / 2;
        List<T> left = list.subList(0, mid);
        List<T> right = list.subList(mid, list.size());

        Future<List<T>> leftFuture = executorService.submit(() -> sort(left));
        Future<List<T>> rightFuture = executorService.submit(() -> sort(right));

        return merge(leftFuture.get(), rightFuture.get());
    }

    private static <T extends Comparable<? super T>> List<T> merge(List<T> left, List<T> right) {
        List<T> result = new ArrayList<>(left.size() + right.size());

        int i = 0, j = 0;
        while (i < left.size() && j < right.size()) {
            if (left.get(i).compareTo(right.get(j)) <= 0) {
                result.add(left.get(i++));
            } else {
                result.add(right.get(j++));
            }
        }

        while (i < left.size()) {
            result.add(left.get(i++));
        }

        while (j < right.size()) {
            result.add(right.get(j++));
        }

        return result;
    }
}
