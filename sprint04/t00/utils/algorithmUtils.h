#ifndef LIB

#include <algorithm>

template <typename T>
bool IsInRange(const T& val, const T& from, const T& to) {
    return (std::find(from, to, *val) != to) ? true : false;
}

template <typename T>
bool IsInRange(const T& val, const std::pair<const T, const T>& minmax) {
    return (std::find(minmax.first, minmax.second, *val) != minmax.second) ? true : false;
}

template <typename T>
bool IsInsideRange(const T& val, const T& from, const T& to) {
    auto p = std::find(from, to, *val);

    if (p == from || to == p++)
        return false;
    if (p == to)
        return false;
    return true;
}

template <typename T>
bool IsInsideRange(const T& val, const std::pair<const T&, const T&>& minmax) {
    auto p = std::find(minmax.first, minmax.second, *val);

    if (p == minmax.first || minmax.second == p++)
        return false;
    if (p == minmax.second)
        return false;
    return true;
}

template <class T, class U = T>
bool Modify(T& obj, U&& new_value) {
    if (obj == new_value)
        return false;
    obj = new_value;
    return true;
}

template <class Collection, class T>
void RemoveAll(Collection& c, const T& value) {
    std::remove(c.begin(), c.end(), value);
}

template <class Collection, class Pred>
void RemoveAllIf(Collection& c, Pred&& predicate) {
    std::remove_if(c.begin(), c.end(), predicate);
}

template <class Collection, class T>
auto Find(Collection& c, const T& value) {
    return std::find(c.begin(), c.end(), value);
}

template <class Collection, class Pred>
auto FindIf(Collection& c, Pred&& predicate) {
    return std::find_if(c.begin(), c.end(), predicate);
}

template <class Collection, class T>
bool Contains(const Collection& c, const T& value)  {
    if (std::find(c.begin(), c.end(), value) == c.end())
        return false;
    return true;
}

template <class Collection, class Pred>
bool ContainsIf(const Collection& c, Pred&& predicate) {
    if (std::find_if(c.begin(), c.end(), predicate) == c.end())
        return false;
    return true;
}

template <class Collection, class Pred>
int CountIf(const Collection& c, Pred&& predicate) {
    return std::count_if(c.begin(), c.end(), predicate);
}

//////////////////
template <class T>
const auto& Min(const T& arg) {
    return arg;
}

template <class T, class ...Args>
const auto& Min(const T& arg, const Args&... args) {
    auto m = std::minmax(arg, Min(args...));
    return m.first;
}
//////////////////
template <class T>
const auto& Max(const T& arg) {
    return arg;
}

template <class T, class ...Args>
const auto& Max(const T& arg, const Args&... args) {
    auto m = std::minmax(arg, Max(args...));
    return m.second;
}
//////////////////

template <class Collection>
auto MaxElement(const Collection& c) {
    return std::max_element(c.begin(), c.end());
}

template <class Collection>
auto MinElement(const Collection& c) {
    return std::min_element(c.begin(), c.end());
}

template <class Collection, class Comp>
auto MaxElement(const Collection& c, Comp&& comparator) {
    return *std::max_element(c.begin(), c.end(), comparator);
}

template <class Collection, class Comp>
auto MinElement(const Collection& c, Comp&& comparator) {
    return *std::min_element(c.begin(), c.end(), comparator);
}

template <class Collection>
void Sort(Collection& c) {
    std::sort(c.begin(), c.end());
}

template <class Collection, class Comp>
void Sort(Collection& c, Comp&& comparator) {
    std::sort(c.begin(), c.end(), comparator);
}

// // remove all not unique elements in collection

template <class Collection>
void Unique(Collection& c) {
    std::unique(c.begin(), c.end());
}

template <class Collection, class Pred>
void Unique(Collection& c, Pred&& predicate) {
    std::unique(c.begin(), c.end(), predicate);
}

template <class Collection, class Pred>
void ForEach(Collection& c, Pred&& predicate) {
    std::for_each(c.begin(), c.end(), predicate);
}

template <class Collection, class T>
int IndexOf(const Collection& c, const T& value) {
    return std::distance(c.begin(), std::find(c.begin(), c.end(), value));
}

template <class Collection, class Pred>
int IndexOfIf(const Collection& c, Pred&& predicate) {
    return std::distance(c.begin(), std::find_if(c.begin(), c.end(), predicate));
}

#endif
