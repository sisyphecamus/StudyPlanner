
#include "Task.h"

Task::Task(const std::string& t, std::chrono::system_clock::time_point ddl, int p, bool review)
    : title(t), deadline(ddl), priority(p), needsReview(review) {}

std::string Task::getTitle() const { return title; }
std::chrono::system_clock::time_point Task::getDeadline() const { return deadline; }
int Task::getPriority() const { return priority; }
bool Task::getNeedsReview() const { return needsReview; }
