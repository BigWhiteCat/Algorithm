#ifndef STUDENTRECORD_H
#define STUDENTRECORD_H

#include <iostream>
#include <string>

struct StudentRecord {
    bool operator!=(const StudentRecord &rh) const {
        return score != rh.score;
    }

    int score;
    std::string *name;
};

inline std::ostream &operator<<(std::ostream &out, const StudentRecord &rh) {
    out << rh.score << "  " << *rh.name << std::endl;
    return out;
}

#endif  // STUDENTRECORD_H
