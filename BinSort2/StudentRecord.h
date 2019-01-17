#ifndef STUDENTRECORD_H
#define STUDENTRECORD_H

#include <iostream>
#include <string>

struct StudentRecord {
    operator int() const {
        return score;
    }

    int score;
    std::string *name;
};

inline std::ostream &operator<<(std::ostream &out, const StudentRecord &record) {
    std::cout << record.score << "  " << *record.name << std::endl;
    return out;
}

#endif  // STUDENTRECORD_H
