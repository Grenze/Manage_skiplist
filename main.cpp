


#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include "Interval_skip_list_interval.h"
#include "Interval_skip_list.h"

typedef ISL::Interval_skip_list_interval<double> Interval;
typedef ISL::Interval_skip_list<Interval> Interval_skip_list;

int main() {
    Interval_skip_list islSample;
    int i, n, d;
    n=20;d=3;
    std::vector<Interval> intervals(n);
    for(i=0;i<n;i++){
        intervals[i] = Interval(i, i+d);
    }
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

    //std::ostream & osSample = std::cout;
    //std::cout<<intervals[0];

    islSample.print(std::cout);
    islSample.printOrdered(std::cout);

    for(i = 0; i < n; i++) {
        islSample.remove(intervals[i]);
    }


    return 0;


}