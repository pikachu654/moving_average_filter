#pragma once

#include <stddef.h>

// Uncomment this line when using print() method.
#include <iostream>

namespace mtrn3100 {

template <typename T, size_t N>
class MovingAverageFilter {
public:
    // Adds a data sample to the filter's history. The history only looks at the N most recent samples. If there are
    // already N samples, then older samples are discarded and replaced by new samples.
    void sample(T data) {
        if (head == empty) {
            head = 0;
            tail = 0;
        }

        samples[head] = data;

        if (head >= (N - 1) ) {
            head = 0;
            full = true;
            tail = N-1;
        }
        else{
            head++;
            if (full == true) {
                tail++;
            }
        }
        
    }

    // Computes the running average value of the N most recent samples.
    template <typename U = T>
    U average() const {
        // COMPLETE THIS FUNCTION.
        double average = 0;
        if (isEmpty() == true) {
            return 0;
        }
        for (size_t i = 0; i < size(); i++) {
            average += samples[i];

        }
        average = average / size();
        return average;
    }

    // History is empty if there are 0 samples.
    bool isEmpty() const { return head == empty; }

    // History is full if there are N samples.
    bool isFull() const {
        int total = (head + 1) % N;
        std:: cout << total << tail << "\n" ;
        return full;
    }
    // Current number of samples saved in history.
    size_t size() const {
        // COMPLETE THIS FUNCTION.
        if (isFull() == true) {
            return N;
        }
        else if(isEmpty() == true) {
            return 0;
        }
        else{
            return head;
        }
        return 0;
    }

    // The max size of history.
    size_t capacity() const { return N; }

    // Delete all saved samples.
    void clear() {
        for (size_t i = 0; i < N; i++) {
            samples[i] = {};
        }
        head = empty;
        tail = empty;
        full = false;
    }

    // Debugging function to visualise the MAF.
    // Uncomment this if you want to debug with doctest. Remember that std::cout is not available on Arduino so
    // replace std::cout with Serial.print or keep this method commented.
    // void print() const {
    //     for (size_t i = 0; i < size(); i++) {
    //         auto sample = samples[(tail + i) % N];
    //         std::cout << sample << ", ";
    //     }
    //     std::cout << std::endl;
    // }

private:
    T samples[N];  // Data is a circular buffer stored as [tail, ..., head].
    static constexpr size_t empty = -1;
    bool full = false;
    size_t head = empty;  // Represents the index of the end of the list.
    size_t tail = empty;  // Represents the index of the start of the list.
};

}  // namespace mtrn3100