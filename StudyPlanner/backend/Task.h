
#ifndef TASK_H
#define TASK_H

#include <string>
#include <chrono>

class Task {
private:
    std::string title;
    std::chrono::system_clock::time_point deadline;
    int priority;
    bool needsReview;

public:
    Task(const std::string& t, std::chrono::system_clock::time_point ddl, int p = 1, bool review = false);
    std::string getTitle() const;
    std::chrono::system_clock::time_point getDeadline() const;
    int getPriority() const;
    bool getNeedsReview() const;
};

#endif
