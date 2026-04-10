#include <iostream>
#include <thread>
#include <semaphore>
using namespace std;

// Binary semaphore
binary_semaphore bin_sem(1);

// Counting semaphore (max 3 threads)
counting_semaphore<3> count_sem(3);

void binaryTask(int id) {
    bin_sem.acquire();
    cout << "Binary Semaphore: Thread " << id << " inside critical section\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Thread " << id << " leaving\n";
    bin_sem.release();
}

void countingTask(int id) {
    count_sem.acquire();
    cout << "Counting Semaphore: Thread " << id << " inside\n";
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Thread " << id << " leaving\n";
    count_sem.release();
}

int main() {
    thread t1(binaryTask, 1);
    thread t2(binaryTask, 2);

    t1.join();
    t2.join();

    cout << "\n--- Counting Semaphore ---\n";

    thread t3(countingTask, 1);
    thread t4(countingTask, 2);
    thread t5(countingTask, 3);
    thread t6(countingTask, 4);

    t3.join(); t4.join(); t5.join(); t6.join();

    return 0;
}