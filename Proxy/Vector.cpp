#include <stdexcept>

#ifdef VECTOR_H
#include "Vector.h"
#include <iostream>
#include<string>

unsigned int calculate_real_size(unsigned int size);
unsigned int calculate_real_index(unsigned int index);
void write_bit(unsigned char& changed_char, unsigned int index, bool bit);

template <typename TData>
Vector<TData>::Vector() noexcept
    :array_v(nullptr), size_v(0), capacity_v(0)
{
}

template <typename TData>
Vector<TData>::Vector(unsigned int size)
    :Vector(size, TData())
{
}

template <typename TData>
Vector<TData>::Vector(unsigned int size, const TData& val)
    : size_v(size), capacity_v(size_v)
{
    array_v = new TData [capacity_v];
    for (unsigned int i = 0; i < size_v; i++)
    {
        array_v [i] = val;
    }
}

template <typename TData>
Vector<TData>::Vector(const Vector& vec) noexcept
    :size_v(vec.size_v), capacity_v(vec.capacity_v)
{
    array_v = new TData [capacity_v];
    memcpy(array_v, vec.array_v, size_v*sizeof(TData));
}

template <typename TData>
Vector<TData>::Vector(const Vector&& vec) noexcept
    :size_v(vec.size_v), capacity_v(vec.capacity_v),
    array_v(vec.array_v)
{
}

template <typename TData>
Vector<TData>::~Vector()
{
    delete [] array_v;
}

template <typename TData>
Vector<TData>& Vector<TData>::operator=(const Vector& vec)
{
    if (this != &vec)
    {
        Vector<TData> tmp(vec);
        std::swap(*this, tmp);
    }
    return *this;
}

template <typename TData>
Vector<TData>& Vector<TData>::operator=(const Vector&& vec)
{
    if (this != &vec)
    {
        size_v = vec.size_v;
        capacity_v = vec.capacity_v;
        array_v = vec.array_v;
    }
    return *this;
}

template <typename TData>
void Vector<TData>::push_back(const TData& val)
{
    if (capacity_v == 0)
    {
        initial_reverse();
    }
    else if (size_v >= capacity_v)
    {
        reserve(capacity_v*2);
    }
    array_v[size_v++]=val;
}

template <typename TData>
void Vector<TData>::reserve(unsigned int new_cap)
{
    TData* array_new = new TData [new_cap];
    capacity_v = new_cap;
    memcpy(array_new, array_v, size_v * sizeof(TData));
    delete [] array_v;
    array_v = array_new;
}

template <typename TData>
void Vector<TData>::initial_reverse()
{
    capacity_v = DEFAULT_CAPACITY;
    array_v = new TData [capacity_v];
}

template <typename TData>
TData* Vector<TData>::insert(unsigned int index, const TData& val)
{
    push_back(array_v [size_v - 1]);
    for (unsigned int i = size_v - 1; i > index; --i)
    {
        array_v [i] = array_v [i - 1];
    }
    array_v [index] = val;
    return &array_v [index];
}

template <typename TData>
TData* Vector<TData>::erase(unsigned int index)
{
    for (unsigned int i = index; i < size_v - 1; i++)
    {
        array_v [i] = array_v [i + 1];
    }
    size_v--;
    return &array_v [index];
}


template <typename TData>
void Vector<TData>::pop_back()
{
    size_v--;
}

template <typename TData>
bool Vector<TData>::empty() const
{
    return size_v == 0;
}

template <typename TData>
void Vector<TData>::clear()
{
    size_v = 0;
}

template <typename TData>
unsigned int Vector<TData>::size() const
{
    return size_v;
}

template <typename TData>
unsigned int Vector<TData>::capacity() const
{
    return capacity_v;
}

template <typename TData>
TData & Vector<TData>::at(unsigned int index) const
{
    if (index < size_v)
    {
        return array_v [index];
    }
    throw std::out_of_range("index out of range");
}

template <typename TData>
TData & Vector<TData>::operator[](unsigned int index) const
{
    return array_v [index];
}

template <typename TData>
TData * Vector<TData>::begin() const
{
    return array_v;
}

template <typename TData>
TData * Vector<TData>::end() const
{
    return &array_v [size_v];
}

template <typename TData>
TData&  Vector<TData>::front() const
{
    return *array_v;
}

