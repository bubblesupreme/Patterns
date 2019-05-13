#ifndef VECTOR_H
#define VECTOR_H

#include <iterator>

#define DEFAULT_CAPACITY 10
#define BOOL_BOX unsigned char
#define CELL_SIZE_BIT ((sizeof(BOOL_BOX))*8)
#define CELL_SIZE_BYTE (sizeof(BOOL_BOX))

template <typename TData>
class Vector
{
public:
    class iterator_v
        : public std::iterator<std::random_access_iterator_tag, TData>
    {
    public:
        using pointer = typename std::iterator<std::random_access_iterator_tag, TData>::pointer;
        using reference = typename std::iterator<std::random_access_iterator_tag, TData>::reference;
    private:
        pointer buff_v;
    public:
        explicit iterator_v(pointer tab) noexcept;
        iterator_v& operator++();
        iterator_v operator++(int);
        iterator_v& operator--();
        iterator_v operator--(int);
        bool operator==(const iterator_v &iter);
        bool operator!=(const iterator_v &iter);
        reference operator*();
    };
    Vector() noexcept;
    Vector(unsigned int size);
    Vector(unsigned int size, const TData& val);
    Vector(const Vector& vec) noexcept;
    Vector(const Vector&& vec) noexcept;
    ~Vector();
    Vector& operator=(const Vector& vec);
    Vector& operator=(const Vector&& vec);
    void push_back(const TData& val);
    iterator_v insert(unsigned int index, const TData& val);
    iterator_v erase(unsigned int index);
    void pop_back();
    bool empty() const;
    void clear();
    void reserve(unsigned int new_cap);
    unsigned int size() const;
    unsigned int capacity() const;
    TData& at(unsigned int index) const;
    TData& operator[](unsigned int index) const;
    iterator_v begin() const;
    iterator_v end() const;
    TData& front() const;
    TData& back() const;
private:
    TData * array_v;
    unsigned int size_v;
    unsigned int capacity_v;
    void initial_reverse();
};


template <>
class Vector<bool>
{
public:
    class BoolReference
    {
    public:
        BoolReference(BOOL_BOX &cell, unsigned char index);
        BOOL_BOX &cell;
        unsigned char index;
        BoolReference& operator=(bool x) noexcept;
        BoolReference& operator=(const BoolReference& x) noexcept;
        operator bool() const noexcept;
    };
    class iterator_v
        : public std::iterator<std::random_access_iterator_tag, bool>
    {
    public:
        using pointer = typename std::iterator<std::random_access_iterator_tag, BOOL_BOX>::pointer;
    private:
        pointer buff_v;
        unsigned int cell_index;
    public:
        explicit iterator_v(pointer tab, unsigned int cell_index) noexcept;
        iterator_v& operator++();
        iterator_v operator++(int);
        iterator_v& operator--();
        iterator_v operator--(int);
        bool operator==(const iterator_v &iter);
        bool operator!=(const iterator_v &iter);
        BoolReference operator*();
    };
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
    iterator_v insert(unsigned int index, const BoolReference& val);
    iterator_v insert(unsigned int index, bool val);
    iterator_v erase(unsigned int index);
    void pop_back();
    bool empty() const;
    void clear();
    void reserve(unsigned int new_cap);
    unsigned int size() const;
    unsigned int capacity() const;
    BoolReference at(unsigned int index) const;
    BoolReference operator[](unsigned int index) const;
    iterator_v begin() const;
    iterator_v end() const;
    BoolReference front() const;
    BoolReference back() const;
private:
    BOOL_BOX* array_v;
    unsigned int size_v;
    unsigned int capacity_v;
    void initial_reverse();
};

#include "Vector.cpp"

#endif
