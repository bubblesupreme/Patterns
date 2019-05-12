#include "Vector.h"
#include <cassert>

void work_check();

void main()
{
    work_check();
}


void work_check()
{
    Vector<int> vec;
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(1);
    assert(vec [0] == 5);
    assert(vec [1] == 6);
    assert(vec [2] == 1);
    std::cout << vec << std::endl;
    vec.pop_back();
    assert(vec.back() == 6);
    assert(vec.front() == 5);
    assert(vec.size() == 2);
    vec.insert(1, 1);
    assert(vec [1] == 1);
    assert(*vec.insert(1, 2) == 2);
    assert(vec [1] == 2);
    assert(*vec.erase(2) == 6);
    assert(vec [2] == 6);
    std::cout << vec << std::endl;
    assert(vec.size() == 3);
    assert(vec.end() == vec.erase(2));
    try
    {
        assert(vec.at(0) == 5);
        vec.at(10);
    }
    catch (std::out_of_range)
    {
        assert(1);
    }
    Vector<int> vec2(vec);
    std::cout << vec2 << std::endl;
    assert(vec [0] == vec2 [0]);
    assert(vec [1] == vec2 [1]);
    vec2 [1] = 16;
    assert(vec2 [1] == 16);
    vec2 [1] = vec [1];
    assert(vec2 [1] == vec [1]);
    assert(vec.size() == vec2.size());
    assert(vec.capacity() == vec2.capacity());
    vec.push_back(0);
    vec.push_back(1);
    vec2 = std::move(vec);
    assert(vec2.size() == 4);
    assert(vec2.capacity() == DEFAULT_CAPACITY);



    Vector<bool> bool_vec;
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    assert(bool_vec [0] == false);
    assert(bool_vec [1] == true);
    assert(bool_vec [2] == false);
    std::cout << bool_vec << std::endl;
    bool_vec.pop_back();
    assert(bool_vec.back() == true);
    assert(bool_vec.front() == false);
    assert(bool_vec.size() == 2);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    assert(bool_vec.size() == 11);
    std::cout << bool_vec << std::endl;
    bool_vec.insert(1, false);
    std::cout << bool_vec << std::endl;
    assert(bool_vec [1] == false);
    assert(bool_vec.insert(1, true) == true);
    std::cout << bool_vec << std::endl;
    assert(bool_vec [1] == true);
    assert(bool_vec [3] == true);
    std::cout << bool_vec << std::endl;
    assert(bool_vec.erase(2) == true);
    assert(bool_vec [2] == true);
    std::cout << bool_vec << std::endl;
    assert(bool_vec.size() == 12);
    assert(bool_vec.end() == bool_vec.erase(11));
    try
    {
        assert(bool_vec.at(0) == false);
        bool_vec.at(16);
    }
    catch (std::out_of_range)
    {
        assert(1);
    }
    Vector<bool> bool_vec2(bool_vec);
    std::cout << bool_vec2 << std::endl;
    assert(bool_vec [0] == bool_vec2 [0]);
    assert(bool_vec [1] == bool_vec2 [1]);
    std::cout << bool_vec << std::endl;
    bool_vec2 [1] = false;
    assert(bool_vec2 [1] == false);
    bool_vec2 [1] = bool_vec [1] = true;
    assert(bool_vec2 [1] == bool_vec [1]);
    assert(bool_vec.size() == bool_vec2.size());
    assert(bool_vec.capacity() == bool_vec2.capacity());
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec2 = std::move(bool_vec);
    assert(bool_vec2.size() == 13);
    assert(bool_vec2 [12] == true);
    assert(bool_vec2.capacity() == DEFAULT_CAPACITY * 2);

    Vector<bool> bool_vec3(3);
    assert(bool_vec3 [0] == false);
    assert(bool_vec3 [1] == false);
    assert(bool_vec3 [2] == false);
    assert(bool_vec3.size() == 3);

    Vector<bool> bool_vec4(3, true);
    assert(bool_vec4 [0] == true);
    assert(bool_vec4 [1] == true);
    assert(bool_vec4 [2] == true);
    assert(bool_vec4.size() == 3);
    std::cout << "OK";
}