template <typename TData>
TData&  Vector<TData>::back() const
{
    return array_v [size_v-1];
}

template <typename TData>
std::ostream& operator<<(std::ostream &os, const Vector<TData>& vec)
{
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        os << *it << " ";
    }
    return os;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Vector<bool>::Vector() noexcept
    :array_v(nullptr), size_v(0), capacity_v(0)
{
}

Vector<bool>::Vector(unsigned int size)
    : Vector(size, false)
{
}

Vector<bool>::Vector(unsigned int size, const BoolReference& val)
    : Vector(size, (1 << val.index)  &  val.cell)
{
}

Vector<bool>::Vector(unsigned int size, bool val)
    : size_v(size), capacity_v(size_v)
{
    unsigned int real_size = calculate_real_size(size_v);
    array_v = new unsigned char [real_size];
    for (unsigned int i = 0; i < real_size; i++)
    {
        for (unsigned int j = 0; j < CELL_SIZE_BIT; j++)
        {
            write_bit(array_v [i], j, val);
        }
    }
}

Vector<bool>::Vector(const Vector& vec) noexcept
    :size_v(vec.size_v), capacity_v(vec.capacity_v)
{
    unsigned int real_size = calculate_real_size(size_v);
    array_v = new unsigned char [real_size];
    memcpy(array_v, vec.array_v, real_size * sizeof(CELL_SIZE_BYTE));
}


Vector<bool>::Vector(const Vector&& vec) noexcept
    :size_v(vec.size_v), capacity_v(vec.capacity_v),
    array_v(vec.array_v)
{
}

Vector<bool>::~Vector()
{
    delete [] array_v;
}

Vector<bool>& Vector<bool>::operator=(const Vector& vec)
{
    if (this != &vec)
    {
        Vector<bool> tmp(vec);
        std::swap(*this, tmp);
    }
    return *this;
}

Vector<bool>& Vector<bool>::operator=(const Vector&& vec)
{
    if (this != &vec)
    {
        size_v = vec.size_v;
        capacity_v = vec.capacity_v;
        array_v = vec.array_v;
    }
    return *this;
}

void Vector<bool>::push_back(const BoolReference& val)
{
    push_back((1 << val.index)  &  val.cell);
}


void Vector<bool>::push_back(bool val)
{
    if (capacity_v == 0)
    {
        initial_reverse();
    }
    else if (size_v >= capacity_v)
    {
        reserve(capacity_v * 2);
    }
    unsigned int real_size = calculate_real_size(size_v);
    unsigned int real_index = calculate_real_index(size_v);
    if ((size_v % CELL_SIZE_BIT) == 0 && (size_v / CELL_SIZE_BIT) > 0)
    {
        real_size++;
    }
    write_bit(array_v [real_index], size_v % CELL_SIZE_BIT, val);
    size_v++;
}

void Vector<bool>::reserve(unsigned int new_cap)
{
    unsigned int new_real_size = calculate_real_size(new_cap);
    unsigned int real_size = calculate_real_size(size_v);
    unsigned char* array_new = new unsigned char [new_real_size];
    capacity_v = new_cap;
    memcpy(array_new, array_v, real_size * sizeof(CELL_SIZE_BYTE));
    delete [] array_v;
    array_v = array_new;
}

void Vector<bool>::initial_reverse()
{
    capacity_v = DEFAULT_CAPACITY;
    array_v = new unsigned char [calculate_real_size(capacity_v)];
}

BoolReference Vector<bool>::insert(unsigned int index, const BoolReference& val)
{
    return insert(index, (1 << val.index)  &  val.cell);
}

BoolReference Vector<bool>::insert(unsigned int index, bool val)
{
    size_v++;
    if (size_v >= capacity_v)
    {
        reserve(capacity_v * 2);
    }
    unsigned int real_size = calculate_real_size(size_v);
    unsigned int real_index = calculate_real_index(index);
    unsigned int cell_index = index % CELL_SIZE_BIT;
    unsigned char previous_state = array_v [real_index];
    bool docking_bit = (1 << 0)  &  array_v [real_index];
    array_v [real_index] = array_v [real_index] >> 1;
    for (unsigned int i = 0; i < cell_index; i++)
    {
        write_bit(array_v [real_index], i, (1 << i)  &  previous_state);
    }
    write_bit(array_v [real_index], cell_index, val);
    for (unsigned int i = real_index + 1; i < real_size; i++)
    {
        bool first_bit = (bool((1 << 0)  &  array_v [i]));
        array_v [i] = array_v [i] >> 1;
        write_bit(array_v [i], CELL_SIZE_BIT - 1, docking_bit);
        docking_bit = first_bit;
    }
    return BoolReference(array_v [real_index], cell_index);
}

