#ifndef VECTOR_H
#define VECTOR_H

#define DEFAULT_CAPACITY 10
#define CELL_SIZE_BIT ((sizeof(unsigned char))*8)
#define CELL_SIZE_BYTE (sizeof(unsigned char))

template <typename TData>
class Vector
{
public:
    Vector() noexcept;
    Vector(unsigned int size);
    Vector(unsigned int size, const TData& val);
    Vector(const Vector& vec) noexcept;
    Vector(const Vector&& vec) noexcept;
    ~Vector();
    Vector& operator=(const Vector& vec);
    Vector& operator=(const Vector&& vec);
    void push_back(const TData& val);
    TData* insert(unsigned int index, const TData& val);
    TData* erase(unsigned int index);
    void pop_back();
    bool empty() const;
    void clear();
    void reserve(unsigned int new_cap);
    unsigned int size() const;
    unsigned int capacity() const;
    TData& at(unsigned int index) const;
    TData& operator[](unsigned int index) const;
    TData* begin() const;
    TData* end() const;
    TData& front() const;
    TData& back() const;
private:
    TData * array_v;
    unsigned int size_v;
    unsigned int capacity_v;
    void initial_reverse();
};

class BoolReference;

template <>
class Vector<bool>
{
public:
    Vector() noexcept;
    Vector(unsigned int size);
    Vector(unsigned int size, const BoolReference& val);
    Vector(unsigned int size, bool val);
    Vector(const Vector& vec) noexcept;
    Vector(const Vector&& vec) noexcept;
    ~Vector();
    Vector& operator=(const Vector& vec);
    Vector& operator=(const Vector&& vec);
    void push_back(const BoolReference& val);
    void push_back(bool val);
    BoolReference insert(unsigned int index, const BoolReference& val);
    BoolReference insert(unsigned int index, bool val);
    BoolReference erase(unsigned int index);
    void pop_back();
    bool empty() const;
    void clear();
    void reserve(unsigned int new_cap);
    unsigned int size() const;
    unsigned int capacity() const;
    BoolReference at(unsigned int index) const;
    BoolReference operator[](unsigned int index) const;
    BoolReference begin() const;
    BoolReference end() const;
    BoolReference front() const;
    BoolReference back() const;
private:
    unsigned char* array_v;
    unsigned int size_v;
    unsigned int capacity_v;
    void initial_reverse();
};


class BoolReference
{
public:
    BoolReference(unsigned char &cell, unsigned char shift);
    unsigned char &cell;
    unsigned char index;
    BoolReference& operator=(bool x) noexcept;
    BoolReference& operator=(const BoolReference& x) noexcept;
    operator bool() const noexcept;
};

#include "Vector.cpp"

#endif
