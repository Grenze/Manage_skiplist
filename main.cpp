


#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <cstring>
#include <chrono>
#include "Interval_skip_list_interval.h"
#include "Interval_skip_list.h"

typedef ISL::Interval_skip_list_interval<double> Interval;
typedef ISL::Interval_skip_list<Interval> Interval_skip_list;



::std::uint64_t NowNanos() {
    return static_cast<uint64_t>(::std::chrono::duration_cast<::std::chrono::nanoseconds>(
            ::std::chrono::steady_clock::now().time_since_epoch())
            .count());
}

int main() {
    auto start_time = NowNanos();

    Interval_skip_list islSample;
    int i, n, d;
    n=20;d=3;
    std::vector<Interval> intervals(n);
    for(i=0;i<n-1;i++){
        intervals[i] = Interval(i, i+d);
    }
    intervals[n-1] = Interval(0, 100);
    std::random_shuffle(intervals.begin(), intervals.end());
    islSample.insert(intervals.begin(), intervals.end());

    for(i = 0; i < n+d; i++) {
        std::list<Interval> L;
        islSample.find_intervals(i, std::back_inserter(L));
        for(std::list<Interval>::iterator it = L.begin(); it != L.end(); it++){
            std::cout << *it;
        }
        std::cout << std::endl;
    }

    //Interval interval = Interval(1, 10);

    //islSample.remove(interval);
    //islSample.remove(interval);   error here.

    islSample.print(std::cout);
    islSample.printOrdered(std::cout);

    for(i = 0; i < n; i++) {
        islSample.remove(intervals[i]);
    }

    auto end_time = NowNanos();
    std::cout<< "nanosecond: "<<end_time - start_time <<std::endl;





/*
    struct node{
        int seq;
    };
    node* nodes = new node[10];
    for(i = 0;i<10;i++){
        nodes[i].seq = i;
    }
    node* no = &nodes[2];
    no++;
    std::cout<<no->seq<<std::endl;

    int* a = new int[100];
    for(i = 0;i<10;i++){
        a[i] = i;
    }
    int* b = &a[1];
    b++;
    //b = nullptr;

    (1>0)?b = a:b++;
    std::cout<<*b<<"bool: "<<true<<" "<<sizeof(a)<<std::endl;

    uint32_t aa = 0X70000000;
    std::cout<<(int)aa<<std::endl;

    struct Node {
        explicit Node() : call(0) {
            next_ = new Node*[1];
        };
        ~Node() {
            if (next_ != nullptr) {
                delete[] next_;
            }
        }
        int call;
    private:
        Node** next_;
    };

    class wrapper{
    public:
        explicit wrapper(int num) :
                        capacity(num),
                        num_(0),
                        nodes_(new Node[num + 2]),
                        head_(&nodes_[0]),
                        tail_(&nodes_[1])
                        {
            assert(head_+1 == tail_);
            for (int i = 0; i < capacity + 2; i++) {
                assert(nodes_[i].call == 0);
            }
        }
        int num_;
        Node* nodes_;
        const int capacity;
        Node* head_;
        Node* tail_;
        ~wrapper() {
            delete[] nodes_;
        }
    };

    wrapper* wrapper1 = new wrapper(1000);
*/


    return 0;


}