BoolReference Vector<bool>::erase(unsigned int index)
{
    size_v--;
    unsigned int real_size = calculate_real_size(size_v);
    unsigned int real_index = calculate_real_index(index);
    unsigned int cell_index = index % CELL_SIZE_BIT;
    unsigned char previous_state = array_v [real_index];
    array_v [real_index] = array_v [real_index] << 1;
    for (unsigned int i = 0; i < cell_index; i++)
    {
        write_bit(array_v [real_index], i, (1 << i)  &  previous_state);
    }
    if (real_index < real_size)
    {
        bool docking_bit = (1 << (CELL_SIZE_BIT - 1))  &  array_v [real_index + 1];
        write_bit(array_v [real_index], 0, docking_bit);
        for (unsigned int i = real_index + 1; i < real_size; i++)
        {
            array_v [i] = array_v [i] << 1;
            if (i != real_size - 1)
            {
                bool docking_bit = (1 << (CELL_SIZE_BIT - 1))  &  array_v [i + 1];
                write_bit(array_v [i], 0, docking_bit);
            }
        }
    }
    return BoolReference(array_v [real_index], cell_index);
}

void Vector<bool>::pop_back()
{
    size_v--;
}

bool Vector<bool>::empty() const
{
    return size_v == 0;
}

void Vector<bool>::clear()
{
    size_v = 0;
}

unsigned int Vector<bool>::size() const
{
    return size_v;
}

unsigned int Vector<bool>::capacity() const
{
    return capacity_v;
}

BoolReference Vector<bool>::at(unsigned int index) const
{
    if (index < size_v)
    {
        unsigned int real_index = calculate_real_index(index);
        unsigned int cell_index = index % CELL_SIZE_BIT;
        return BoolReference(array_v [real_index], cell_index);
    }
    throw std::out_of_range("index out of range");
}

BoolReference Vector<bool>::operator[](unsigned int index) const
{
    unsigned int real_index = calculate_real_index(index);
    unsigned int cell_index = index % CELL_SIZE_BIT;
    return BoolReference(array_v [real_index], cell_index);
}

BoolReference Vector<bool>::begin() const
{
    return BoolReference(array_v [0], 0);
}


BoolReference Vector<bool>::end() const
{
    return BoolReference(array_v [calculate_real_index(size_v)], size_v % CELL_SIZE_BIT);
}

BoolReference Vector<bool>::front() const
{
    return BoolReference(array_v [0], 0);
}

BoolReference Vector<bool>::back() const
{
    return BoolReference(array_v [calculate_real_index(size_v)], size_v % CELL_SIZE_BIT - 1);
}

std::ostream& operator<<(std::ostream &os, const Vector<bool>& vec)
{
    for (unsigned int i = 0; i < vec.size(); i++)
    {
        os << vec.at(i) << " ";
    }

    return os;
}



BoolReference& BoolReference::operator=(bool val) noexcept
{
    write_bit(cell, index, val);
    return *this;
}

BoolReference& BoolReference::operator=(const BoolReference& val) noexcept
{
    write_bit(cell, index, (1 << val.index)  &  val.cell);
    return *this;
}

BoolReference::BoolReference(unsigned char &cell, unsigned char index)
    : cell(cell), index(index)
{}

BoolReference::operator bool() const noexcept
{
    return ((1 << index)  &  cell);
}

unsigned int calculate_real_size(unsigned int size)
{
    return size / CELL_SIZE_BIT + 1;
}

unsigned int calculate_real_index(unsigned int index)
{
    return calculate_real_size(index)-1;
}

void write_bit(unsigned char& changed_char, unsigned int index, bool bit)
{
    if (bit)
    {
        changed_char |= 1 << index;
    }
    else
    {
        changed_char &= ~(1 << index);
    }
}
#endif