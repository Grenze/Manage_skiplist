//
// Created by lingo on 19-2-19.
//

#ifndef ISL_GISL_HELPER_H
#define ISL_GISL_HELPER_H


#include "GISL.h"


namespace GISL {



    struct KeyComparator {
        int operator()(const int& a, const int& b) const {
            if (a < b) {
                return -1;
            }
            if (a == b) {
                return 0;
            }
            if (a > b) {
                return 1;
            }
        }
    };

    class GeneralIntervalSkipList {
    public:

        explicit GeneralIntervalSkipList(KeyComparator cmp) : index_(cmp) {

        }

        typedef IntervalSkipList<int, KeyComparator> IntegerIndex;
        IntegerIndex index_;

    };


}   // namespace GISL




#endif //ISL_GISL_HELPER_H
